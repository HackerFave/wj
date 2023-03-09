#ifndef SQLTRUNCATETHREAD_H
#define SQLTRUNCATETHREAD_H
#include <QMap>
#include <QTimer>
#include "baseThread.h"
#include "../../../sql/SqlMethod.h"
class sqlTruncateThread : public baseThread
{
public:
    sqlTruncateThread();
    Q_INVOKABLE void startWork() override;
    Q_INVOKABLE void stopWork() override;
    Q_INVOKABLE void run(){};
public slots:
    virtual Q_INVOKABLE void slotWork() override ;
    Q_INVOKABLE void slotPostWork() override;
    Q_INVOKABLE void slotPostAppendData(const void *,size_t,int) override;
    Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &) override;//ack包，是否收取到信息
private slots:

private:
    bool _isStop = false;
    int _id;
};
#endif // SQLTRUNCATETHREAD_H
