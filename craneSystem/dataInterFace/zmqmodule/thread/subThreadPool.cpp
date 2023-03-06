#include "subThreadPool.h"
#include <QDebug>
subThreadPool::subThreadPool()
{

}
void subThreadPool::run()
{
    qDebug() << QThread::currentThreadId()<<"线程池";
    QThread::sleep(4);
}
