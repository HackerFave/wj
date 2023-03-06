#include <QCoreApplication>
#include "zmq_addon.hpp"
#include "zmq.h"

#define ZMQ_PROXY_SUB_CHANNEL "tcp://127.0.0.1:7000"
#define ZMQ_PROXY_PUB_CHANNEL "tcp://127.0.0.1:7001"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    zmq::context_t ctx(1);
    zmq::socket_t frontend(ctx, /*ZMQ_ROUTER*/ ZMQ_XSUB);
    zmq::socket_t backend(ctx, /*ZMQ_DEALER*/ ZMQ_XPUB);
    frontend.bind(ZMQ_PROXY_PUB_CHANNEL);
    backend.bind(ZMQ_PROXY_SUB_CHANNEL);
    zmq::proxy(frontend, backend);
    return a.exec();
}
