
#ifndef TOPICCOMMON_H
#define TOPICCOMMON_H

#include <string>
#include <iostream>

using namespace std;
namespace topic{
enum Topic_ID{
    UNKNOW = 0,
//    // gps_info.fbs
//    TOPIC_TCP_GNSS_GPS_INFO_ENUM = 1,
//    TOPIC_TCP_GNSS_GPS_STATUS_ENUM = 2,
    //test
    TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM = 5,


};

inline const char* enumToString(Topic_ID operatior) {
    switch(operatior) {
#define interface(name) \
    case name: \
    return #name; \
    break;

    interface(TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM);

#undef interface
    default:
        return "UNKNOW";
    }
    return "UNKNOW";
}

inline const char* enumToOtherString(Topic_ID operatior) {
    switch(operatior) {
#define interface(operatior, v) \
    case operatior: \
    return #v; \
    break;
    interface(TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM, tcp/message/test_topic);

#undef interface
    default:
        return "UNKNOW";
    }
    return "UNKNOW";
}

inline Topic_ID enumFromString(const std::string & str) {
#define interface(operatior, v) \
    if(str == #v) { \
    return operatior; \
}
    interface(TOPIC_TCP_MESSAGE_TEST_TOPIC_ENUM, tcp/message/test_topic);

    return UNKNOW;
#undef interface
}
}
#endif // TOPICCOMMON_H
