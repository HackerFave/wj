#include "dataInterface.h"
#include <QDebug>
#include "message_generated.h"

#include <QFile>
#include <QDir>
#include <QCoreApplication>


dataInterface* dataInterface::P_dataInterface = nullptr;
std::mutex dataInterface::_mutex ;
using namespace topic;

dataInterface::dataInterface(QObject *parent) : baseObject(parent)
{
    initProduct();
    //    initConfigTopicIni();

}
dataInterface::~dataInterface()
{
    delInstance();
    if(P_Factory){
        delete P_Factory;
    }
}
dataInterface* dataInterface::getInstance(){
    if (P_dataInterface == nullptr)
    {
        std::lock_guard<std::mutex> lgd(_mutex);
        if (P_dataInterface == nullptr)
        {
            P_dataInterface = new dataInterface;
        }
    }
    return P_dataInterface;
}
void dataInterface::delInstance()
{
    std::lock_guard<std::mutex> lgd(_mutex);
    if (P_dataInterface)
    {
        delete P_dataInterface;
        P_dataInterface = nullptr;
    }
}

void dataInterface::initProduct()
{
    /////subdata() //订阅数据
    if(!P_Factory){
        P_Factory = new Factory;
        P_Factory->createProductClass("dataSub");
        connect(P_Factory,SIGNAL(signalSubTopicDataParent(const void*,int ,const uint32_t &)),
                this,SIGNAL(signalSubTopicData(const void*,int ,const uint32_t &)),Qt::QueuedConnection);

        P_Factory->createProductClass("dataPub");
        connect(this,SIGNAL(signalPostTopicData(const void *, size_t, int)),
                P_Factory,SIGNAL(signalPostTopicDataParent(const void*,size_t,int  )));
    }

}
void dataInterface::emitPostData( const void *payload, size_t payload_len, int id )
{
    emit signalPostTopicData(payload,payload_len, id);
}

bool dataInterface::initConfigTopicIni()
{

    QString filePath = "/storage/zmqbin/configTopic/";
    QDir dir;
    if(dir.mkpath(filePath)){

        QFile file("/storage/zmqbin/configTopic/zmqtopic.ini");
        if(file.exists()){
            return true;
        }else {
            if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
                return true;
            }
        }
    }
    return  false;
}
