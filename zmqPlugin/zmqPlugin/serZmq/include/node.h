#pragma once
#include "zmq_wrapper.h"

namespace datax {

class Node {
public:
    Node(void);
    ~Node(void);

    template<typename ...A, typename T>
    void SubscribeTemplate(std::string topic, std::function<void(const T*)> func) {
        std::shared_ptr<ZmqSubWrapper> pool = GetSubWrapper(topic);
        pool->SubscribeTemplate(topic, func);
    }

    void Subscribe(std::string topic, SubscribeFunc func);
    void UnSubscribe(std::string topic);
    void SubscribeAll(SubscribeFunc func);
    void UnSubscribeAll(void);
    void SubscribeWithMessage(std::string topic, SubscribeFunc func);
    void UnSubscribeWithMessage(std::string topic);

    size_t Post(std::string topic, const void *payload, size_t payload_len);
    size_t PostWithMessage(std::string topic, const void *payload, size_t payload_len);

    // std::shared_ptr<ZmqWrapper> GetIpcPool(void);
    // std::shared_ptr<ZmqWrapper> GetInprocPool(void);
    // std::shared_ptr<ZmqWrapper> GetTcpPool(void);

private:
    void CheckStartServer(std::shared_ptr<ZmqSubWrapper> pool, int &flag);
    void CheckStopServer(std::shared_ptr<ZmqSubWrapper> pool, int &flag);
    std::shared_ptr<ZmqSubWrapper> GetSubWrapper(std::string topic);
    std::shared_ptr<ZmqPubWrapper> GetPubWrapper(std::string topic);

    std::mutex mutex_;
    int m_ipc_flag = 0;
    int m_inproc_flag = 0;
    int m_tcp_flag = 0;
#if not(defined _WIN32 || defined WIN32)
    std::shared_ptr<ZmqSubWrapper> m_ipc_sub;
    std::shared_ptr<ZmqPubWrapper> m_ipc_pub;
#endif
    std::shared_ptr<ZmqSubWrapper> m_ipc_sub;
    std::shared_ptr<ZmqPubWrapper> m_ipc_pub;
    std::shared_ptr<ZmqSubWrapper> m_inproc_sub;
    std::shared_ptr<ZmqPubWrapper> m_inproc_pub;
    std::shared_ptr<ZmqSubWrapper> m_tcp_sub;
    std::shared_ptr<ZmqPubWrapper> m_tcp_pub;
};

}  // namespace datax
