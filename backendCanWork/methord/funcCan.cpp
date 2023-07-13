#include "funcCan.h"
#include <QTextStream>
#include <QDateTime>
#include <synchapi.h>  //QSleep
#include <QDebug>
#include <usbscan.h>
funcCan::funcCan(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<UINT>("UINT");
    qRegisterMetaType<BYTE>("BYTE");
    qRegisterMetaType<VCI_CAN_OBJ>("VCI_CAN_OBJ");
    qRegisterMetaType<DWORD>("DWORD");
    qRegisterMetaType<int16_t>("int16_t");
    initCan();
}
/*
 * @brief   : 析构
 * @author  :tanchuang
 * @date    :2023.03.31
 */
funcCan::~funcCan()
{
    closeCan();
    releaseThread();
}
//释放线程池
void funcCan::releaseThread()
{
    if(!_threadMap.isEmpty()){
        _threadMap.clear();
    }
    if(P_ThreadRecv_CAN1){
        qDebug()<<P_canDataRecvThread_CAN1<<P_ThreadRecv_CAN1<<"ID";
        P_canDataRecvThread_CAN1->stopWork();
        P_ThreadRecv_CAN1->quit();
        P_ThreadRecv_CAN1->deleteLater();
        P_ThreadRecv_CAN1 = nullptr;
        P_canDataRecvThread_CAN1 = nullptr;
    }
    if(P_ThreadRecv_CAN2){
        qDebug()<<P_canDataRecvThread_CAN2<<P_ThreadRecv_CAN2<<"ID";
        P_canDataRecvThread_CAN2->stopWork();
        P_ThreadRecv_CAN2->quit();
        P_ThreadRecv_CAN2->deleteLater();
        P_ThreadRecv_CAN2 = nullptr;
        P_canDataRecvThread_CAN2 = nullptr;
    }
    if(P_ThreadSend){
        P_canDataSendThread->stopWork();
        P_ThreadSend->quit();
        P_ThreadSend->deleteLater();
        P_ThreadSend = nullptr;
        P_canDataSendThread = nullptr;
    }
    _pool.releaseThread();
}

void funcCan::initCan()
{
    DWORD Reserved=0;
    uchar BaudIndex=static_cast<uchar>(13);  //获取波特率选取序号
    //打开设备
    if(VCI_OpenDevice(m_DevType,m_DevIndex,Reserved)!=1)
    {
        qDebug()<<"Open can error";
        return;
    }
    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=/*Bsp[BaudIndex][0]*/0x00;
    InitInfo->Timing1=/*Bsp[BaudIndex][1]*/0x14;
    InitInfo->Filter=static_cast<UCHAR>(1); //接收数据类型
    InitInfo->AccCode=0x80000008; //验收码
    //InitInfo->AccCode=0x80000000;
    InitInfo->AccMask=0xFFFFFFFF; //屏蔽码,表示全部接接收
    InitInfo->Mode=static_cast<UCHAR>(0);  //正常模式 工作模式
    //初始化通道can1
    m_CanIndex=static_cast<DWORD>(0);  //Can1或者Can2
    publicClass::getInstance()->setCurrentCanIndex(m_CanIndex);
    if(VCI_InitCAN(m_DevType,m_DevIndex,0,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);

        qDebug()<<"Init CAN failed!";
        return;
    }
    if(VCI_InitCAN(m_DevType,m_DevIndex,1,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);

        qDebug()<<"Init CAN failed!";
        return;
    }
    if(VCI_StartCAN(m_DevType,m_DevIndex,0)!=1)	//
    {
        qDebug()<<"Start-CAN1 failed!";
        return;
    }
    if(VCI_StartCAN(m_DevType,m_DevIndex,1)!=1)	//
    {
        qDebug()<<"Start-CAN2 failed!";
        return;
    }
    qDebug()<<"Open successfule!\n Start CAN OK!";
    publicClass::getInstance()->setValueIni("index/DevIndex",QString::number(m_DevIndex));
    publicClass::getInstance()->setValueIni("index/CanIndex",QString::number(m_CanIndex));

    initThread();
}
void funcCan::closeCan()
{
    VCI_ClearBuffer(m_DevType, m_DevIndex, 0);//清理接收和发送缓冲器数据
    VCI_ClearBuffer(m_DevType, m_DevIndex, 1);//清理接收和发送缓冲器数据
    if(VCI_CloseDevice(m_DevType,m_DevIndex)!=1)
    {
        qDebug()<<"Close failed";
        return;
    }
    qDebug()<<"Close successful!";
}
void funcCan::openCan()
{

}
void funcCan::initThread()
{
    //线程池
    _threadMap.clear();
    _pool.setMaxThreadCount(8);
    _threadMap[0] = new messageReportThreadPool_XT_01(0,1);
    _threadMap[0]->startWork();
    _threadMap[0]->setAutoDelete(true);

    _threadMap[1] = new messageReportThreadPool_XT_02(1,1);
    _threadMap[1]->startWork();
    _threadMap[1]->setAutoDelete(true);

    _threadMap[2] = new messageReportThreadPool_LX_603(2,0);
    _threadMap[2]->startWork();
    _threadMap[2]->setAutoDelete(true);

    _threadMap[3] = new messageReportThreadPool_TT_602(3,0);
    _threadMap[3]->startWork();
    _threadMap[3]->setAutoDelete(true);

    _threadMap[4] = new messageReportThreadPool_MT_141(4,0);
    _threadMap[4]->startWork();
    _threadMap[4]->setAutoDelete(true);

    _threadMap[5] = new messageReportThreadPool_MT_142(5,1);
    _threadMap[5]->startWork();
    _threadMap[5]->setAutoDelete(true);

    _threadMap[6] = new messageReportThreadPool_MT_143(6,1);
    _threadMap[6]->startWork();
    _threadMap[6]->setAutoDelete(true);

    _threadMap[7] = new messageReportThreadPool_MT_145(7,0);
    _threadMap[7]->startWork();
    _threadMap[7]->setAutoDelete(true);

    _pool.start(_threadMap[0]);
    _pool.start(_threadMap[1]);
//    _pool.start(_threadMap[2]);
//    _pool.start(_threadMap[3]);
//    _pool.start(_threadMap[4]);
    _pool.start(_threadMap[5]);
    _pool.start(_threadMap[6]);
//    _pool.start(_threadMap[7]);
    /*
 * @brief   :初始化recv线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */
    /*******************************CAN1****************************************/
    P_canDataRecvThread_CAN1 = new canDataRecvThread(m_DevType,m_DevIndex,0);
    P_ThreadRecv_CAN1 = new QThread;
    P_canDataRecvThread_CAN1->moveToThread(P_ThreadRecv_CAN1);

    connect(P_ThreadRecv_CAN1,SIGNAL(finished()),P_canDataRecvThread_CAN1,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN1,SIGNAL(started()),P_canDataRecvThread_CAN1,SLOT(slotWork()));
    P_ThreadRecv_CAN1->start();
    P_canDataRecvThread_CAN1->startWork();

    connect(P_canDataRecvThread_CAN1,&canDataRecvThread::signalSendRecvData,this,&funcCan::slotRecvCanMessage,Qt::DirectConnection);

    /*******************************CAN2****************************************/
    P_canDataRecvThread_CAN2 = new canDataRecvThread(m_DevType,m_DevIndex,1);
    P_ThreadRecv_CAN2 = new QThread;
    P_canDataRecvThread_CAN2->moveToThread(P_ThreadRecv_CAN2);

    connect(P_ThreadRecv_CAN2,SIGNAL(finished()),P_canDataRecvThread_CAN2,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN2,SIGNAL(started()),P_canDataRecvThread_CAN2,SLOT(slotWork()));
    P_ThreadRecv_CAN2->start();
    P_canDataRecvThread_CAN2->startWork();

    connect(P_canDataRecvThread_CAN2,&canDataRecvThread::signalSendRecvData,this,&funcCan::slotRecvCanMessage,Qt::DirectConnection);


    //    P_canDataSendThread = new canDataSendThread(m_DevType,m_DevIndex,m_CanIndex);
    //    P_ThreadSend = new QThread;

    //    P_canDataSendThread->moveToThread(P_ThreadSend);
    //    connect(P_ThreadSend,SIGNAL(finished()),P_canDataSendThread,SLOT(deleteLater()));
    //    connect(P_ThreadSend,SIGNAL(started()),P_canDataSendThread,SLOT(slotWork()));

    //    //can报文写入线程
    //    connect(this,SIGNAL(signalSendCanBuf(void *,int)),P_canDataSendThread,SLOT(slotSendCanBuf(void *,int)),Qt::DirectConnection);
    //    connect(this,SIGNAL(signalRecvId(QString)),P_canDataSendThread,SLOT(slotRecvId(QString)),Qt::DirectConnection);

    //    P_ThreadSend->start();
    //    P_canDataSendThread->startWork();
}

void funcCan::slotRecvCanMessage(VCI_CAN_OBJ *Recv,  DWORD Recv_Len)
{

    if(Recv_Len>0)
    {
        for(DWORD i=0;i<Recv_Len;i++){

            //            QString systime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"); //系统时间
            //            QString timeStamp=QString::number(QDateTime::currentMSecsSinceEpoch());  //当前毫秒级时间戳
            //            QString channel=ui->comboBox_Channel->currentText(); //当前can通道（can1或者can2）
            //            QString direct="Recv"; //接收
            //            QString id=QString::number(Recv->ID,16).toUpper();  //CanID
            //            QString type=ui->comboBox_frame_type->currentText();  //帧类型 数据帧 远程帧
            //            QString format=ui->comboBox_format->currentText(); //帧格式 标准帧 扩展帧
            //            QString datalen=QString::number(Recv->DataLen,10); //数据长度
            qDebug()<<publicClass::getInstance()->hex2Str(Recv[i].Data,Recv[i].DataLen); //数据
            //            *rowstr=index+":    "+systime+"   "+timeStamp+"   "+channel+"   "+direct+"   "+id+"   "+type+"   "+format+"   "+datalen+"   "+data+"\n";
            //            QStandardItem *itemmodel = new QStandardItem(direct);
            //            itemmodel->setForeground(QBrush(QColor(0, 255, 0)));
            //            Rowtext<</*new QStandardItem(index)<<*/new QStandardItem(systime)<</*new QStandardItem(timeStamp)*/new QStandardItem(channel)
            //                  <<itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
            //                 <<new QStandardItem(datalen)<<new QStandardItem(data);
            //            return Rowtext;
        }
    }
}
