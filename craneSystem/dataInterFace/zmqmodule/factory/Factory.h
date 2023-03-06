#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include <QMetaObject>
#include "factoryObject.h"
#include "../product/dataSub.h"
#include "../product/dataPub.h"
#include <qobjectdefs.h>
#include <QMap>
#include "../thread/workThread.h"
#include "../thread/IPC_Thread.h"
using namespace std;
class Factory : public QObject
{
    Q_OBJECT


public:
    explicit Factory(QObject *parent = nullptr);
    void createProductClass(string classname);//不需要判断语句，直接根据字符创生产对应实例，方便扩展
    void initMethods();
    ~Factory();
public:
    baseProduct *_Product = nullptr;
    baseThread *_Pthread = nullptr;
    QThread * _q_thread = nullptr;
    baseThread *_IPC_thread = nullptr;
    QThread * _q_IPC_thread = nullptr;
private:
    void initSlots();
    template<class T_AGR>
    QGenericArgument GETARG(const T_AGR & t,T_AGR v);
signals:
    void signalSubTopicDataParent(const void*,int,const uint32_t &);//发送到HMI的数据信号
    void signalPostTopicDataParent(const void*,size_t,int );//HMI POST的数据信号
private slots:
    void slotPostWorkStart();
private:
};

class RegisterAction{
public:
    RegisterAction(string className,create_fun ptrCreateFn){
        factoryObject::GetInstance().RegisterClassTmp(className,ptrCreateFn);
    }
};
#endif // FACTORY_H
