#ifndef IPC_THREAD_H
#define IPC_THREAD_H
#include "baseThread.h"
#include <QProcess>

class IPC_Thread : public baseThread
{
public:
    IPC_Thread();
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    Q_INVOKABLE void run(){}
public slots:
    virtual Q_INVOKABLE void slotWork() override {};
    virtual Q_INVOKABLE void slotPostWork() override;
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int){};
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &){};
private:
     bool _isStop = false;
//     QProcess _process ;
};

#endif // IPC_THREAD_H
