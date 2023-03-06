#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <stdio.h>
#include "zmq_client.h"
#include "zmq_server.h"
#include <stdio.h>
#include "node.h"
#include "test_generated.h"
#include "message_generated.h"

//void client1 (void)
//{
//    zmq_client session("tcp://127.0.0.1:7002");

//    while(1)
//    {
//        MsgRequestT req;
//        req.request.assign("hello");
//        flatbuffers::FlatBufferBuilder fbb;
//        fbb.Finish(CreateMsgRequest(fbb, &req));

//        zmsg * request = new zmsg(fbb.GetBufferPointer(), fbb.GetSize());

//        zmsg * reply = session.send ("test_topic", request);
//        if (reply) {
//            auto content = flatbuffers::GetRoot<MsgResponse>(reply->body());
//            printf("hello response: %s\n", content->response()->c_str());
//            delete reply;
//        } else {
//            printf("client1 send failed!\n");
//        }

//        Sleep(1);
//    }
//}

//void client2 (void)
//{
//    zmq_client session("tcp://127.0.0.1:7002");

//    while(1)
//    {
//        MsgRequestT req;
//        req.request.assign("good");
//        flatbuffers::FlatBufferBuilder fbb;
//        fbb.Finish(CreateMsgRequest(fbb, &req));

//        zmsg * request = new zmsg(fbb.GetBufferPointer(), fbb.GetSize());

//        zmsg * reply = session.send ("test_topic", request);
//        if (reply) {
//            auto content = flatbuffers::GetRoot<MsgResponse>(reply->body());
//            printf("good response: %s\n", content->response()->c_str());
//            delete reply;
//        } else {
//            printf("client2 send failed!\n");
//        }

//        Sleep(1);
//    }
//}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    //         pub-sub wrapper
    MsgTestT result;
    result.result = 1;

    for(int i=1; i<5001; i++)
    {
        std::unique_ptr<RepeatT> rep(new RepeatT());
        rep->id = i;
        result.array.push_back(std::move(rep));
    }

    flatbuffers::FlatBufferBuilder fbb;
    fbb.Finish(CreateMsgTest(fbb, &result));

    MessageT msg;
    msg.timestamp = 12345;
    msg.node_name = "sender";
    msg.data.assign(fbb.GetBufferPointer(), fbb.GetBufferPointer() + fbb.GetSize());
    msg.size = fbb.GetSize();

    flatbuffers::FlatBufferBuilder builder;
    builder.Finish(CreateMessage(builder, &msg));

    datax::Node sender;

    while(1)
    {

        sender.PostWithMessage("tcp/message/test_topic", fbb.GetBufferPointer(), fbb.GetSize());
        Sleep(1);
    }


    return a.exec();
}
