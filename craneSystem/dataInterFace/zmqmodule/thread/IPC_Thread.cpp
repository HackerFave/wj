#include "IPC_Thread.h"
#include <QDebug>

IPC_Thread::IPC_Thread()
{

}
Q_INVOKABLE void IPC_Thread::startWork()
{
    _isStop = false;
}
Q_INVOKABLE void IPC_Thread::stopWork()
{
    _isStop = true;
}
Q_INVOKABLE void IPC_Thread::slotPostWork()
{
    QProcess process;
    while (1) {
        if(!_isStop){
            if(process.state()==QProcess::NotRunning){
                QString path = "/home/work/IPC_pro";
                process.start(path);
                if(process.waitForStarted()){
                    qInfo() << "IPC_Pro start successful"
                             <<process.readAllStandardOutput();
                }
                else {
                    qCritical() << "IPC_Pro start failed"<<process.readAllStandardError();
                }
            }

            else {
                qDebug() << "IPC_Pro running..."<<QThread::currentThreadId();
            }

        }
        else {
            process.close();
            process.kill();
        }
        QThread::sleep(30);
    }
}
