#include "baseThread.h"
#include <QDebug>
baseThread::baseThread(QObject *parent ) : QObject(parent)
{
    connect(this,SIGNAL(signalStartWork()),this,SLOT(slotPostWork()));

}
