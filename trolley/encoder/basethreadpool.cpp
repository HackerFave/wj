#include "basethreadpool.h"

baseThreadPool::baseThreadPool(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(signalStartWork()),this,SLOT(slotWork()));

}
