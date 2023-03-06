#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <stdio.h>
#include "node.h"
#include "test_generated.h"
#include "message_generated.h"
#include "zmq_wrapper.h"
#include "zmq_server.h"
#include "zmq_client.h"
//void server(void)
//{
//    zmq_server session ("test_topic", "tcp://127.0.0.1:7002");

//    zmsg *reply = 0;
//    while (1) {
//        zmsg *request = session.recv (reply);
//        if (request == 0) {
//            break;              //  Worker was interrupted
//        }

//        auto content = flatbuffers::GetRoot<MsgRequest>((uint8_t*)request->body());
//        printf("request recved: %s\n", content->request()->c_str());

//        MsgResponseT resp;
//        flatbuffers::FlatBufferBuilder fbb;

//        std::string recv = content->request()->c_str();
//        if(!recv.compare("hello"))
//        {
//            resp.response.assign("world");
//            fbb.Finish(CreateMsgResponse(fbb, &resp));
//        }
//        else if(!recv.compare("good"))
//        {
//            resp.response.assign("morning");
//            fbb.Finish(CreateMsgResponse(fbb, &resp));
//        }

//        delete request;
//        reply = new zmsg((const char*)fbb.GetBufferPointer(), fbb.GetSize());
//    }
//}





void CallBackFun(const char* topic, const void*payload, uint32_t len)
{
    printf("topic: %s\n", topic);
    auto msg = flatbuffers::GetRoot<Message>(payload);
    printf("timestamp: %lld\n", msg->timestamp());
    printf("name: %s\n", msg->node_name()->c_str());

    auto content = flatbuffers::GetRoot<MsgTest>(msg->data()->Data());
    printf("content result: %d\n", content->result());

    //     for(int i=0; i<content->array()->size(); i++)
    //     {
    //         printf("array id: %d\n", content->array()->Get(i)->id());
    //     }
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    datax::Node recver;
//    recver.Subscribe("tcp/message/test_topic", CallBackFun);

//    while(1)
//    {
//        Sleep(1);
//    }

    MainWindow w;
    w.show();
    return a.exec();
}
