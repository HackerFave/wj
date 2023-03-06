#include "node.h"

namespace datax {

Node::Node(void) {
#if not(defined _WIN32 || defined WIN32)
    m_ipc_sub = std::make_shared<datax::ZmqSubWrapper>("ipc://@message_pool/sub_channel");
    m_ipc_pub = std::make_shared<datax::ZmqPubWrapper>("ipc://@message_pool/pub_channel");
#endif
    //#if 0
    m_inproc_sub = std::make_shared<datax::ZmqSubWrapper>("inproc://sub_channel");
    m_inproc_pub = std::make_shared<datax::ZmqPubWrapper>("inproc://pub_channel");
    m_tcp_sub = std::make_shared<datax::ZmqSubWrapper>("tcp://127.0.0.1:7000");
    m_tcp_pub = std::make_shared<datax::ZmqPubWrapper>("tcp://127.0.0.1:7001");
}

Node::~Node(void) {

}

void Node::CheckStartServer(std::shared_ptr<ZmqSubWrapper> pool, int &flag) {
    std::unique_lock<std::mutex> lock(mutex_);
    if(!flag) {

        pool->run();

        flag = 1;
    }
}

void Node::CheckStopServer(std::shared_ptr<ZmqSubWrapper> pool, int &flag) {
    std::unique_lock<std::mutex> lock(mutex_);
    if(flag) {
        pool->run();
        flag = 0;
    }
}

std::shared_ptr<ZmqSubWrapper> Node::GetSubWrapper(std::string topic) {

    std::shared_ptr<ZmqSubWrapper> pool = nullptr;
    if(topic.compare(0, 6, "inproc") == 0)
        //    if(topic.compare(topic.size()-4,4,"5560"))
    {
        pool = m_inproc_sub;
        CheckStartServer(pool, m_inproc_flag);
#if not(defined _WIN32 || defined WIN32)
    } else if(topic.compare(0, 3, "ipc") == 0) {
        pool = m_ipc_sub;
        CheckStartServer(pool, m_ipc_flag);
#endif
    } else {
        pool = m_tcp_sub;
        CheckStartServer(pool, m_tcp_flag);
    }
    return pool;
}

std::shared_ptr<ZmqPubWrapper> Node::GetPubWrapper(std::string topic) {
    std::shared_ptr<ZmqPubWrapper> pool = nullptr;
    if(topic.compare(0, 6, "inproc") == 0)
        //    if(topic.compare(topic.size()-4,4,"5561"))
    {
        pool = m_inproc_pub;
#if not(defined _WIN32 || defined WIN32)
    } else if(topic.compare(0, 3, "ipc") == 0) {
        pool = m_ipc_pub;
#endif
    } else {

        pool = m_tcp_pub;

    }
    return pool;
}

void Node::Subscribe(std::string topic, SubscribeFunc func) {
    std::shared_ptr<ZmqSubWrapper> pool = GetSubWrapper(topic);
    pool->Subscribe(topic, func);
}

void Node::UnSubscribe(std::string topic) {
    std::shared_ptr<ZmqSubWrapper> pool = GetSubWrapper(topic);
    pool->UnSubscribe(topic);
}

void Node::SubscribeAll(SubscribeFunc func) {
#if not(defined _WIN32 || defined WIN32)
    m_ipc_sub->SubscribeAll(func);
    CheckStartServer(m_ipc_sub, m_ipc_flag);
#endif
    m_ipc_sub->SubscribeAll(func);
    CheckStartServer(m_ipc_sub, m_ipc_flag);

    m_inproc_sub->SubscribeAll(func);
    CheckStartServer(m_inproc_sub, m_inproc_flag);
    m_tcp_sub->SubscribeAll(func);
    CheckStartServer(m_tcp_sub, m_tcp_flag);
}

void Node::UnSubscribeAll(void) {
#if not(defined _WIN32 || defined WIN32)
    m_ipc_sub->UnSubscribeAll();
#endif
    m_ipc_sub->UnSubscribeAll();
    m_inproc_sub->UnSubscribeAll();
    m_tcp_sub->UnSubscribeAll();
}

void Node::SubscribeWithMessage(std::string topic, SubscribeFunc func) {
    std::shared_ptr<ZmqSubWrapper> pool = GetSubWrapper(topic);
    pool->SubscribeWithMessage(topic, func);
}

void Node::UnSubscribeWithMessage(std::string topic) {
    std::shared_ptr<ZmqSubWrapper> pool = GetSubWrapper(topic);
    pool->UnSubscribeWithMessage(topic);
}

size_t Node::Post(std::string topic, const void *payload, size_t payload_len) {
    std::shared_ptr<ZmqPubWrapper> pool = GetPubWrapper(topic);
    return pool->Post(topic, payload, payload_len);
}

size_t Node::PostWithMessage(std::string topic, const void *payload, size_t payload_len) {
    std::shared_ptr<ZmqPubWrapper> pool = GetPubWrapper(topic);
    return pool->PostWithMessage(topic, payload, payload_len);
}

// std::shared_ptr<ZmqWrapper> Node::GetIpcPool(void) {
//     CheckStartServer(m_ipc, m_ipc_flag);
//     return m_ipc;
// }

// std::shared_ptr<ZmqWrapper> Node::GetInprocPool(void) {
//     CheckStartServer(m_inproc, m_inproc_flag);
//     return m_inproc;
// }

// std::shared_ptr<ZmqWrapper> Node::GetTcpPool(void) {
//     CheckStartServer(m_tcp, m_tcp_flag);
//     return m_tcp;
// }

}  // namespace datax
