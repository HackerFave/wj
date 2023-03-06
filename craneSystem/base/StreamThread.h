#ifndef STREAMTHREAD_H
#define STREAMTHREAD_H

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/pixfmt.h>
#include <libavutil/imgutils.h>
#include <libswscale/swscale.h>
//#include <libsync.h>
#include "libavutil/avutil.h"
#include "libswresample/swresample.h"
#include "libavutil/frame.h"
#include "libavutil/samplefmt.h"
}

#include <QObject>
#include <QMutex>
#include <QPixmap>
#include <memory>

class FfmpegRegister
{
public:
    explicit FfmpegRegister();
    ~FfmpegRegister();
};

class StreamThread : public QObject
{
    Q_OBJECT
public:
    explicit StreamThread(QObject *parent = nullptr);
    ~StreamThread();

    bool openStream();
    void setParameter(QString &url,QMetaObject::Connection &connection,int w = 0,int h = 0);
    void startThread();  //执行后线程结束会自动释放内存

signals:
    void sglFinished();
    void sglAsyncUpdateUi(QPixmap img);
    void sglAsyncUpdateUi();
    void sglSyncUpdateYUV(const uchar *Yplane,
                          const uchar *Uplane,
                          const uchar *Vplane,
                          uint width,uint height);

public slots:
    void doWork();
    void outputResize(int w,int h);

private:

    std::unique_ptr<AVPacket,void(*)(void*)>            m_pPacket;
    AVPacket                                           *m_audio_Packet;
    std::unique_ptr<SwsContext,void(*)(SwsContext*)>    m_pImgConvertCtx;
    std::unique_ptr<uint8_t,void(*)(void*)>             m_pOutBuffer;

    AVFrame                 *m_pFrame;
    AVFrame                 *m_pFrameIMG;
    AVFormatContext         *m_pFormatCtx;
    AVCodecContext          *m_pCodecCtx;
    const AVCodec                 *m_pCodec;

    AVCodecContext          *m_audio_pCodecCtx;//音频
    AVCodec                 *m_audio_pCodec;//音频
    AVFrame                 *m_frame_audio;
    int                     m_videoIndex;//视频
    int                     m_audioStreamIdx  = -1;//音频
    SwrContext              *m_swrContext ;//音频
    //缓存区
    uint8_t                 *m_out_buffer ;//音频

    QString                 m_url;
    QSize                   m_outSize;
    QMetaObject::Connection m_connection;

    static QMutex           s_mutex;
    static FfmpegRegister   s_ffmpeg;
};

#endif // STREAMTHREAD_H
