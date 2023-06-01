#include "serialWorkThreadPool.h"
#include <QCoreApplication>
#include <QDataStream>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QtDebug>
#define MT 0


serialWorkThreadPool_send::serialWorkThreadPool_send(QSerialPort *port):
    P_QSerialPort(port)
{

}
Q_INVOKABLE void serialWorkThreadPool_send::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_send::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_send::slotWork()
{

}
void serialWorkThreadPool_send::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_send::run()
{
    while (_isStart) {

        _sleep(1000);
    }
}


serialWorkThreadPool_recv::serialWorkThreadPool_recv(QSerialPort *port):
    P_QSerialPort(port)
{


}
Q_INVOKABLE void serialWorkThreadPool_recv::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_recv::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_recv::slotWork()
{

}
void serialWorkThreadPool_recv::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_recv::run()
{

}
void serialWorkThreadPool_recv::DataArrived()
{

}
