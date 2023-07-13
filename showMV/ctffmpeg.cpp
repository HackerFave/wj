//#include "ctffmpeg.h"

//ctffmpeg::ctffmpeg()
//{

//}

#include "ctffmpeg.h"
#include <QImage>
#include "ctaudioplayer.h"
#include <QPixmap>
#include <QDate>
#include <QTime>

ctFFmpeg::ctFFmpeg()
{
}

ctFFmpeg::~ctFFmpeg()
{
}

int ctFFmpeg::Init(QString sUrl, int nProtocolType)
{
    DeInit();

    avformat_network_init();//初始化网络流

    //参数设置
    AVDictionary* pOptDict = NULL;
    if(nProtocolType == PROTOCOL_UDP)
        av_dict_set(&pOptDict, "rtsp_transport", "udp", 0);
    else
        av_dict_set(&pOptDict, "rtsp_transport", "tcp", 0);

    av_dict_set(&pOptDict, "stimeout", "2000000", 0);
    av_dict_set(&pOptDict, "buffer_size", /*"8192000"*/"50", 0);

    if(nullptr == m_pAVFmtCxt)
        m_pAVFmtCxt = avformat_alloc_context();
    if(nullptr == m_pYuvFrame)
        m_pYuvFrame = av_frame_alloc();
    if(nullptr == m_pPcmFrame)
        m_pPcmFrame = av_frame_alloc();

    //加入中断处理
    m_nLastReadPacktTime = av_gettime();
    m_pAVFmtCxt->interrupt_callback.opaque = this;
    m_pAVFmtCxt->interrupt_callback.callback = [](void* ctx)
    {
        ctFFmpeg* pThis = (ctFFmpeg*)ctx;
        int nTimeout = 3;
        if (av_gettime() - pThis->m_nLastReadPacktTime > nTimeout * 1000 * 1000)
        {
            return -1;
        }
        return 0;
    };

    //打开码流
    int nRet = avformat_open_input(&m_pAVFmtCxt, sUrl.toStdString().c_str(), nullptr, nullptr);
    if(nRet < 0)
    {
        MY_DEBUG << "avformat_open_input failed nRet:" << nRet;
        return nRet;
    }

    //设置探测时间，获取码流信息
    m_pAVFmtCxt->probesize = 400 * 1024;
    m_pAVFmtCxt->max_analyze_duration = 2 * AV_TIME_BASE;
    nRet = avformat_find_stream_info(m_pAVFmtCxt, nullptr);
    if(nRet < 0)
    {
        MY_DEBUG << "avformat_find_stream_info failed nRet:" << nRet;
        return nRet;
    }

    //打印码流信息
    av_dump_format(m_pAVFmtCxt, 0, sUrl.toStdString().c_str(), 0);

    //查找码流
    for (int nIndex = 0; nIndex < m_pAVFmtCxt->nb_streams; nIndex++)
    {
        if (m_pAVFmtCxt->streams[nIndex]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            m_nVideoIndex = nIndex;
        }

        if (m_pAVFmtCxt->streams[nIndex]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO)
        {
            m_nAudioIndex = nIndex;
        }
    }

    //初始化视频
    if(InitVideo() < 0)
    {
        MY_DEBUG << "InitVideo() error";
        return -1;
    }

    //初始化音频
    if(m_nAudioIndex != -1)
    {
        if(InitAudio() < 0)
        {
            MY_DEBUG << "InitAudio() error";
            m_bSupportAudioPlay = false;
        }
        else
            m_bSupportAudioPlay = true;
    }

    return 0;
}

void ctFFmpeg::DeInit()
{
    MY_DEBUG << "DeInit 000";
    m_mutex.lock();

    MY_DEBUG << "DeInit 111";
    if (nullptr != m_pVideoSwsContext)
    {
        sws_freeContext(m_pVideoSwsContext);
    }

    MY_DEBUG << "DeInit 222";
    if (nullptr != m_pAudioSwrContext)
    {
        swr_free(&m_pAudioSwrContext);
        m_pAudioSwrContext = nullptr;
    }

    MY_DEBUG << "DeInit 333";
    if(nullptr != m_pYuvFrame)
        av_free(m_pYuvFrame);

    MY_DEBUG << "DeInit 444";
    if(nullptr != m_pPcmFrame)
        av_free(m_pPcmFrame);

    MY_DEBUG << "DeInit 555";
    if(nullptr != m_pOutBuffer)
    {
        av_free(m_pOutBuffer);
    }

    MY_DEBUG << "DeInit 666";
    if(nullptr != m_pVideoCodecCxt)
    {
        avcodec_close(m_pVideoCodecCxt);
        //avcodec_free_context(&m_pVideoCodecCxt);
        m_pVideoCodecCxt = nullptr;
    }

    MY_DEBUG << "DeInit 777";
    if (nullptr != m_pAudioCodecCxt)
    {
       avcodec_close(m_pAudioCodecCxt);
       //avcodec_free_context(&m_pAudioCodecCxt);
       m_pAudioCodecCxt = nullptr;
    }

    MY_DEBUG << "DeInit 888";
    if(nullptr != m_pAVFmtCxt)
    {
        avformat_close_input(&m_pAVFmtCxt);
        MY_DEBUG << "DeInit 999";
        avformat_free_context(m_pAVFmtCxt);
        m_pAVFmtCxt = nullptr;
    }
    MY_DEBUG << "DeInit end";
    m_mutex.unlock();
}

AVPacket ctFFmpeg::getPacket()
{
    AVPacket pkt;
    memset(&pkt, 0, sizeof(AVPacket));

    if(!m_pAVFmtCxt)
    {
        return pkt;
    }
    m_nLastReadPacktTime = av_gettime();
    int nErr = av_read_frame(m_pAVFmtCxt, &pkt);
    if(nErr < 0)
    {
        //错误信息
        char errorbuff[1024];
        av_strerror(nErr, errorbuff, sizeof(errorbuff));
    }
    return pkt;
}

bool ctFFmpeg::Decode(const AVPacket *pkt)
{
    m_mutex.lock();
    if(!m_pAVFmtCxt)
    {
        m_mutex.unlock();
        return false;
    }

    AVCodecContext* pCodecCxt = nullptr;
    AVFrame *pFrame;
    if (pkt->stream_index == m_nAudioIndex)
    {
        pFrame = m_pPcmFrame;
        pCodecCxt = m_pAudioCodecCxt;
    }
    else
    {
        pFrame = m_pYuvFrame;
        pCodecCxt = m_pVideoCodecCxt;
    }

    //发送编码数据包
    int nRet = avcodec_send_packet(pCodecCxt, pkt);
    if (nRet != 0)
    {
        m_mutex.unlock();
        MY_DEBUG << "avcodec_send_packet error---" << nRet;
        return false;
    }

    //获取解码的输出数据
    nRet = avcodec_receive_frame(pCodecCxt, pFrame);
    if (nRet != 0)
    {
        m_mutex.unlock();
        qDebug()<<"avcodec_receive_frame error---" << nRet;
        return false;
    }
    m_mutex.unlock();
    return true;
}

int ctFFmpeg::getVideoFrame()
{
    m_mutex.lock();
    auto nRet = sws_scale(m_pVideoSwsContext, (const uint8_t* const*)m_pYuvFrame->data,
                          m_pYuvFrame->linesize, 0, m_pVideoCodecCxt->height,
                          m_pFrameRGB->data, m_pFrameRGB->linesize);
    if(nRet < 0)
    {
        //MY_DEBUG << "sws_scale error.";
        m_mutex.unlock();
        return -1;
    }

    //发送获取一帧图像信号
    QImage image(m_pFrameRGB->data[0], m_pVideoCodecCxt->width,
            m_pVideoCodecCxt->height, QImage::Format_ARGB32);

    //截图
    if(m_bSnapshot)
    {
        QPixmap pixPicture = QPixmap::fromImage(image);

        QString sPath = "./snapshot/";
        QDate date = QDate::currentDate();
        QTime time = QTime::currentTime();
        m_sSnapPath = QString("%1%2-%3-%4-%5%6%7.jpg").arg(sPath).arg(date.year()). \
                arg(date.month()).arg(date.day()).arg(time.hour()).arg(time.minute()). \
                arg(time.second());
        MY_DEBUG << "Snapshot... m_sSnapPath:" << m_sSnapPath;
        pixPicture.save(m_sSnapPath, "jpg");
        m_bSnapshot = false;
    }

    emit sig_getImage(image);

    m_mutex.unlock();

    return 0;
}

int ctFFmpeg::getAudioFrame(char *pOut)
{
    m_mutex.lock();

    uint8_t  *pData[1];
    pData[0] = (uint8_t *)pOut;

    //获取目标样本数
    auto nDstNbSamples = av_rescale_rnd(m_pPcmFrame->nb_samples,
                                            m_nAudioPlaySampleRate,
                                            m_nAudioSampleRate,
                                            AV_ROUND_ZERO);

    //重采样
    int nLen = swr_convert(m_pAudioSwrContext, pData, nDstNbSamples,
                          (const uint8_t **)m_pPcmFrame->data,
                          m_pPcmFrame->nb_samples);
    if(nLen <= 0)
    {
        MY_DEBUG << "swr_convert error";
        m_mutex.unlock();
        return -1;
    }

    //获取样本保存的缓存大小
    int nOutsize = av_samples_get_buffer_size(nullptr, m_pAudioCodecCxt->channels,
                                             m_pPcmFrame->nb_samples,
                                             AV_SAMPLE_FMT_S16,
                                             0);
    m_mutex.unlock();

    return nOutsize;
}

void ctFFmpeg::Snapshot()
{
    m_bSnapshot = true;
}

int ctFFmpeg::InitVideo()
{
    if(m_nVideoIndex == -1)
    {
        MY_DEBUG << "m_nVideoIndex == -1 error";
        return -1;
    }

    //查找视频解码器
    const AVCodec *pAVCodec = avcodec_find_decoder(m_pAVFmtCxt->streams[m_nVideoIndex]->codecpar->codec_id);
    if(!pAVCodec)
    {
        MY_DEBUG << "video decoder not found";
        return -1;
    }

    //视频解码器参数配置
    m_CodecId = pAVCodec->id;
    if(!m_pVideoCodecCxt)
        m_pVideoCodecCxt = avcodec_alloc_context3(nullptr);
    if(nullptr == m_pVideoCodecCxt)
    {
        MY_DEBUG << "avcodec_alloc_context3 error m_pVideoCodecCxt=nullptr";
        return -1;
    }
    avcodec_parameters_to_context(m_pVideoCodecCxt, m_pAVFmtCxt->streams[m_nVideoIndex]->codecpar);
    if(m_pVideoCodecCxt)
    {
        if (m_pVideoCodecCxt->width == 0 || m_pVideoCodecCxt->height == 0)
        {
            MY_DEBUG << "m_pVideoCodecCxt->width=0 or m_pVideoCodecCxt->height=0 error";
            return -1;
        }
    }

    //打开视频解码器
    int nRet = avcodec_open2(m_pVideoCodecCxt, pAVCodec, nullptr);
    if(nRet < 0)
    {
        MY_DEBUG << "avcodec_open2 video error";
        return -1;
    }

    //申请并分配内存,初始化转换上下文,用于YUV转RGB
    m_pOutBuffer = (uint8_t*)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_BGRA,
                                                 m_pVideoCodecCxt->width, m_pVideoCodecCxt->height, 1));
    if(nullptr == m_pOutBuffer)
    {
        MY_DEBUG << "nullptr == m_pOutBuffer error";
        return -1;
    }

    if(nullptr == m_pFrameRGB)
        m_pFrameRGB = av_frame_alloc();
    if(nullptr == m_pFrameRGB)
    {
        MY_DEBUG << "nullptr == m_pFrameRGB error";
        return -1;
    }
    av_image_fill_arrays(m_pFrameRGB->data, m_pFrameRGB->linesize, m_pOutBuffer,
                                    AV_PIX_FMT_BGRA, m_pVideoCodecCxt->width, m_pVideoCodecCxt->height, 1);

    m_pVideoSwsContext = sws_getContext(m_pVideoCodecCxt->width, m_pVideoCodecCxt->height,
                                   m_pVideoCodecCxt->pix_fmt, m_pVideoCodecCxt->width, m_pVideoCodecCxt->height,
                                   AV_PIX_FMT_BGRA, SWS_FAST_BILINEAR, NULL, NULL, NULL);
    if(nullptr == m_pVideoSwsContext)
    {
        MY_DEBUG << "nullptr == m_pVideoSwsContex error";
        return -1;
    }
    return 0;
}

int ctFFmpeg::InitAudio()
{
    if(m_nAudioIndex == -1)
    {
        MY_DEBUG << "m_nAudioIndex == -1";
        return -1;
    }

    //查找音频解码器
    const AVCodec *pAVCodec = avcodec_find_decoder(m_pAVFmtCxt->streams[m_nAudioIndex]->codecpar->codec_id);
    if(!pAVCodec)
    {
        MY_DEBUG << "audio decoder not found";
        return -1;
    }

    //音频解码器参数配置
    if (!m_pAudioCodecCxt)
        m_pAudioCodecCxt = avcodec_alloc_context3(nullptr);
    if(nullptr == m_pAudioCodecCxt)
    {
        MY_DEBUG << "avcodec_alloc_context3 error m_pAudioCodecCxt=nullptr";
        return -1;
    }
    avcodec_parameters_to_context(m_pAudioCodecCxt, m_pAVFmtCxt->streams[m_nAudioIndex]->codecpar);

    //打开音频解码器
    int nRet = avcodec_open2(m_pAudioCodecCxt, pAVCodec, nullptr);
    if(nRet < 0)
    {
        avcodec_close(m_pAudioCodecCxt);
        MY_DEBUG << "avcodec_open2 error m_pAudioCodecCxt";
        return -1;
    }

    //音频重采样初始化
    if (nullptr == m_pAudioSwrContext)
    {
        if(m_pAudioCodecCxt->channel_layout <= 0 || m_pAudioCodecCxt->channel_layout > 3)
            m_pAudioCodecCxt->channel_layout = 1;

        qDebug() << "m_audioCodecContext->channel_layout:" << m_pAudioCodecCxt->channel_layout;
        qDebug() << "m_audioCodecContext->channels:" << m_pAudioCodecCxt->channels;

        m_pAudioSwrContext = swr_alloc_set_opts(0,
                                               m_pAudioCodecCxt->channel_layout,
                                               AV_SAMPLE_FMT_S16,
                                               m_pAudioCodecCxt->sample_rate,
                                               av_get_default_channel_layout(m_pAudioCodecCxt->channels),
                                               m_pAudioCodecCxt->sample_fmt,
                                               m_pAudioCodecCxt->sample_rate,
                                               0,
                                               0);
        auto nRet = swr_init(m_pAudioSwrContext);
        if(nRet < 0)
        {
            MY_DEBUG << "swr_init error";
            return -1;
        }
    }

    //音频播放设备初始化
    int nSampleSize = 16;
    switch (m_pAudioCodecCxt->sample_fmt)//样本大小
    {
        case AV_SAMPLE_FMT_S16:
            nSampleSize = 16;
            break;
        case  AV_SAMPLE_FMT_S32:
            nSampleSize = 32;
        default:
            break;
    }

    m_nAudioSampleRate = m_pAudioCodecCxt->sample_rate;
    ctAudioPlayer::getInstance().m_nSampleRate = m_nAudioSampleRate;//采样率
    ctAudioPlayer::getInstance().m_nChannelCount = m_pAudioCodecCxt->channels;//通道数
    ctAudioPlayer::getInstance().m_nSampleSize = nSampleSize;//样本大小
    if(!ctAudioPlayer::getInstance().Init())
        return -1;

    return 0;
}

