#ifndef DATASUB_H
#define DATASUB_H
#include "baseProduct.h"
#include "node.h"
using namespace std;
class dataSub : public baseProduct
{
public:
    dataSub();
    Q_INVOKABLE void initPoint() override;
    // 设置回调函数的函数
    static void CallbackFunc(const char* topic, const void*payload, uint32_t len);//数据接受函数、、
    void emitSignal(const void *,int id, const uint32_t &len);
signals:
public slots:
private:
    datax::Node _topicRecver;
    static dataSub *P_dataSub;
};

#endif // DATASEND_H
