#ifndef SERIALWORKTHREADPOOL_H
#define SERIALWORKTHREADPOOL_H

#include "basethreadpool.h"
#include <QtSerialPort/QSerialPort>


class serialWorkThreadPool_send : public baseThreadPool
{
public:
    serialWorkThreadPool_send(QSerialPort *port);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};

public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialPort *P_QSerialPort;
    bool _isStart = false;

};

class serialWorkThreadPool_recv : public baseThreadPool
{
public:
    serialWorkThreadPool_recv(QSerialPort *port);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
    void DataArrived();
private:
    QSerialPort *P_QSerialPort;
    bool _isStart = false;
};
#endif // SERIALWORKTHREADPOOL_H
