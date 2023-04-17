#ifndef CANDATASENDTHREAD_H
#define CANDATASENDTHREAD_H
#include "thread/baseThread.h"
#include "ControlCAN.h"
#include "public/publicclass.h"
#include <QQueue>
#include <QDebug>
class canDataSendThread : public baseThread
{
    Q_OBJECT
public:
    canDataSendThread(const DWORD&,const DWORD&,const DWORD&);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    virtual Q_INVOKABLE void slotRecvStatus(QString status) override;
    virtual Q_INVOKABLE void slotRecvId(QString) override;
    virtual Q_INVOKABLE void slotSendCanBuf(void *,int length) override;
    virtual Q_INVOKABLE void slotPostWork() override{};
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override{};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override{};
signals :

private:
    bool _isStart;
    DWORD m_DevType;
    DWORD m_DevIndex;
    DWORD m_CanIndex;
    DWORD m_nDevType;
    QQueue<VCI_CAN_OBJ> _queCanBuf;
    QString _id ;
    std::mutex _mutex;
};

#endif // CANDATASENDTHREAD_H
