#include "dataPub.h"
#include "define_zmqmodule.h"
#include <stdio.h>
#include <QtDebug>
dataPub *dataPub::P_dataPub = nullptr;

dataPub::dataPub()
{
    qRegisterMetaType<size_t>("size_t&");
    qRegisterMetaType<size_t>("size_t");
    initPoint();

}
Q_INVOKABLE void dataPub::initPoint()
{
    if(P_dataPub){
        delete P_dataPub;
        P_dataPub = this;
    }
    P_dataPub = this;
}

Q_INVOKABLE void dataPub::slotPostTopicDataChild( const void *payload, size_t payload_len,int id)
{

    Topic_ID flag = static_cast<Topic_ID>(id);
    _sender.Post(enumToOtherString(flag), payload, payload_len);
    qDebug()<<enumToOtherString(flag)<<id<<payload_len<<"测试post数据----------------------------------";
    emit this->signalPostStartThread();
    emit this->signalPostAppendData(payload, payload_len,id);
}
