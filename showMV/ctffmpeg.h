//#ifndef CTFFMPEG_H
//#define CTFFMPEG_H


//class ctffmpeg : public ctffmpeg
//{
//public:
//    ctffmpeg();
//};

//#endif // CTFFMPEG_H


#ifndef CTFFMPEG_H
#define CTFFMPEG_H

#include <QObject>
#include <QMutex>

extern "C"
{
    #include "libavcodec/avcodec.h"
    #include "libavcodec/dxva2.h"
    #include "libavutil/avstring.h"
    #include "libavutil/mathematics.h"
    #include "libavutil/pixdesc.h"
    #include "libavutil/imgutils.h"
    #include "libavutil/dict.h"
    #include "libavutil/parseutils.h"
    #include "libavutil/samplefmt.h"
    #include "libavutil/avassert.h"
    #include "libavutil/time.h"
    #include "libavformat/avformat.h"
    #include "libswscale/swscale.h"
    #include "libavutil/opt.h"
    #include "libavcodec/avfft.h"
    #include "libswresample/swresample.h"
    #include "libavfilter/buffersink.h"
    #include "libavfilter/buffersrc.h"
    #include "libavutil/avutil.h"
}
#include "commondef.h"

class ctFFmpeg : public QObject
{
    Q_OBJECT
public:
    ctFFmpeg();
    ~ctFFmpeg();

    int Init(QString sUrl, int nProtocolType = PROTOCOL_UDP);
    void DeInit();

    AVPacket getPacket(); //读取一帧
    bool Decode(const AVPacket *pkt); //解码

    int getVideoFrame();
    int getAudioFrame(char* pOut);

    void Snapshot();

private:
    int InitVideo();
    int InitAudio();

signals:
    void sig_getImage(const QImage &image);

public:
    int m_nVideoIndex = -1;
    int m_nAudioIndex = -1;
    bool m_bSupportAudioPlay = false;
    AVFormatContext *m_pAVFmtCxt = nullptr;              //流媒体的上下文

private:
    AVCodecContext* m_pVideoCodecCxt = nullptr;          //视频解码器上下文
    AVCodecContext* m_pAudioCodecCxt = nullptr;          //音频解码器上下文
    AVFrame *m_pYuvFrame = nullptr;                      //解码后的视频帧数据
    AVFrame *m_pPcmFrame = nullptr;                      //解码后的音频数据
    SwrContext *m_pAudioSwrContext = nullptr;            //音频重采样上下文
    SwsContext *m_pVideoSwsContext = nullptr;            //处理像素问题,格式转换 yuv->rbg
    AVPacket m_packet;                                   //每一帧数据 原始数据
    AVFrame* m_pFrameRGB = nullptr;                      //转换后的RGB数据
    enum AVCodecID m_CodecId;
    uint8_t* m_pOutBuffer = nullptr;

    int m_nAudioSampleRate = 8000;                       //音频采样率
    int m_nAudioPlaySampleRate = 44100;                  //音频播放采样率
    int m_nAudioPlayChannelNum = 1;                      //音频播放通道数
    int64_t m_nLastReadPacktTime = 0;
    bool m_bSnapshot = false;
    QString m_sSnapPath = "./snapshot/test.jpg";
    QMutex m_mutex;
};

#endif // CTFFMPEG_H
