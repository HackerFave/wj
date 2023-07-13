#ifndef TESTDATATHREAD_H
#define TESTDATATHREAD_H

#include "thread/baseThread.h"
#include "methord/qserialwork.h"
#include "public/publicclass.h"
class testDataThread : public baseThread
{
public:
    testDataThread(QSerialWork *port);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    virtual Q_INVOKABLE void slotPostWork() override{};
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override{};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override{};
private:
    bool _isStart;
    QSerialWork * _port;
};

#endif // TESTDATATHREAD_H
