//#include "mediathread.h"

//mediathread::mediathread()
//{

//}
#include "mediathread.h"
#include "ctaudioplayer.h"
#include <QDate>
#include <QTime>

MediaThread::MediaThread()
{
}

MediaThread::~MediaThread()
{
    if(m_pFFmpeg)
    {
        m_pFFmpeg->DeInit();
        delete m_pFFmpeg;
        m_pFFmpeg = nullptr;
    }
}

bool MediaThread::Init(QString sUrl, int nProtocolType)
{
    if(nullptr == m_pFFmpeg)
    {
        MY_DEBUG << "new ctFFmpeg";
        m_pFFmpeg = new ctFFmpeg;
        connect(m_pFFmpeg, SIGNAL(sig_getImage(const QImage&)),
                this, SIGNAL(sig_emitImage(const QImage&)));
    }

    if(m_pFFmpeg->Init(sUrl, nProtocolType) != 0)
    {
        MY_DEBUG << "FFmpeg Init error.";
        return false;
    }
    return true;
}

void MediaThread::DeInit()
{
    MY_DEBUG << "DeInit 000";
    m_pFFmpeg->DeInit();

    MY_DEBUG << "DeInit 111";
    if(m_pFFmpeg)
    {
        delete m_pFFmpeg;
        m_pFFmpeg = nullptr;
    }
    MY_DEBUG << "DeInit end";
}

void MediaThread::startThread()
{
    m_bRun = true;
    start();
}

void MediaThread::stopThread()
{
    m_bRun = false;
}

void MediaThread::setPause(bool bPause)
{
    m_bPause = bPause;
}

void MediaThread::Snapshot()
{
    m_pFFmpeg->Snapshot();
}

void MediaThread::startRecord()
{
    QString sPath = "./record/";
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString sRecordPath = QString("%1%2-%3-%4-%5%6%7.mp4").arg(sPath).arg(date.year()). \
            arg(date.month()).arg(date.day()).arg(time.hour()).arg(time.minute()). \
            arg(time.second());

    MY_DEBUG << "sRecordPath:" << sRecordPath;

    if(nullptr != m_pFFmpeg->m_pAVFmtCxt && m_bRun)
    {
//        m_bRecord = m_pMp4Recorder.Init(m_pFFmpeg->m_pAVFmtCxt, sRecordPath);
    }
}

void MediaThread::stopRecord()
{
    if(m_bRecord)
    {
        MY_DEBUG << "stopRecord...";
//        m_pMp4Recorder.DeInit();
        m_bRecord = false;
    }
}

void MediaThread::run()
{
    char audioOut[MAX_AUDIO_OUT_SIZE] = {0};
    while(m_bRun)
    {
        if(m_bPause)
        {
            msleep(100);
            continue;
        }

        //获取播放器缓存大小
        if(m_pFFmpeg->m_bSupportAudioPlay)
        {
            int nFreeSize = ctAudioPlayer::getInstance().getFreeSize();
            if(nFreeSize < m_nMinAudioPlayerSize)
            {
                msleep(1);
                continue;
            }
        }

        AVPacket pkt = m_pFFmpeg->getPacket();
        if (pkt.size <= 0)
        {
            msleep(10);
            continue;
        }

        //解码播放
        if (pkt.stream_index == m_pFFmpeg->m_nAudioIndex &&
                m_pFFmpeg->m_bSupportAudioPlay)
        {
            if(m_pFFmpeg->Decode(&pkt))
            {
               int nLen = m_pFFmpeg->getAudioFrame(audioOut);//获取一帧音频的pcm
               if(nLen > 0)
                    ctAudioPlayer::getInstance().Write(audioOut, nLen);
            }
        }
        else
        {
            //目前只支持录制视频
            if(m_bRecord)
            {
                //MY_DEBUG << "record...";
                AVPacket* pPkt = av_packet_clone(&pkt);
//                m_pMp4Recorder.saveOneFrame(*pPkt);
                av_packet_free(&pPkt);
            }

            if(m_pFFmpeg->Decode(&pkt))
            {
                m_pFFmpeg->getVideoFrame();
            }
        }
        av_packet_unref(&pkt);
    }
    MY_DEBUG << "run end";
}

