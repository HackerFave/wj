#ifndef CANDATARECVTHREAD_H
#define CANDATARECVTHREAD_H

#include "baseThread.h"
#include "publicclass.h"
#include "define.h"
class canDataRecvThread : public baseThread
{
    Q_OBJECT
public:
    canDataRecvThread(const DWORD&,const DWORD&,const DWORD&);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    //    void setParameters(const DWORD&,const DWORD&,const DWORD&);
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    virtual Q_INVOKABLE void slotRecvStatus(QString status) override;
    virtual Q_INVOKABLE void slotPostWork() override{};
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override{};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override{};
signals:
    void signalSendRecvData(void *data,  DWORD len,short can);
    void signalSendError(short);
    void signalRecvStatus(bool);
    void signalReset();
private:
    bool _isStart;
    DWORD m_DevType = 4;
    DWORD m_DevIndex =0;
    DWORD m_CanIndex =1;
    DWORD m_nDevType;
    int16_t _index = 0;
    int _numStart =0;
    int _numEnd =0;
};

#endif // CANDATARECVTHREAD_H
