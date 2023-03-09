#ifndef SUBTHREADPOOL_H
#define SUBTHREADPOOL_H

#include "baseThread.h"
class subThreadPool : public baseThread
{
public:
    subThreadPool();
    void run();
    virtual Q_INVOKABLE void startWork(){};
    virtual Q_INVOKABLE void stopWork(){};
public slots:
    virtual Q_INVOKABLE void slotWork() override {};
    virtual Q_INVOKABLE void slotPostWork(){};
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int){};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &){};
};

#endif // SUBTHREADPOOL_H
