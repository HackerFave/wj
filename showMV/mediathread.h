//#ifndef MEDIATHREAD_H
//#define MEDIATHREAD_H


//class mediathread
//{
//public:
//    mediathread();
//};

//#endif // MEDIATHREAD_H

#ifndef MEDIATHREAD_H
#define MEDIATHREAD_H

#include <QThread>
#include <QImage>
#include "ctffmpeg.h"
#include "commondef.h"
//#include "mp4recorder.h"

#define MAX_AUDIO_OUT_SIZE 8*1152


class MediaThread : public QThread
{
    Q_OBJECT
public:
    MediaThread();
    ~MediaThread();

    bool Init(QString sUrl, int nProtocolType = PROTOCOL_UDP);
    void DeInit();

    void startThread();
    void stopThread();

    void setPause(bool bPause);

    void Snapshot();
    void startRecord();
    void stopRecord();

public:
    int m_nMinAudioPlayerSize = 640;

private:
    void run() override;

signals:
    void sig_emitImage(const QImage&);

private:
    bool m_bRun = false;
    bool m_bPause = false;
    bool m_bRecord = false;
    ctFFmpeg* m_pFFmpeg = nullptr;
//    mp4Recorder m_pMp4Recorder;

};

#endif // MEDIATHREAD_H

