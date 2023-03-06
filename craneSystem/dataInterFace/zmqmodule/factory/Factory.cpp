#include "Factory.h"
#include <QDebug>
#include "define_zmqmodule.h"
REGISTER(dataSub);//注册dataSend类
REGISTER(dataPub);//注册post类
REGISTER(workThread);//注册线程类
REGISTER(IPC_Thread);//注册线程类
Factory::Factory(QObject *parent) : QObject(parent)
{

    /***********数据回馈轮寻机制  **********/
    _Pthread = new workThread;
    _q_thread = new QThread;
    _Pthread->moveToThread(_q_thread);
    connect(_q_thread,SIGNAL(finished()),_Pthread,SLOT(deleteLater()));
    connect(_q_thread,SIGNAL(started()),_Pthread,SLOT(slotPostWork()));
//    /***********启动IPC进程间通信  **********/
    _IPC_thread = new IPC_Thread;
    _q_IPC_thread = new QThread;
    _IPC_thread->moveToThread(_q_IPC_thread);//启动进程间通信IPC
    connect(_q_IPC_thread,SIGNAL(finished()),_IPC_thread,SLOT(deleteLater()));
    connect(_q_IPC_thread,SIGNAL(started()),_IPC_thread,SLOT(slotPostWork()));

    //    QThreadPool thread_pool;
    //    workThread *work = new workThread;
    //    thread_pool.start(work);

}
Factory::~Factory()
{

    if(_q_thread->isRunning())
    {
        _Pthread->stopWork();  //关闭线程槽函数
        _q_thread->quit();            //退出事件循环
        _q_thread->wait();            //释放线程槽函数资源
    }
    if(_q_IPC_thread->isRunning())
    {
        _IPC_thread->stopWork();  //关闭线程槽函数
        _q_IPC_thread->quit();            //退出事件循环
        _q_IPC_thread->wait();            //释放线程槽函数资源
    }
}
void Factory::createProductClass(string classname)//不需要判断语句，直接根据字符创生产对应实例，方便扩展
{

    qDebug()<<classname.c_str()<<"KKKKKKKKKKKKKKKKKKKKKKK";
    this->_Product = (baseProduct*)factoryObject::GetInstance().GetClassByName(classname);
    initSlots();//初始化槽函数 必须在产品类创建完成之后
}
void Factory::initSlots()
{
//    if(!_q_IPC_thread->isRunning()){//绑定IPC_PRO
//        _q_IPC_thread->start();
//    }
    QObject::connect(this,SIGNAL(signalPostTopicDataParent(const void*,size_t,int )),_Product,
                     SIGNAL(signalPostTopicDataChild(const void*,size_t,int )));//post HMI发送过来的数据

    QObject::connect(_Product,SIGNAL(signalSubTopicDataChild(const void*,int,const uint32_t &)),this,
                     SIGNAL(signalSubTopicDataParent(const void*,int,const uint32_t &)),Qt::QueuedConnection);//sub 订阅HMI需要的数据传回HMI

    QObject::connect(_Product,SIGNAL(signalPostStartThread()),this,
                     SLOT(slotPostWorkStart()));//启动工作线程 当HMI有post的时候

    QObject::connect(_Product,SIGNAL(signalPostAppendData(const void *,size_t,int)),_Pthread,
                     SLOT(slotPostAppendData(const void *,size_t,int)),Qt::DirectConnection);//post 数据推送在线程中轮寻

    QObject::connect(_Product,SIGNAL(signalSubTopicDataChild(const void*,int,const uint32_t &)),_Pthread,
                     SLOT(slotSubAckAppendData(const void*,int,const uint32_t &)),Qt::DirectConnection);//判断post后的数据是否收到回复
    qDebug()<<"初始化产品类__________________"<<_Product;

}
void Factory::initMethods()
{
    //    if(_Product){
    //        qDebug() << QMetaObject::invokeMethod( _Product, "dataDoWork");
    //        qDebug() << QMetaObject::invokeMethod( _Product, "settingData");
    //        QString str;
    //        qDebug() << QMetaObject::invokeMethod(_Product
    //                                              , "settigData"
    //                                              ,Qt::AutoConnection
    //                                              ,Q_RETURN_ARG(QString, str)
    //                                              ,Q_ARG(QString, "")
    //                                              ,Q_ARG(QString, (""))
    //                                              );

    //        QMetaObject::invokeMethod(_Product, "signalChangeState", Q_ARG(int, 1), Q_ARG(int, 1), Q_ARG(int, 0));

    //    }
    qDebug()<<"数据集方法未初始化!";
}
void Factory::slotPostWorkStart()
{
    if(!_q_thread->isRunning()){
        _q_thread->start();
    }

}
///返回匹配的数据类型
template<class T_AGR>
QGenericArgument Factory::GETARG(const T_AGR & t,T_AGR v)
{

    QGenericArgument val =  Q_ARG(T_AGR,v);
    return val;
}
