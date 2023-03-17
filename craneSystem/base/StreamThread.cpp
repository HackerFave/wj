#include "StreamThread.h"
#include <QThread>
#include <QDebug>

#define USEOPENGL  true

FfmpegRegister::FfmpegRegister()
{
//    av_register_all();          //注册全部功能
    avformat_network_init();    //初始化FFmpeg网络模块
}

FfmpegRegister::~FfmpegRegister()
{
    avformat_network_deinit();
}

FfmpegRegister StreamThread::s_ffmpeg;
QMutex         StreamThread::s_mutex;

StreamThread::StreamThread(QObject *parent) : QObject(parent),
            m_pPacket(NULL,free),
            m_pImgConvertCtx(NULL,sws_freeContext),
            m_pOutBuffer(NULL,av_free),
            m_pFrame(NULL),
            m_pFrameIMG(NULL),
            m_pFormatCtx(NULL),
            m_pCodecCtx(NULL),
            m_outSize(0,0)
{
    m_url.clear();
}

StreamThread::~StreamThread()
{
    QMutexLocker lk(&s_mutex);
    if(m_pFrame != NULL){
        av_frame_free(&m_pFrame);
    }
    if(m_pFrameIMG != NULL){
        av_frame_free(&m_pFrameIMG);
    }
    if(m_pCodecCtx != NULL){
        avcodec_free_context(&m_pCodecCtx);
    }
    if(m_pFormatCtx != NULL){
        avformat_free_context(m_pFormatCtx);
    }
}

void StreamThread::startThread()
{
    QThread* thread = new QThread();
    connect(this, SIGNAL(sglFinished()), thread, SLOT(quit()));
    connect(this, SIGNAL(sglFinished()), this, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    connect(thread, SIGNAL(started()), this, SLOT(doWork()));
    this->moveToThread(thread);
    thread->start();
}

void StreamThread::setParameter(QString &url,QMetaObject::Connection &connection,int w,int h)
{
    m_url = url;
    m_outSize.setWidth(w);
    m_outSize.setHeight(h);
    m_connection = connection;
}

// 打开流媒体
bool StreamThread::openStream()
{
    if(m_url.isEmpty()){
        qWarning("Missing parameter. \n");
        return false;
    }

    int ret = 0;
    //添加命令参数
    AVDictionary *options = NULL;
    av_dict_set(&options, "stimeout", "2000000", 0);
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    av_dict_set(&options, "max_delay", "50", 0);
    m_pFormatCtx = avformat_alloc_context();
    ret = avformat_open_input(&m_pFormatCtx, m_url.toUtf8().data(), NULL, &options);
    av_dict_free(&options);

    if (ret != 0) {
        qWarning() << "can't open the url :" << m_url;
        return false;
    }
    QMutexLocker lk(&s_mutex);
    if (avformat_find_stream_info(m_pFormatCtx, NULL) < 0) {
        qWarning("Could't find stream infomation.\n");
        return false;
    }

    fprintf(stderr,"--------------- File Information ----------------\n");
    //打印输入或输出的详细信息
    av_dump_format(m_pFormatCtx, 0, m_url.toUtf8().data(), 0);
    fprintf(stderr,"-------------------------------------------------\n");

    m_videoIndex = -1;

    //循环查找视频中包含的流信息，仅找视频类型的流
    for (uint i = 0; i < m_pFormatCtx->nb_streams; i++) {
        if (m_pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            m_videoIndex = i;
        }
    }
    if (m_videoIndex == -1) {
        qWarning("Didn't find a video stream.\n");
        return false;
    }

    //查找解码器
    m_pCodec = avcodec_find_decoder(m_pFormatCtx->streams[m_videoIndex]->codecpar->codec_id);
    m_pCodecCtx = avcodec_alloc_context3(m_pCodec);
    if (m_pCodec == NULL || m_pCodecCtx == NULL) {
        qWarning("Codec not found.\n");
        return false;
    }
    if(avcodec_parameters_to_context(m_pCodecCtx, m_pFormatCtx->streams[m_videoIndex]->codecpar) < 0){
        qWarning("Error initializing the decoder context.\n");
    }

//    m_pCodecCtx->bit_rate =0;   //初始化为0
//    m_pCodecCtx->time_base.num=1;  //一秒钟25帧
//    m_pCodecCtx->time_base.den=25;
//    m_pCodecCtx->frame_number=1;  //每包一个视频帧

    //打开解码器
    ret = avcodec_open2(m_pCodecCtx, m_pCodec, NULL);
    lk.unlock();
    if (ret < 0) {
        qWarning("Could not open codec.\n");
        return false;
    }
    if(m_pCodecCtx->width < 50 || m_pCodecCtx->height < 50){
        qWarning() << "error video width :" << m_pCodecCtx->width << "video height :" << m_pCodecCtx->height;
        return false;
    }

    m_pFrame = av_frame_alloc();
    m_pFrameIMG = av_frame_alloc();

#if USEOPENGL
    int size = av_image_get_buffer_size(AV_PIX_FMT_YUVJ420P, m_pCodecCtx->width,m_pCodecCtx->height,1);
#else
    int size = av_image_get_buffer_size(AV_PIX_FMT_RGB32, m_pCodecCtx->width,m_pCodecCtx->height,1);
#endif

    m_pOutBuffer = std::unique_ptr<uint8_t,void(*)(void*)>{
        static_cast<uint8_t*>(av_malloc(size)),av_free
    };

#if USEOPENGL
    av_image_fill_arrays(m_pFrameIMG->data, m_pFrameIMG->linesize, m_pOutBuffer.get(),
            AV_PIX_FMT_YUVJ420P, m_pCodecCtx->width, m_pCodecCtx->height, 1);
#else
    av_image_fill_arrays(m_pFrameIMG->data, m_pFrameIMG->linesize, m_pOutBuffer.get(),
            AV_PIX_FMT_RGB32, m_pCodecCtx->width, m_pCodecCtx->height, 1);
#endif

    m_pPacket = std::unique_ptr<AVPacket,void(*)(void*)>{
        static_cast<AVPacket*>(malloc(sizeof(AVPacket))),free
    };
    memset(m_pPacket.get(),0,sizeof(AVPacket));
    av_init_packet(m_pPacket.get());

#if USEOPENGL
    m_pImgConvertCtx = std::unique_ptr<SwsContext,void(*)(SwsContext*)>{
        sws_getContext(m_pCodecCtx->width, m_pCodecCtx->height,
                    m_pCodecCtx->pix_fmt, m_pCodecCtx->width, m_pCodecCtx->height,
                    AV_PIX_FMT_YUVJ420P, SWS_BICUBIC, NULL, NULL, NULL),
                sws_freeContext
    };
#else
    m_pImgConvertCtx = std::unique_ptr<SwsContext,void(*)(SwsContext*)>{
        sws_getContext(m_pCodecCtx->width, m_pCodecCtx->height,
                    m_pCodecCtx->pix_fmt, m_pCodecCtx->width, m_pCodecCtx->height,
                    AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL),
                sws_freeContext
    };
#endif

    return true;
}

void StreamThread::outputResize(int w,int h)
{
    m_outSize.setWidth(w);
    m_outSize.setHeight(h);
    if(m_outSize.isNull()){
        this->disconnect(m_connection);
    }
}

void StreamThread::doWork()
{
    if(openStream()) {

        int ret = -1;

        // 读取帧
        while (av_read_frame(m_pFormatCtx, m_pPacket.get()) >= 0) {

            if (m_pPacket->stream_index == m_videoIndex) {
                // 发送包解码
                ret = avcodec_send_packet(m_pCodecCtx,m_pPacket.get());
                av_packet_unref(m_pPacket.get());
                if (ret != 0) {
                    continue;
                }
                // 接受解码帧
                ret = avcodec_receive_frame(m_pCodecCtx,m_pFrame);
                if (ret != 0) {
                    qWarning("decode error.\n");
                    break;
                }

                if(!m_outSize.isNull()) {
                    sws_scale(m_pImgConvertCtx.get(),
                              (const uint8_t* const*)m_pFrame->data, m_pFrame->linesize,
                              0, m_pCodecCtx->height,
                              m_pFrameIMG->data, m_pFrameIMG->linesize);
                //返回解码图像
                #if USEOPENGL
                    emit sglSyncUpdateYUV(m_pFrameIMG->data[0],m_pFrameIMG->data[1],m_pFrameIMG->data[2],
                                           m_pCodecCtx->width, m_pCodecCtx->height);
                    emit sglAsyncUpdateUi();

                #else
                    QImage tmpImg(static_cast<uchar*>(m_pOutBuffer.get()),m_pCodecCtx->width,m_pCodecCtx->height,QImage::Format_RGB32);
                    emit sglAsyncUpdateUi(QPixmap::fromImage(tmpImg.scaled(m_outSize,Qt::KeepAspectRatio)));  //发送信号
                #endif

                }else{
                    break;
                }
            }
        }
        QMutexLocker lk(&s_mutex);
        avcodec_close(m_pCodecCtx);
        avformat_close_input(&m_pFormatCtx);
    }
    emit sglFinished();
}
