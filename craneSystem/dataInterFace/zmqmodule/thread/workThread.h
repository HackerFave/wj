#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include "baseThread.h"
#include <QMap>
#include <QTimer>
#include <QVariantList>
class workThread : public baseThread
{
public:
    workThread();
    Q_INVOKABLE void startWork() override;
    Q_INVOKABLE void stopWork() override;
    Q_INVOKABLE void run(){};
public slots:
    Q_INVOKABLE void slotPostWork() override;
    Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override;
    Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override;//ack包，是否收取到信息
private slots:
private:
    bool _isStop = false;
    int _id;
    QMap<int, QVariantList> _dataMap;
};

#endif // WORKTHREAD_H
