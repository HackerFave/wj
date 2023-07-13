//#include "ctaudioplayer.h"

//ctaudioplayer::ctaudioplayer()
//{

//}


#include "ctaudioplayer.h"

ctAudioPlayer::ctAudioPlayer()
{

}

ctAudioPlayer::~ctAudioPlayer()
{

}

ctAudioPlayer &ctAudioPlayer::getInstance()
{
    static ctAudioPlayer s_obj;
    return s_obj;
}

bool ctAudioPlayer::Init()
{
    DeInit();

    m_mutex.lock();

    MY_DEBUG << "m_nSampleRate:" << m_nSampleRate;
    MY_DEBUG << "m_nSampleSize:" << m_nSampleSize;
    MY_DEBUG << "m_nChannelCount:" << m_nChannelCount;

    m_audio_device = QAudioDeviceInfo::defaultOutputDevice();
    MY_DEBUG << "m_audio_device.deviceName():" << m_audio_device.deviceName();
    if(m_audio_device.deviceName().isEmpty())
    {
        return false;
    }

    QAudioFormat format;
    format.setSampleRate(m_nSampleRate);
    format.setSampleSize(m_nSampleSize);
    format.setChannelCount(m_nChannelCount);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    if(!m_audio_device.isFormatSupported(format))
    {
        MY_DEBUG << "QAudioDeviceInfo format No Supported.";
        //format = m_audio_device.nearestFormat(format);
        m_mutex.unlock();
        return false;
    }

    if(m_pAudioOut)
    {
        m_pAudioOut->stop();
        delete m_pAudioOut;
        m_pAudioOut = nullptr;
        m_pIODevice = nullptr;
    }
    m_pAudioOut = new QAudioOutput(format);
    m_pIODevice = m_pAudioOut->start();

    m_mutex.unlock();
    return true;
}

void ctAudioPlayer::DeInit()
{
    m_mutex.lock();

    if(m_pAudioOut)
    {
        m_pAudioOut->stop();
        delete m_pAudioOut;
        m_pAudioOut = nullptr;
        m_pIODevice = nullptr;
    }

    m_mutex.unlock();
}

void ctAudioPlayer::isPlay(bool bPlay)
{
    m_mutex.lock();

    if(!m_pAudioOut)
    {
        m_mutex.unlock();
        return;
    }

    if(bPlay)
        m_pAudioOut->resume();//恢复播放
    else
        m_pAudioOut->suspend();//暂停播放

    m_mutex.unlock();
}

void ctAudioPlayer::Write(const char *pData, int nDatasize)
{
    m_mutex.lock();

    if(m_pIODevice)
        m_pIODevice->write(pData, nDatasize);//将获取的音频写入到缓冲区中

    m_mutex.unlock();
}

int ctAudioPlayer::getFreeSize()
{
    m_mutex.lock();

    if(!m_pAudioOut)
    {
        m_mutex.unlock();
        return 0;
    }
    int nFreeSize = m_pAudioOut->bytesFree();//剩余空间

    m_mutex.unlock();

    return nFreeSize;
}

