#include "workThread.h"
#include <QDebug>
#include "node.h"
#include "topicCommon.h"
#include "node.h"
#define TIME_OUT 30
using namespace topic;
workThread::workThread()
{

}
Q_INVOKABLE void workThread::startWork()
{
    _isStop = false;
}
Q_INVOKABLE void workThread::stopWork()
{
    _isStop = true;
}
Q_INVOKABLE void workThread::slotPostWork()
{
    qDebug()<<"hmi--->post 巡检线程启动"<<_id<<QThread::currentThreadId();
    while (1)
    {
        if(_isStop)
            return;
        if(_dataMap.isEmpty()){
            qDebug()<<"当前需要发送的数据已经全部发送成功，准备停止当前线程";
            stopWork();
        }else {
            datax::Node nodepost;
            QMap<int, QVariantList> ::iterator it;
            for(it = _dataMap.begin();it!=_dataMap.end();it++){
                Topic_ID flag = static_cast<Topic_ID>(it.key());
                nodepost.Post(enumToOtherString(flag),it.value().at(0).data(),it.value().at(1).toUInt());
            }
            QThread::sleep(TIME_OUT);
        }
     qDebug()<<"post线程执行中..."<<_id<<QThread::currentThreadId();
    }
}
Q_INVOKABLE void workThread::slotPostAppendData(const void * f,size_t len,int id)
{
    _id = id;
    Topic_ID flag = static_cast<Topic_ID>(id);
    if(len!=0){
        QVariantList list;
        list.append(f);
        list.append(len);
        _dataMap.insert(id,list);
    }
    qDebug()<<"当前正在post的数据:"<<enumToOtherString(flag)<<QThread::currentThreadId();
    if(_isStop){
        startWork();
    }
}
Q_INVOKABLE void workThread::slotSubAckAppendData(const void*f,int id,const uint32_t &len)
{
    Topic_ID flag = static_cast<Topic_ID>(id);
//    qDebug()<<"已经收取到回复需要删除的id:"<<len<<enumToOtherString(flag)<<QThread::currentThreadId();
    if(_dataMap.contains(id)){
        if(len!=0){
            _dataMap.remove(id);
        }
    }
}
