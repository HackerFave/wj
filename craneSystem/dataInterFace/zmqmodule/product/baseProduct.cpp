#include "baseProduct.h"

baseProduct::baseProduct(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(signalPostTopicDataChild(const void*,size_t,int )),
            this,SLOT(slotPostTopicDataChild(const void*,size_t,int )));
}
