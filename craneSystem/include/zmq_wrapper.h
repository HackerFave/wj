#ifndef ZMQ_WRAPPER_H
#define ZMQ_WRAPPER_H

#pragma once

#include <map>
#include <thread>
#include <vector>
#include "message_generated.h"
#include "zmq_addon.hpp"
#include <mutex>

namespace datax {

using SubscribeFunc = std::function<void(const char*, const void*, uint32_t)>;
using MessageFunc = std::function<void(const void*, uint32_t)>;

struct Func_t {};
// The derived type that represents a callback.
template<typename ...A>
struct Cb_t : public Func_t {
    using cb = std::function<void(A...)>;
    cb callback;
    Cb_t(cb p_callback) : callback(p_callback) {}
};

class ZmqProxy {
public:
    static ZmqProxy &GetInstance(void);
    zmq::context_t& GetZmqContext(void);

private:
    ZmqProxy(void);
    ~ZmqProxy(void);
    ZmqProxy(const ZmqProxy &proxy);
    const ZmqProxy &operator=(const ZmqProxy &proxy);

    zmq::context_t m_zmq_context;
};

// class ZmqBase {
// public:
//     ZmqBase();
//     ~ZmqBase(void);

//     void reconnect(zmq::socket_t &socket, std::string addr);
// };

class ZmqSubWrapper : public zmq::monitor_t {
public:
    ZmqSubWrapper(std::string);
    ~ZmqSubWrapper(void);

    template<typename ...A, typename T>
    void SubscribeTemplate(std::string topic, std::function<void(const T*)> func) {
        std::unique_ptr<datax::Func_t> f(new datax::Cb_t<const T*>(func));
        PreSubscribeTemplate(topic, std::move(f));
    }

    template<typename ...A>
    void PreSubscribeTemplate(std::string topic, std::unique_ptr<Func_t> func) {
        m_callbacks.insert(std::make_pair(topic, std::move(func)));
        m_suber.set(zmq::sockopt::subscribe, topic);
    }

    void Subscribe(std::string topic, SubscribeFunc func);
    void UnSubscribe(const std::string topic);

    void SubscribeAll(SubscribeFunc func);
    void UnSubscribeAll(void);

    void RegisterReceiver(std::string topic, MessageFunc func);
    //UnRegisterReceiver();

    void SubscribeWithMessage(std::string topic, SubscribeFunc func);
    void UnSubscribeWithMessage(const std::string topic);

    // size_t Post(std::string topic, const void *payload, size_t payload_len);
    // size_t PostWithMessage(std::string topic, const void *payload, size_t payload_len);

    void run(void);

    template<typename ...A>
    void call(std::string topic, A&& ... args)
    {
        using func_t = Cb_t<A...>;
        using cb_t = std::function<void(A...)>;
        const Func_t& base = *m_callbacks[topic];
        const cb_t& fun = static_cast<const func_t&>(base).callback;
        fun(std::forward<A>(args)...);
    }

private:
    void MessageHandler(void);

    ZmqProxy &proxy = ZmqProxy::GetInstance();

    std::map<std::string, MessageFunc> msgback_;
    std::map<std::string, SubscribeFunc> subback_;
    std::map<std::string, SubscribeFunc> sub_msg_back_;
    std::map<std::string, std::unique_ptr<Func_t>> m_callbacks;
    SubscribeFunc allback_ = nullptr;
    zmq::socket_t m_suber;
    // zmq::socket_t m_puber;
    std::thread thread_;
    int m_exit_flag = 0;
};

class ZmqPubWrapper : public zmq::monitor_t {
public:
    ZmqPubWrapper(std::string);
    ~ZmqPubWrapper(void);

    size_t Post(std::string topic, const void *payload, size_t payload_len);
    size_t PostWithMessage(std::string topic, const void *payload, size_t payload_len);

    void on_event_connected(const zmq_event_t &event, const char *addr) override;
    void on_event_connect_retried(const zmq_event_t &event, const char *addr) override;
    void on_event_disconnected(const zmq_event_t &event, const char *addr) override;

private:
    zmq::socket_t m_puber;
    std::string m_pub_channel;
    std::mutex m_mutex;
    int m_monitor_flag;
};

}  // namespace datax


#endif // ZMQ_WRAPPER_H
