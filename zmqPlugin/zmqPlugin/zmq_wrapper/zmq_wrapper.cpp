#include "zmq_wrapper.h"

#include <random>
#include <cstdlib>
#include <limits.h>
// #include "log.h"
#include <iostream>
#if (defined _WIN32 || defined WIN32)
#include "windows.h"
#include "wincrypt.h"
#endif
#include "zmq_addon.hpp"
using namespace std;
#define _ALIGNMENT_ 8
#define ZMQ_PROXY_PUB_CHANNEL   "inproc://pub_channel"
#define ZMQ_PROXY_SUB_CHANNEL   "inproc://sub_channel"

//#define ZMQ_PROXY_SUB_CHANNEL "tcp://127.0.0.1:5560"
//#define ZMQ_PROXY_PUB_CHANNEL "tcp://127.0.0.1:5561"

/**
* We can create a template function that simplifies our declarations of aligned
* shared pointers. Alignment and size are passed through to aligned malloc, and
* aligned free is always used as the deleter.  We then generate the correct pointer
* type based on the templated call
*
* Notice here that the shared pointer doesn't need a special type due to the deleter
* The deleter type is only required for the unique pointer.
*/

template<class T>
std::shared_ptr<T> aligned_sptr(size_t align, size_t size)
{
#if (defined _WIN32 || defined WIN32)
    return std::shared_ptr<T>(static_cast<T*>(_aligned_malloc(size, align)), &_aligned_free);
#else
    return std::shared_ptr<T>(static_cast<T*>(aligned_alloc(align, size)), &free);
#endif
}

#if (defined _WIN32 || defined WIN32)
int get_random()
{
    unsigned short _rand_value = 0;
    HCRYPTPROV       hProvider = 0;
    const DWORD      dwLength = 4;
    BYTE             pbBuffer[dwLength] = {};

    ::CryptAcquireContextW(&hProvider, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT);
    ::CryptGenRandom(hProvider, dwLength, pbBuffer);
    _rand_value = *(int*)pbBuffer;
    ::CryptReleaseContext(hProvider, 0);
    return _rand_value;
}
#else
int get_random(void)
{
    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<int> dist(1, INT_MAX);
    int number = dist(gen);
    return number;
}
#endif

namespace datax {

ZmqProxy::ZmqProxy(void)
{
    std::thread io_run_thread([&]() {
        zmq::socket_t frontend(GetZmqContext()/*context*/, /*ZMQ_ROUTER*/ ZMQ_XSUB);
        zmq::socket_t backend(GetZmqContext()/*context*/, /*ZMQ_DEALER*/ ZMQ_XPUB);
        frontend.bind(ZMQ_PROXY_PUB_CHANNEL);//"inproc://pub_channel"
        backend.bind(ZMQ_PROXY_SUB_CHANNEL);//"inproc://sub_channel"
        try {
            zmq::proxy(frontend, backend); // 4.持续运行代理

        } catch(const std::exception& e){}
    });
    io_run_thread.detach();
}

ZmqProxy::~ZmqProxy(void) {}

ZmqProxy &ZmqProxy::GetInstance(void)
{
    static ZmqProxy proxy;
    return proxy;
}

zmq::context_t &  ZmqProxy::GetZmqContext(void)
{
    return m_zmq_context;
}


// void ZmqBase::reconnect(zmq::socket_t &socket, std::string addr) {
//     socket.disconnect(addr);
//     socket.disconnect(addr);
// }


ZmqSubWrapper::ZmqSubWrapper(std::string sub_channel)
    : m_suber(proxy.GetZmqContext(), zmq::socket_type::sub) {
    // throw expection
    if(sub_channel.compare(0, 3, "tcp") == 0)
    {
        m_suber.set(zmq::sockopt::tcp_keepalive, 1);
        m_suber.set(zmq::sockopt::tcp_keepalive_cnt, 2);
        m_suber.set(zmq::sockopt::tcp_keepalive_idle, 5);
        m_suber.set(zmq::sockopt::tcp_keepalive_intvl, 1);
        m_suber.set(zmq::sockopt::reconnect_ivl, 100);
        m_suber.set(zmq::sockopt::reconnect_ivl_max, 10000);
        m_suber.set(zmq::sockopt::tcp_maxrt, 10000);
    }
    m_suber.connect(sub_channel);
}

ZmqSubWrapper::~ZmqSubWrapper() {
    m_exit_flag = 1;
    if(thread_.joinable()){
        thread_.join();
    }
}

// start server
void ZmqSubWrapper::run(void) {
    thread_ = std::thread(&ZmqSubWrapper::MessageHandler, this);
}

void ZmqSubWrapper::MessageHandler(void) {
    std::string topic;

    while(1)
    {
        if(m_exit_flag == 1) {
            break;
        }
        std::vector<zmq::message_t> recv_msgs;
        const auto ret = zmq::recv_multipart(m_suber, std::back_inserter(recv_msgs), zmq::recv_flags::dontwait);
        if (ret.has_value()) {
            std::string topic = recv_msgs[0].to_string();
            if(m_callbacks.find(topic) != m_callbacks.end()) {
                for(auto it=recv_msgs.begin()+1; it!=recv_msgs.end(); ++it) {
                    auto temp_buf = aligned_sptr<MessageT>(_ALIGNMENT_, _ALIGNMENT_ * ((*it).size() / _ALIGNMENT_ + 1));
                    std::memmove(temp_buf.get(), (*it).data(), (*it).size());
                    flatbuffers::Verifier verifier(reinterpret_cast<unsigned char*>(temp_buf.get()), (*it).size());
                    if(!VerifyMessageBuffer(verifier)) {
                        continue;
                    }
                    auto msg = flatbuffers::GetRoot<Message>(temp_buf.get());
                    if(msg->data() == nullptr) {
                        call(topic, nullptr);
                    } else {
                        call(topic, flatbuffers::GetRoot<Message>(msg->data()->Data()));
                    }
                }
            }
            if(msgback_.find(topic) != msgback_.end()) {
                // callback process
                for(auto it=recv_msgs.begin()+1; it!=recv_msgs.end(); ++it) {
                    if (msgback_[topic] != nullptr) {
                        auto temp_buf = aligned_sptr<MessageT>(_ALIGNMENT_, _ALIGNMENT_ * ((*it).size() / _ALIGNMENT_ + 1));
                        std::memmove(temp_buf.get(), (*it).data(), (*it).size());
                        msgback_[topic](reinterpret_cast<const void*>(temp_buf.get()), (*it).size());
                    }
                }
            }
            if(subback_.find(topic) != subback_.end()) {
                // callback process
                for(auto it=recv_msgs.begin()+1; it!=recv_msgs.end(); ++it) {
                    if (subback_[topic] != nullptr) {
                        auto temp_buf = aligned_sptr<MessageT>(_ALIGNMENT_, _ALIGNMENT_ * ((*it).size() / _ALIGNMENT_ + 1));
                        std::memmove(temp_buf.get(), (*it).data(), (*it).size());
                        subback_[topic](topic.c_str(),
                                reinterpret_cast<const void*>(temp_buf.get()),
                                (*it).size());
                    }
                }
            }
            if(sub_msg_back_.find(topic) != sub_msg_back_.end()) {
                // callback process
                for(auto it=recv_msgs.begin()+1; it!=recv_msgs.end(); ++it) {
                    if (sub_msg_back_[topic] != nullptr) {
                        auto temp_buf = aligned_sptr<MessageT>(_ALIGNMENT_, _ALIGNMENT_ * ((*it).size() / _ALIGNMENT_ + 1));
                        std::memmove(temp_buf.get(), (*it).data(), (*it).size());
                        flatbuffers::Verifier verifier(reinterpret_cast<unsigned char*>(temp_buf.get()),(*it).size());
                        if(!VerifyMessageBuffer(verifier)) {
                            continue;
                        }
                        auto msg = flatbuffers::GetRoot<Message>(temp_buf.get());
                        sub_msg_back_[topic](topic.c_str(),
                                reinterpret_cast<const void*>(msg->data()->Data()),
                                (*it).size());
                    }
                }
            }
            if(allback_ != nullptr) {
                // callback process
                for(auto it=recv_msgs.begin()+1; it!=recv_msgs.end(); ++it) {
                    auto temp_buf = aligned_sptr<MessageT>(_ALIGNMENT_, _ALIGNMENT_ * ((*it).size() / _ALIGNMENT_ + 1));
                    std::memmove(temp_buf.get(), (*it).data(), (*it).size());
                    allback_(topic.c_str(),
                             reinterpret_cast<const void*>(temp_buf.get()),
                             (*it).size());
                }
            }
        }
        //test if we need a little sleep
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void ZmqSubWrapper::Subscribe(std::string topic, SubscribeFunc func) {

    subback_.insert(std::make_pair(topic, func));
    m_suber.set(zmq::sockopt::subscribe, topic);
}

void ZmqSubWrapper::UnSubscribe(const std::string topic) {
    m_suber.set(zmq::sockopt::unsubscribe, topic);
    subback_.erase(topic);
}

void ZmqSubWrapper::SubscribeAll(SubscribeFunc func) {
    allback_ = func;
    m_suber.set(zmq::sockopt::subscribe, "");
}

void ZmqSubWrapper::UnSubscribeAll(void) {
    m_suber.set(zmq::sockopt::unsubscribe, "");
    allback_ = nullptr;
}

void ZmqSubWrapper::RegisterReceiver(std::string topic, MessageFunc func) {
    msgback_.insert(std::make_pair(topic, func));
    m_suber.set(zmq::sockopt::subscribe, topic);
}

void ZmqSubWrapper::SubscribeWithMessage(std::string topic, SubscribeFunc func) {
    sub_msg_back_.insert(std::make_pair(topic, func));
    m_suber.set(zmq::sockopt::subscribe, topic);
}

void ZmqSubWrapper::UnSubscribeWithMessage(const std::string topic) {
    m_suber.set(zmq::sockopt::unsubscribe, topic);
    sub_msg_back_.erase(topic);
}


ZmqPubWrapper::ZmqPubWrapper(std::string pub_channel)
    : m_puber(ZmqProxy::GetInstance().GetZmqContext(), zmq::socket_type::pub),
      m_pub_channel(pub_channel), m_monitor_flag(1) {
    // throw expection

    std::stringstream monitor_addr;
    monitor_addr << "inproc://monitor" << std::this_thread::get_id() << get_random();
    init(m_puber, monitor_addr.str(), ZMQ_EVENT_ALL);
    m_puber.set(zmq::sockopt::tcp_keepalive, 1);
    m_puber.set(zmq::sockopt::tcp_keepalive_cnt, 3);
    m_puber.set(zmq::sockopt::tcp_keepalive_idle, 120);
    m_puber.set(zmq::sockopt::tcp_keepalive_intvl, 10);
    m_puber.connect(m_pub_channel);
    std::thread f([&]() {
        try{
            while(m_monitor_flag) {
                check_event(10);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        } catch(const std::exception& e){}
    });
    f.detach();
}

ZmqPubWrapper::~ZmqPubWrapper(void) {
    m_monitor_flag = 0;
    m_puber.close();
}

size_t ZmqPubWrapper::Post(std::string topic, const void *payload, size_t payload_len) {
    std::unique_lock<std::mutex> lock(m_mutex);
    zmq::const_buffer cbuf(payload, static_cast<size_t>(payload_len));
    //    std::cout<<"[topic------->]"<< topic<<std::endl;
    m_puber.send(zmq::buffer(topic), zmq::send_flags::sndmore);
    size_t ret = m_puber.send(cbuf, zmq::send_flags::none).value();
    //    std::cout << " -- puber send size: " << ret<<std::endl;
    //    std::cout<<"[ret------->]"<< ret<<std::endl;
    return ret;
}

size_t ZmqPubWrapper::PostWithMessage(std::string topic, const void *payload, size_t payload_len) {
    MessageT msg;
    msg.timestamp = std::chrono::duration_cast< std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()).count();
    msg.node_name = topic;
    msg.data.assign((uint8_t*)payload, (uint8_t*)payload+payload_len);
    msg.size = payload_len;

    flatbuffers::FlatBufferBuilder builder;
    builder.Finish(CreateMessage(builder, &msg));
    return Post(topic, builder.GetBufferPointer(), builder.GetSize());
}

void ZmqPubWrapper::on_event_connected(const zmq_event_t &event, const char *addr) {
    // LOG_Debug() << " -- on_event_connected to: " << addr;
}

void ZmqPubWrapper::on_event_connect_retried(const zmq_event_t &event, const char *addr) {
    // LOG_Debug() << " -- on_event_connect_retried to!!";
    // m_puber.disconnect(m_pub_channel);
    // m_puber.connect(m_pub_channel);
}

void ZmqPubWrapper::on_event_disconnected(const zmq_event_t &event, const char *addr) {
    // LOG_Debug() << " -- on_event_disconnected to: " << addr << " reconnect to: " << m_pub_channel;
    try {
        // sleep a while beofre re-connect
#if (defined _WIN32 || defined WIN32)
        Sleep(1000);
#else
        sleep(1);
#endif
        m_puber.disconnect(m_pub_channel);
        m_puber.connect(m_pub_channel);
    } catch (zmq::error_t error) {
        // LOG_Warn() << "on_event_disconnected exception: " << error.what();
    }
}

}  // namespace datax
