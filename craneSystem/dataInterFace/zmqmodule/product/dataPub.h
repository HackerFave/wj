#ifndef DATAPUBT_H
#define DATAPUBT_H

#include "baseProduct.h"
#include "node.h"

using namespace std;
class dataPub : public baseProduct
{
public:
    dataPub();
    Q_INVOKABLE void initPoint() override;
public slots:
    Q_INVOKABLE void slotPostTopicDataChild(const void*,size_t,int ) override;
private:
    datax::Node _sender;
    static dataPub *P_dataPub;
};

#endif // DATAPOST_H
