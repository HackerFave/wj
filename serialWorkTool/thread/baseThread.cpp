#include "baseThread.h"
#include <QDebug>
baseThread::baseThread(QObject *parent ) : QObject(parent)
{
    connect(this,SIGNAL(signalStartWork()),this,SLOT(slotPostWork()));
//     connect(this,SIGNAL(signalSendCanBuf(void *,int )),this,SLOT(slotSendCanBuf(void *,int)));

}
