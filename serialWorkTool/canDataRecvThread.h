#ifndef CANDATARECVTHREAD_H
#define CANDATARECVTHREAD_H

#include "thread/baseThread.h"
#include "methord/qserialwork.h"
#include "public/publicclass.h"
#include "ControlCAN.h"
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
    virtual Q_INVOKABLE void slotRecvStatus(bool) override;
    virtual Q_INVOKABLE void slotPostWork() override{};
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override{};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override{};
signals:
    void signalSendRecvData(VCI_CAN_OBJ *data,  DWORD len,short can);
    void signalSendError(short);
    void signalRecvStatus(bool);
private:
    bool _isStart;
    DWORD m_DevType;
    DWORD m_DevIndex;
    DWORD m_CanIndex;
    DWORD m_nDevType;
    int16_t _index = 0;
};

#endif // CANDATARECVTHREAD_H