#include "plctimerthread.h"
#include <QThread>

//static int timerCount = 0;

PlcTimerThread::PlcTimerThread(QObject *parent) : QObject(parent)
{

}

PlcTimerThread::~PlcTimerThread()
{

}

void PlcTimerThread::run()
{
//    emit workStart();
//    timer = new QTimer(this);
//    connect(timer,&QTimer::timeout,this,&PlcTimerThread::dowork);
//    timer->start(1000);
    qDebug()<<"run";
    dowork();
}

void PlcTimerThread::dowork()
{
//    timerCount ++;
//    if (timerCount > 100)
//    {
//        emit workFinished();
//    }

    //qDebug()<<QTime::currentTime()<<endl;
    qDebug()<<"显示时间线程ID:"<<QThread::currentThread();  //显示当前线程的数值
    QDateTime time = QDateTime::currentDateTime();
    str_time = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    emit upDateTime(str_time);


}

void PlcTimerThread::printSpinBox(int spin)
{
    spinbox = spin;
    qDebug()<<"changed"<<spin;
    qDebug()<<"线程ID:"<<QThread::currentThread();  //显示当前线程的数值
}


