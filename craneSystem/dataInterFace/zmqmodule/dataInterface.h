#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include "baseObject.h"
#include "node.h"
#include <mutex>
#include <QVariantMap>
#include "topicCommon.h"
#include "../zmqmodule/factory/Factory.h"
#include "../zmqmodule/product/dataSub.h"
#include "../zmqmodule/product/dataPub.h"
class dataInterface : public baseObject
{
    Q_OBJECT
public:
private:
    explicit dataInterface(QObject *parent = nullptr);
    dataInterface & operator=(const dataInterface & ) = delete;
    dataInterface(const dataInterface &) = delete;
    void initProduct();
public:
    ~dataInterface();
    static dataInterface* getInstance();
    static void delInstance();
    void emitPostData(const void *payload, size_t payload_len, int id);
signals:
    void signalSubTopicData(const void*,int,const uint32_t & );//订阅
    void signalPostTopicData(const void *payload, size_t payload_len, int id );//发布
private:
    bool initConfigTopicIni();
private slots:
private:
    static dataInterface *P_dataInterface;
    static std::mutex _mutex;
    Factory * P_Factory = nullptr;

};

#endif // DATAINTERFACE_H
