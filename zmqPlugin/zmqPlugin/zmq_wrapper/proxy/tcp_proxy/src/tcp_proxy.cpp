#include "../../ZeroMQ/zmq_addon.hpp"

#define ZMQ_PROXY_SUB_CHANNEL "tcp://192.168.20.20:7000"
#define ZMQ_PROXY_PUB_CHANNEL "tcp://192.168.20.20:7001"

int main(void)
{
    zmq::context_t ctx(1);
    zmq::socket_t frontend(ctx, /*ZMQ_ROUTER*/ ZMQ_XSUB);
    zmq::socket_t backend(ctx, /*ZMQ_DEALER*/ ZMQ_XPUB);
    frontend.bind(ZMQ_PROXY_PUB_CHANNEL);
    backend.bind(ZMQ_PROXY_SUB_CHANNEL);
    zmq::proxy(frontend, backend);

    return 0;
}
