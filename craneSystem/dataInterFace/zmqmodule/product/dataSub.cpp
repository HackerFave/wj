#include "dataSub.h"
#include <QDebug>
#include "define_zmqmodule.h"

#include <string>
using namespace std;
dataSub * dataSub::P_dataSub  = nullptr;
dataSub::dataSub()
{

    initPoint();
    qRegisterMetaType<uint32_t>("uint32_t&");
    qRegisterMetaType<uint32_t>("uint32_t");

    //    _topicRecver.Subscribe(enumToOtherString(Topic_ID::TOPIC_TCP_GNSS_GPS_INFO_ENUM),
    //                           CallbackFunc);
    //    _topicRecver.Subscribe(enumToOtherString(Topic_ID::TOPIC_TCP_GNSS_GPS_STATUS_ENUM),
    //                           CallbackFunc);
    _topicRecver.Subscribe(enumToOtherString(Topic_ID::TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM),
                           CallbackFunc);
}

//初始化指针
Q_INVOKABLE void dataSub::initPoint()
{

    if(P_dataSub){
        delete P_dataSub;
        P_dataSub = this;
    }
    P_dataSub = this;
}

void dataSub::emitSignal(const void *f,int id, const uint32_t &len)
{    
    emit this->signalSubTopicDataChild(f,id,len);
}

void dataSub::CallbackFunc(const char* topic1, const void*payload, uint32_t len)//数据接受函数、、
{
    int id = enumFromString(std::string(topic1));

    if(id == TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM){
        auto msg = flatbuffers::GetRoot<Message>(payload);
        if(msg->data()&&msg->data()->Data()){
//            uint8_t *data  = new uint8_t[1024];
//            memcpy(data, msg->data()->Data(), len);
//            P_dataSub->emitSignal(data,id,len);
             qInfo() << "接收到" << id << ":" << topic1;
        }

    }
    qInfo() << "接收到" << id << ":" << topic1;
//    if(id==0){
//        std::string t_error = std::string(topic1)+"远端数据获取失败";
//        P_dataSub->emitSignal(t_error.c_str(),0,len);
//        return;
//    }
    //    auto msg = GetMessage(payload);
    //    auto msg = flatbuffers::GetRoot<Message>(payload);
    //    if(msg->data()&&msg->data()->Data()){
    //        uint8_t *data  = new uint8_t[1024];
    //        memcpy(data, msg->data()->Data(), len);
    //        P_dataSub->emitSignal(data,id,len);
    //    }else if(id == TOPIC_OTA_REQ_HOST_VERSION_ENUM){
    //        uint8_t *data  = new uint8_t[64];
    //        P_dataSub->emitSignal(data,id,1);
    //    }
}
