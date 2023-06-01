#ifndef BASETHREAD_H
#define BASETHREAD_H

#include <QObject>
#include <QRunnable>
#include <QThreadPool>
#include <QThread>
class baseThread : public QObject
{
    Q_OBJECT
public:
    explicit baseThread(QObject *parent = nullptr);
    virtual Q_INVOKABLE void startWork()=0;
    virtual Q_INVOKABLE void stopWork()=0;
public slots:
    virtual Q_INVOKABLE void slotWork()=0;
    virtual Q_INVOKABLE void slotRecvStatus(bool istrue){};
    virtual Q_INVOKABLE void slotRecvId(QString){};
    virtual Q_INVOKABLE void slotSendCanBuf(void *,int length,int canIndex){};
    virtual Q_INVOKABLE void slotPostWork()=0;
    virtual Q_INVOKABLE void slotPostAppendData(const void *,size_t,int)=0;
    virtual Q_INVOKABLE void slotSubAckAppendData(const void*,int,const uint32_t &)=0;

signals:
    Q_INVOKABLE void signalStartWork();
    Q_INVOKABLE void signalRecvStatus(QString status);
//    Q_INVOKABLE void signalSendCanBuf(void *,int length);
};

#endif // BASETHREAD_H
