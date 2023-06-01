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
    canDataSendThread();
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    virtual Q_INVOKABLE void slotRecvStatus(bool istrue) override;
    virtual Q_INVOKABLE void slotRecvId(QString) override;
    virtual Q_INVOKABLE void slotSendCanBuf(void *,int length,int canIndex) override;
    virtual Q_INVOKABLE void slotPostWork() override{};
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override{};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override{};
signals :

private:
    bool _isStart;
    QString _id;
//    QQueue<VCI_CAN_OBJ> _queCanBuf;
    bool _isTrue = false ;
    std::mutex _mutex;
    int16_t _canIndex = 0;
};

#endif // CANDATASENDTHREAD_H
