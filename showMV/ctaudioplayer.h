//#ifndef CTAUDIOPLAYER_H
//#define CTAUDIOPLAYER_H


//class ctaudioplayer
//{
//public:
//    ctaudioplayer();
//};

//#endif // CTAUDIOPLAYER_H

#ifndef CTAUDIOPLAYER_H
#define CTAUDIOPLAYER_H

#include <QObject>
#include <QAudioDeviceInfo>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QMutex>
#include "commondef.h"

class ctAudioPlayer
{
public:
    ctAudioPlayer();
    ~ctAudioPlayer();

    static ctAudioPlayer& getInstance();
    bool Init();
    void DeInit();
    void isPlay(bool bPlay);
    void Write(const char *pData, int nDatasize);
    int getFreeSize();

public:
    int m_nSampleRate = 8000;//采样率
    int m_nSampleSize = 16;//采样大小
    int m_nChannelCount = 1;//通道数
private:
    QAudioDeviceInfo m_audio_device;
    QAudioOutput* m_pAudioOut = nullptr;
    QIODevice* m_pIODevice = nullptr;
    QMutex m_mutex;
};

#endif // CTAUDIOPLAYER_H

