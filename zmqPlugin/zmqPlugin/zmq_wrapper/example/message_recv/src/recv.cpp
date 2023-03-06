#include <stdio.h>
//#include <unistd.h>
#include "node.h"
// #include "msg_topic.h"

//#include "test_generated.h"
#include "message_generated.h"
//#include "cgu_protocol_generated.h"

#include "zmq_server.h"

void server(void)
{
    zmq_server session ("test_topic", "tcp://localhost:7002");

    zmsg *reply = 0;
    while (1) {
        zmsg *request = session.recv (reply);
        if (request == 0) {
            break;              //  Worker was interrupted
        }

        auto content = flatbuffers::GetRoot<MsgRequest>((uint8_t*)request->body());
        printf("request recved: %s\n", content->request()->c_str());

        MsgResponseT resp;
        flatbuffers::FlatBufferBuilder fbb;

        std::string recv = content->request()->c_str();
        if(!recv.compare("hello"))
        {
            resp.response.assign("world");
            fbb.Finish(CreateMsgResponse(fbb, &resp));
        }
        else if(!recv.compare("good"))
        {
            resp.response.assign("morning");
            fbb.Finish(CreateMsgResponse(fbb, &resp));
        }

        delete request;
        reply = new zmsg((const char*)fbb.GetBufferPointer(), fbb.GetSize());
    }
}

void CallBackFun(const char* topic, const void*payload, uint32_t len)
{
    printf("topic: %s\n", topic);
    auto msg = flatbuffers::GetRoot<Message>(payload);
    printf("timestamp: %lld\n", msg->timestamp());
    printf("name: %s\n", msg->node_name()->c_str());

    auto content = flatbuffers::GetRoot<MsgTest>(msg->data()->Data());
    printf("content result: %d\n", content->result());

    // for(int i=0; i<content->array()->size(); i++)
    // {
    //     printf("array id: %d\n", content->array()->Get(i)->id());
    // }
}

int main(void)
{
    // start server
    // std::thread test_server(server);
    // test_server.detach();


    // pub-sub wrapper
    datax::Node recver;

    recver.Subscribe("ipc/message/test_topic", CallBackFun);

    // recver.SubscribeWithMessage("ipc/message/test_topic2", CallBackFun);
    // recver.GetIpcPool()->SubscribeAll(CallBackFun);
    // recver.SubscribeAll(CallBackFun);

    // std::function<void(const MsgTest*)> f = [](const MsgTest* msg) {
    //     if(msg == nullptr)
    //     {
    //         printf("recv null!\n");
    //     }
    //     else
    //     {
    //         printf("result: %d\n", msg->result());
    //     }
    // };

    // recver.SubscribeTemplate("ipc/message/test_topic3", f);

    while(1)
    {
        sleep(1);
    }


    return 0;
}
