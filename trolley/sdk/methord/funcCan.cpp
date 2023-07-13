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
    exitProcess();//退出编码器进程
    initBmq();//初始化编码器
    initCan();//初始化can通道
}
/*
 * @brief   : 析构
 * @author  :tanchuang
 * @date    :2023.03.31
 */
funcCan::~funcCan()
{
    exitProcess();//退出编码器进程
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
void funcCan::turnMove(int32_t value)
{
#if CANDEV_CX
    VCI_CAN_OBJ sendbuf[8];
#endif
#if CANDEV_GC
    CAN_OBJ sendbuf[8];
#endif
    bool ok;
    QString id = "602";
    QStringList sendMsg;
    sendMsg.clear();
    int32_t valuebmq = value*360/1000/20*524287/360;
//    if(value<0&&_currentA0Bmq<(121523+200)){
//        qDebug()<<"[ID:A0]"<<" Over limit position "<<_currentA0Bmq<<value;
//        return;
//    }
//    else if (value>0&&_currentA0Bmq>(233835-200)) {
//        qDebug()<<"[ID:A0]"<<" Over limit position "<<_currentA0Bmq<<value;
//        return;
//    }
    unsigned char s[4]={0,0,0,0} ;
    memmove(s,&value,4);
    //    sendMsg.append("2B 40 60 00 01 00 00 00");
    //    sendMsg.append("2B 40 60 00 00 00 00 00");
    //    sendMsg.append("2B 40 60 00 06 00 00 00");
    //    sendMsg.append("60 40 60 00 00 00 00 00");
    sendMsg.append(QString("23 7A 60 00 %1").arg(publicClass::getInstance()->Byte_16(s,4).simplified()));
    //    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));
    sendMsg.append(QString("40 41 60 00 01 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2f 60 60 00 01 00 00 00"));

    sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        _sleep(10);
#if CANDEV_CX
        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
#if CANDEV_GC
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
        if(flag<1)  //发送不正常
        {

            qDebug()<<"[ID:602]"<<"[SEND ERROR:"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified()<<"]";

        }
        else {
        }
    }

}


void funcCan::initCan()
{
#if CANDEV_CX
    PVCI_BOARD_INFO info;
    DWORD Reserved=0;
    //打开设备
    if(VCI_OpenDevice(4,0,Reserved)!=1)
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
    //初始化通道can
    if(VCI_InitCAN(4,0,0,InitInfo)!=1)	//
    {
        VCI_CloseDevice(4, 0);

        qDebug()<<"Init CAN failed!";
        return;
    }
    if(VCI_InitCAN(4,0,1,InitInfo)!=1)	//
    {
        VCI_CloseDevice(4, 0);

        qDebug()<<"Init CAN failed!";
        return;
    }
    if(VCI_StartCAN(4,0,0)!=1)	//
    {
        qDebug()<<"Start-CAN failed!";
        return;
    }
    if(VCI_StartCAN(4,0,1)!=1)	//
    {
        qDebug()<<"Start-CAN2 failed!";
        return;
    }


    qDebug()<<"Open successfule!\n Start CAN OK!";
#endif
#if CANDEV_GC
    int nDeviceType = 3; /* USBCAN-I */
    int nDeviceInd = 0;
    int nReserved =0;
    DWORD dwRel;
    dwRel = OpenDevice(nDeviceType, nDeviceInd, nReserved);
    if (dwRel != STATUS_OK)
    {
        qDebug()<<"Start-CAN failed!";
    }
    INIT_CONFIG init_config;
    memset(&init_config,0,sizeof(init_config));
    init_config.AccCode = /*0*/0x80000008; //验收码;
    init_config.AccMask =/*0xffffff*/0xFFFFFFFF; //不滤波
    init_config.Filter = 0;
    init_config.Timing0 = 0x00;
    init_config.Timing1 = 0x14; //波特率 250k
    init_config.Mode = 0; //正常模式
    if(InitCAN(3, 0, 0,&init_config)!=STATUS_OK)
    {
        qDebug()<<"Init CAN failed!";
        CloseDevice(3,0);
        return;
    }
    if(StartCAN(3, 0, 0) !=STATUS_OK)
    {
        qDebug()<<"Start-CAN1 failed!";
        CloseDevice(3,0);
        return;
    }
    qDebug()<<"Open successfule!\n Start CAN OK!";
#endif
    initThread();
}
void funcCan::initBmq()
{
    _A0 = publicClass::getInstance()->readValueIni("COM/A0").simplified();//底盘转向
    _A2 = publicClass::getInstance()->readValueIni("COM/A2").simplified();
    _A3 = publicClass::getInstance()->readValueIni("COM/A3").simplified();
    _A4 = publicClass::getInstance()->readValueIni("COM/A4").simplified();
    qRegisterMetaType<int16_t>("int32_t");


    _process = new QProcess(0);
    QString str = QCoreApplication::applicationDirPath()+ "/start.bat";//加可执行文件路径

    _process->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process->start(str);

    if (!_process->waitForStarted()) {
        qDebug() << "start failed:" << _process->errorString();
    } else {
        qDebug()  << "[bat]"<< "start success:";
    }

    connect(&_timerBmqRead,SIGNAL(timeout()),this,SLOT(slotUpdateBmq()));

#if IS_GKJ
    _timerBmqRead.start(30000);
#endif
    initServer();
}
void funcCan::closeCan()
{
#if CANDEV_CX
    VCI_ClearBuffer(4, 0, 0);//清理接收和发送缓冲器数据
    VCI_ClearBuffer(4, 0, 1);//清理接收和发送缓冲器数据
    if(VCI_CloseDevice(4,0)!=1)
    {
        qDebug()<<"Close failed";
        return;
    }
#endif
#if CANDEV_GC
    CloseDevice(3, 0);
#endif
    qDebug()<<"Close successful!";
}
void funcCan::openCan()
{

}
void funcCan::initThread()
{
    //线程池
    _threadMap.clear();
    _pool.setMaxThreadCount(6);

    //    _threadMap[0] = new messageReportThreadPool_LX_603(1,0);
    //    _threadMap[0]->startWork();
    //    _threadMap[0]->setAutoDelete(true);

    //    _threadMap[1] = new messageReportThreadPool_TT_601(2,0);
    //    _threadMap[1]->startWork();
    //    _threadMap[1]->setAutoDelete(true);

    //    _threadMap[2] = new messageReportThreadPool_MT_141(3,0);
    //    _threadMap[2]->startWork();
    //    _threadMap[2]->setAutoDelete(true);

    //    _threadMap[3] = new messageReportThreadPool_MT_145(4,0);
    //    _threadMap[3]->startWork();
    //    _threadMap[3]->setAutoDelete(true);

    _threadMap[4] = new messageReportThreadPool_YK_602(5,0);
    _threadMap[4]->startWork();
    _threadMap[4]->setAutoDelete(true);

    _threadMap[5] = new MachineEnableThreadPool(6,0);
    _threadMap[5]->startWork();
    _threadMap[5]->setAutoDelete(true);

    //    _pool.start(_threadMap[0]);
    //    _pool.start(_threadMap[1]);
    //    _pool.start(_threadMap[2]);
    //    _pool.start(_threadMap[3]);
    _pool.start(_threadMap[4]);
    _pool.start(_threadMap[5]);
    /*
 * @brief   :初始化recv线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */

#if CANDEV_CX
    /*******************************CAN1****************************************/
    P_canDataRecvThread_CAN1 = new canDataRecvThread(4,0,0);
    P_ThreadRecv_CAN1 = new QThread;
    P_canDataRecvThread_CAN1->moveToThread(P_ThreadRecv_CAN1);

    connect(P_ThreadRecv_CAN1,SIGNAL(finished()),P_canDataRecvThread_CAN1,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN1,SIGNAL(started()),P_canDataRecvThread_CAN1,SLOT(slotWork()));
    P_ThreadRecv_CAN1->start();
    P_canDataRecvThread_CAN1->startWork();

    connect(P_canDataRecvThread_CAN1,&canDataRecvThread::signalSendRecvData,this,&funcCan::slotRecvCanMessage,Qt::DirectConnection);

    /*******************************CAN2****************************************/
    P_canDataRecvThread_CAN2 = new canDataRecvThread(4,0,1);
    P_ThreadRecv_CAN2 = new QThread;
    P_canDataRecvThread_CAN2->moveToThread(P_ThreadRecv_CAN2);

    connect(P_ThreadRecv_CAN2,SIGNAL(finished()),P_canDataRecvThread_CAN2,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN2,SIGNAL(started()),P_canDataRecvThread_CAN2,SLOT(slotWork()));
    P_ThreadRecv_CAN2->start();
    P_canDataRecvThread_CAN2->startWork();

    connect(P_canDataRecvThread_CAN2,&canDataRecvThread::signalSendRecvData,this,&funcCan::slotRecvCanMessage,Qt::DirectConnection);

#endif

#if CANDEV_GC
    P_canDataRecvThread_CAN1 = new canDataRecvThread(3,0,0);
    P_ThreadRecv_CAN1 = new QThread;
    P_canDataRecvThread_CAN1->moveToThread(P_ThreadRecv_CAN1);

    connect(P_ThreadRecv_CAN1,SIGNAL(finished()),P_canDataRecvThread_CAN1,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN1,SIGNAL(started()),P_canDataRecvThread_CAN1,SLOT(slotWork()));
    P_ThreadRecv_CAN1->start();
    P_canDataRecvThread_CAN1->startWork();

    connect(P_canDataRecvThread_CAN1,&canDataRecvThread::signalSendRecvData,this,&funcCan::slotRecvCanMessage,Qt::DirectConnection);
    connect(P_canDataRecvThread_CAN1,&canDataRecvThread::signalReset,this,&funcCan::slotResetCan,Qt::DirectConnection);
#endif
}
void funcCan::slotResetCan()
{
#if CANDEV_GC

    //    if(ClearBuffer(3,0,0)){
    //        qDebug()<<"clear canbuffer success!!!";
    //    }
    if(ResetCAN(3,0,0)){
        qDebug()<<"CAN reset success!!!";
    }
    else {
        qDebug()<<"CAN reset failed!!!";
    }
#endif
}
void funcCan::slotRecvCanMessage(void *Recv,  DWORD Recv_Len,short can)
{

    if(Recv_Len>0)
    {
#if CANDEV_CX
        for(DWORD i=0;i<Recv_Len;i++){
            VCI_CAN_OBJ obj;
            std::lock_guard<std::mutex> lgd(_mutex);
            memmove(&obj,&((VCI_CAN_OBJ*)Recv)[i],sizeof (VCI_CAN_OBJ));
            emit signalDataToForm(obj.ID, obj.Data);
            setBuf(obj.ID, obj.Data,obj.DataLen);
        }
#endif
#if CANDEV_GC
        for(DWORD i=0;i<Recv_Len;i++){
            doBuf(&((CAN_OBJ*)Recv)[i]);
        }
#endif
    }

}
bool funcCan::writeData(uint32_t &ids,std::string &data)
{
#if CANDEV_CX
    VCI_CAN_OBJ sendbuf;
    bool ok;
    uint32_t id =ids;
    QString sendMsg = data.c_str();
    sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
    sendbuf.ID=id&0x7FF;
    sendbuf.SendType=0;
    sendbuf.TimeFlag=0;
    sendbuf.TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
    ULONG flag;

    flag=VCI_Transmit(4,0,0,&sendbuf,1); //调用动态链接库发送函数
    if(flag<1)  //发送不正常
    {
        return false;

    }
    else {
        return true;
    }
#endif
#if CANDEV_GC
    CAN_OBJ frame;
    memset(&frame,0,sizeof(frame));
    frame.ID=ids&0x7FF;
    frame.DataLen=8;
    frame.SendType=0;
    frame.RemoteFlag=0;
    frame.ExternFlag=0;
    //        BYTE data[]={1,2,3,4,5,6,7,8};
    QString sendMsg = data.c_str();
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg,frame.Data,&frame.DataLen);
    //        memcpy(frame.Data,data, frame.DataLen);
    if(Transmit(3, 0, 0,&frame,1) !=STATUS_OK)
    {
        qDebug()<<"send data failed!";
        return  false;
    }
    //    CloseDevice(3 ,0);
    return true;
    qDebug()<<"send data success!";
#endif
}
void funcCan::control(QString value)//向前
{
    QByteArray byte = QByteArray::fromHex(value.toLatin1());
    _serialPort->write(byte,byte.size());
}
void funcCan::initServer()
{
    m_server = new QLocalServer(this);
    //myserver为服务端名称,类似于IP+PORT,客户端连接需要与其保持一致
    if( m_server->listen("SERVER") ) //监听
    {
        connect(m_server,SIGNAL(newConnection()),this,SLOT(slot_new_connection()));
        qDebug("listen success!!\n");
    }
    else
        qDebug("listen fail\n");
    //m_server->removeServer("myserver");   //如果SERVER已经存在，则需删除
}
void funcCan::slot_new_connection()
{
    QLocalSocket *newsocket = m_server->nextPendingConnection();  //获取连接上的客户端句柄
    connect(newsocket, SIGNAL(readyRead()), this, SLOT(slot_recv_data())); //关联数据接收槽函数
}
void funcCan::slot_recv_data()
{

    // 取得是哪个localsocket可以读数据了
    QLocalSocket *local = static_cast<QLocalSocket *>(sender());
    if (!local)
        return;

    QByteArray rcv_data = local->readAll();
    QString rcvstr = rcv_data.toHex().toUpper();
    if(rcvstr>8){
        QString head = rcvstr.split("1A").at(0);
        QByteArray byte = QByteArray::fromHex(/*rcvstr.left(10).toUtf8()*/head.toUtf8());
        QString str;
        for(int i = 0; i < byte.count(); ++i)
        {
            str.append(QChar(byte .at(i)));
        }
        if(str==_A0){
            _isA0Start = true;
            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(head.size()),rcvstr.mid(head.size()).size()).split(" ");
            if(st.size()==11){
                QString dataDanquan = st.at(2)+" "+st.at(3)+" "+st.at(4)+" "+"00";
                QString dataFBL = st.at(5);
                QString dataDuoquan = st.at(6)+" "+st.at(7)+" "+st.at(8)+" "+"00";
                int32_t valueDanquan,valueDuoquan ;
                int8_t valueFBL;
                QByteArray byte = QByteArray::fromHex(dataDanquan.toLatin1());
                memcpy(&valueDanquan,byte.data(),byte.size());

                byte =  QByteArray::fromHex(dataFBL.toLatin1());
                memcpy(&valueFBL,byte.data(),byte.size());

                byte =  QByteArray::fromHex(dataDuoquan.toLatin1());
                memcpy(&valueDuoquan,byte.data(),byte.size());
                setBmqBuf(str.toStdString(),valueFBL,valueDanquan,valueDuoquan);
                _currentA0Bmq = valueDanquan;
            }

        }
//        if(str==_A2){
//            _isA2Start = true;
//            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(head.size()),rcvstr.mid(head.size()).size()).split(" ");
//            if(st.size()==11){
//                QString dataDanquan = st.at(2)+" "+st.at(3)+" "+st.at(4)+" "+"00";
//                QString dataFBL = st.at(5);
//                QString dataDuoquan = st.at(6)+" "+st.at(7)+" "+st.at(8)+" "+"00";
//                int32_t valueDanquan,valueDuoquan ;
//                int8_t valueFBL;
//                QByteArray byte = QByteArray::fromHex(dataDanquan.toLatin1());
//                memcpy(&valueDanquan,byte.data(),byte.size());

//                byte =  QByteArray::fromHex(dataFBL.toLatin1());
//                memcpy(&valueFBL,byte.data(),byte.size());

//                byte =  QByteArray::fromHex(dataDuoquan.toLatin1());
//                memcpy(&valueDuoquan,byte.data(),byte.size());
//                setBmqBuf(str.toStdString(),valueFBL,valueDanquan,valueDuoquan);
//                _currentA2Bmq = valueDanquan+524287*valueDuoquan;

//                if((_currentA2Bmq>383416/*83416*/+524287*4)&&(_valueSpeed141<0)){

//                    qDebug()<<"[ID:A2]"<<" Over limit position "<<_currentA2Bmq<<_valueSpeed141;
//                    stopRmd(0x141);

//                }
//                else if ((_currentA2Bmq<=524287+6842/*306842*/)&&(_valueSpeed141>0)) {
//                    qDebug()<<"[ID:A2]"<<" Over limit position "<<_currentA2Bmq<<_valueSpeed141;
//                    stopRmd(0x141);
//                }

//            }

//        }
//        if(str==_A3){
//            _isA3Start = true;
//            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(head.size()),rcvstr.mid(head.size()).size()).split(" ");
//            if(st.size()==11){
//                QString dataDanquan = st.at(2)+" "+st.at(3)+" "+st.at(4)+" "+"00";
//                QString dataFBL = st.at(5);
//                QString dataDuoquan = st.at(6)+" "+st.at(7)+" "+st.at(8)+" "+"00";
//                int32_t valueDanquan,valueDuoquan ;
//                int8_t valueFBL;
//                QByteArray byte = QByteArray::fromHex(dataDanquan.toLatin1());
//                memcpy(&valueDanquan,byte.data(),byte.size());

//                byte =  QByteArray::fromHex(dataFBL.toLatin1());
//                memcpy(&valueFBL,byte.data(),byte.size());

//                byte =  QByteArray::fromHex(dataDuoquan.toLatin1());
//                memcpy(&valueDuoquan,byte.data(),byte.size());
//                setBmqBuf(str.toStdString(),valueFBL,valueDanquan,valueDuoquan);
//                _currentA3Bmq = valueDanquan+524287*valueDuoquan;
//                if((_currentA3Bmq>/*309390*/209390+524287)&&(_valueSpeed601<0)){

//                    qDebug()<<"[ID:A3]"<<" Over limit position "<<_currentA3Bmq<<_valueSpeed601;
//                    stopTT();

//                }
//                else if ((_currentA3Bmq<=/*41290*/141290)&&(_valueSpeed601>0)) {
//                    qDebug()<<"[ID:A3]"<<" Over limit position "<<_currentA3Bmq<<_valueSpeed601;
//                    stopTT();
//                }
//            }

//        }
//        if(str==_A4){

//            _isA4Start = true;
//            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(head.size()),rcvstr.mid(head.size()).size()).split(" ");
//            if(st.size()==11){
//                QString dataDanquan = st.at(2)+" "+st.at(3)+" "+st.at(4)+" "+"00";
//                QString dataFBL = st.at(5);
//                QString dataDuoquan = st.at(6)+" "+st.at(7)+" "+st.at(8)+" "+"00";
//                int32_t valueDanquan,valueDuoquan ;
//                int8_t valueFBL;
//                QByteArray byte = QByteArray::fromHex(dataDanquan.toLatin1());
//                memcpy(&valueDanquan,byte.data(),byte.size());

//                byte =  QByteArray::fromHex(dataFBL.toLatin1());
//                memcpy(&valueFBL,byte.data(),byte.size());

//                byte =  QByteArray::fromHex(dataDuoquan.toLatin1());
//                memcpy(&valueDuoquan,byte.data(),byte.size());

//                setBmqBuf(str.toStdString(),valueFBL,valueDanquan,valueDuoquan);
//                //                qDebug()<<QString("[BMQ:%1]").arg(str)<<""<<valueDanquan<<valueFBL<<valueDuoquan;
//                _currentA4Bmq = valueDanquan+524287*valueDuoquan;
//            }

//        }
    }
}

void funcCan::slotUpdateBmq()
{
//    if(_A0.isEmpty()){
//        _isA0Start = true;
//    }
//    if(_A2.isEmpty()){
//        _isA2Start = true;
//    }
//    if(_A3.isEmpty()){
//        _isA3Start = true;
//    }
//    if(_A4.isEmpty()){
//        _isA4Start = true;
//    }
    if(/*_isA2Start==true&&_isA3Start==true&&_isA4Start==true&&*/_isA0Start==true){
        _timerBmqRead.stop();
        qDebug()<<"running";
        return;
    }
    exitProcess();
    QString str = QCoreApplication::applicationDirPath()+ "/start.bat";//加可执行文件路径

    _process->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process->start(str);

    if (!_process->waitForStarted()) {
        qDebug() << "start failed:" << _process->errorString();
    } else {
        qDebug()  << "[BMQ]"<< "start success:";
    }
}
void funcCan::exitProcess()
{
    QSharedPointer<QProcess> process(new QProcess(0));
    QString exe ="encoder.exe";
    QString c = "taskkill /f /t /im encoder.exe";    //exeFileName为要杀死的进程名
    process.data()->execute(c);
    process.data()->close();

}
#if CANDEV_CX
void funcCan::setBuf(VCI_CAN_OBJ *data)
{
    _fun(data);
}
#endif

#if CANDEV_GC
void funcCan::setBuf(CAN_OBJ * data)
{
    _fun(data);
}
void funcCan::setBmqBuf(std::string com,int8_t valueFBL, int32_t valueDanquan,int32_t valueDuoquan )
{

    _funBmq(com,valueFBL,valueDanquan,valueDuoquan);
}
#endif
void funcCan::regeditCallBack(Func fun)/*注册回调函数*/
{
    _fun = fun;
}
void funcCan::regeditCallBack(FuncBmq fun)/*注册回调函数*/
{
    _funBmq = fun;
}
void funcCan::doBuf(CAN_OBJ *data)
{
    setBuf(data);
    CAN_OBJ obj;
    memmove(&obj,data,sizeof (CAN_OBJ));

    int id = obj.ID;
    switch (id) {
    case 0x581:{
        int16_t index;
        memmove(&index,&data->Data[1],2);

        if(index == 0x3000){//速度
            int16_t value;
            memmove(&value,&data->Data[4],2);
            _valueSpeed601 = value;
        }
        else if(index == 0x6041){ //查询使能状态
            if(data->Data[4] == 0x37){
                static_cast<MachineEnableThreadPool*>(_threadMap[5])->setStatusEnable(0x601,true);

            }
            else {
                static_cast<MachineEnableThreadPool*>(_threadMap[5])->setStatusEnable(0x601,false);
            }
        }
        break;
    }
    case 0x583:{
        int32_t value;
        int16_t index;
        memmove(&index,&data->Data[1],2);
        if(index == 0x6064){
            memmove(&value,&data->Data[4],4);
            _currentA1Bmq = value;
            if((_currentA1Bmq>450953)&&(_valueSpeed603>0)){

                qDebug()<<"[ID:A1]"<<" Over limit position "<<_currentA1Bmq<<_valueSpeed603;
                stopLX();

            }
            else if ((_currentA1Bmq<=300000)&&(_valueSpeed603<0)) {
                qDebug()<<"[ID:A1]"<<" Over limit position "<<_currentA1Bmq<<_valueSpeed603;
                stopLX();
            }
        }
        break;
    }
    case 0x141:{
        //        int8_t valuetem;
        //        int16_t valueiq;
        int16_t valuespeed;
        //        uint16_t valueencoder;
        //        memmove(&valuetem,&data->Data[1],1);
        //        memmove(&valueiq,&data->Data[2],2);
        memmove(&valuespeed,&data->Data[4],2);
        //        memmove(&valueencoder,&data->Data[6],2);
        _valueSpeed141 = valuespeed;
        break;
    }
    case 0x145:{
        //        int8_t valuetem;
        //        int16_t valueiq;
        int16_t valuespeed;
        //        uint16_t valueencoder;
        //        memmove(&valuetem,&data->Data[1],1);
        //        memmove(&valueiq,&data->Data[2],2);
        memmove(&valuespeed,&data->Data[4],2);
        //        memmove(&valueencoder,&data->Data[6],2);
        _valueSpeed145 = valuespeed;
        break;
    }
    case 0x5C3:
    {
        int32_t valuespeed;
        char out[4] = {};
        out[0] = data->Data[3];
        out[1] = data->Data[2];
        out[2] = data->Data[1];
        out[3] = data->Data[0];
        memmove(&valuespeed,out,4);
        _valueSpeed603 = valuespeed;
        break;
    }

    default:
        break;
    }
}
void funcCan::stopTT()
{
#if CANDEV_GC

    CAN_OBJ sendbuf;
    sendbuf.Data[0] = 0x23;
    sendbuf.Data[1] = 0xFF;
    sendbuf.Data[2] = 0x60;
    sendbuf.Data[3] = 0x00;
    sendbuf.Data[4] = 0x00;
    sendbuf.Data[5] = 0x00;
    sendbuf.Data[6] = 0x00;
    sendbuf.Data[7] = 0x00;
    QString RowStr;
    sendbuf.DataLen=8 ;
    sendbuf.ExternFlag=0 ;
    sendbuf.RemoteFlag=0;
    sendbuf.ID=0x601&0x7ff;
    sendbuf.SendType=0;
    sendbuf.TimeFlag=0;
    sendbuf.TimeStamp=0;
    ULONG flag;
    flag=Transmit(3,0,0,&sendbuf,1); //调用动态链接库发送函数
    _sleep(5);
    if(flag<1)  //发送不正常
    {
    }
    else {
    }

#endif
}
void funcCan::stopLX()
{
#if CANDEV_GC
    CAN_OBJ sendbuf[9];
    QStringList sendMsg;
    sendMsg.append(QString("00 8A 00 00 00 00 "));//设置速度
    sendMsg.append(QString("00 84"));//停止运动
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
        sendbuf[i].ID= 0x643;
        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;

        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(5);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
#endif
}
void funcCan::stopRmd(uint16_t id)
{
#if CANDEV_GC

    CAN_OBJ sendbuf[1];
    QStringList sendMsg;
    QString datastr = "81 00 00 00 00 00 00 00";
    sendMsg.append(datastr.simplified());
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        sendbuf[i].ID=id&0x7FF;

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);

        ULONG flag =Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8);
        }
    }

#endif
}
void funcCan::controlMachine(ID id,int32_t angle)
{
#if CANDEV_GC

    if(id == 0x643){
#if 0
        CAN_OBJ sendbuf[9];
        QStringList sendMsg;
        static bool enabel = false;
        if(!enabel){
            sendMsg.append(QString("00 88 00 00 4E 20"));//设置加速度为 10000 count/s²
            sendMsg.append(QString("00 89 00 00 4E 20"));//设置减速度为 10000 count/s²
            sendMsg.append(QString("00 8A 00 00 4E 20"));//设置目标速度为 10000 count/s
            sendMsg.append(QString("01 00 00 00 00 01"));//电机使能
        }
        sendMsg.append(QString("00 8D 00 00 00 01"));//设置不带往返运动模式
        sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
        /***
     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
     * */
        if(angle<0) return;
        int32_t value = angle*(524287/360)+300000;
        if(value>450953){
            qDebug()<<"[ID:A1]"<<" Over limit position ";
            return;
        }
        unsigned char out4[4] ={};
        memmove(out4,&value,4);
        QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
        sendMsg.append(QString("00 86 ")+str4.split(" ").at(3)+" "
                       +str4.split(" ").at(2)+" "
                       +str4.split(" ").at(1)+" "
                       +str4.split(" ").at(0));//262144count 相当于180度=262144*（360/524287）
        sendMsg.append(QString("00 83"));//开始运动

        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
            sendbuf[i].ID= 0x643;
            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"error";

            }
            else {
                //                qDebug()<<"success"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen);
                enabel = true;
            }
        }
#endif

        int32_t valuespeed = angle;
        if(_currentA1Bmq<300000&&(valuespeed<0)){
            qDebug()<<"[ID:A1]"<<" Over limit position "<<"[speed:]"<<valuespeed<<"[BMQ:]"<<_currentA1Bmq;
            stopLX();
            return;
        }
        else if ((_currentA1Bmq>450953)&&(valuespeed>0)) {
            qDebug()<<"[ID:A1]"<<" Over limit position "<<"[speed:]"<<valuespeed<<"[BMQ:]"<<_currentA1Bmq;
            stopLX();
            return;
        }

        CAN_OBJ sendbuf[9];
        QStringList sendMsg;
        static bool enabel = false;
        if(!enabel){
            sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为连续运动
            sendMsg.append(QString("00 8D 00 00 00 00"));//设置运动模式为连续运动模式（相当于速度模式，以5C1 3E 设定速度连续运行）
            sendMsg.append(QString("00 88 00 00 75 30"));// 设置加速度 30000
            sendMsg.append(QString("00 89 00 00 75 30"));//设置减速度 30000
            unsigned char out4[4] ={};
            memmove(out4,&valuespeed,4);
            QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
            sendMsg.append(QString("00 8A ")+str4.split(" ").at(3)+" "
                           +str4.split(" ").at(2)+" "
                           +str4.split(" ").at(1)+" "
                           +str4.split(" ").at(0));//设置速度

            sendMsg.append(QString("01 00 00 00 00 01"));//电机使能
            sendMsg.append(QString("00 83"));//开始运动
        }
        else
        {
            unsigned char out4[4] ={};
            memmove(out4,&valuespeed,4);
            QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
            sendMsg.append(QString("00 8A ")+str4.split(" ").at(3)+" "
                           +str4.split(" ").at(2)+" "
                           +str4.split(" ").at(1)+" "
                           +str4.split(" ").at(0));//设置速度
            sendMsg.append(QString("00 83"));//开始运动
        }


        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
            sendbuf[i].ID= 0x643;
            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"error";

            }
            else {
                //                qDebug()<<"success"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen);
                enabel = true;
            }
        }
    }
    if(id == 0x601){
        CAN_OBJ sendbuf;

        int32_t valuespeed = angle*10;
        if(_currentA3Bmq</*41290*/141290&&(valuespeed>0)){
            qDebug()<<"[ID:A3]"<<" Over limit position "<<"[speed:]"<<valuespeed<<"[BMQ:]"<<_currentA3Bmq;
            stopTT();
            return;
        }
        else if ((_currentA3Bmq>/*309390*/209390+524287)&&(valuespeed<0)) {
            qDebug()<<"[ID:A3]"<<" Over limit position "<<"[speed:]"<<valuespeed<<"[BMQ:]"<<_currentA3Bmq;
            stopTT();
            return;
        }
        char speed[4] = {};
        memmove(speed,&valuespeed,4);
        sendbuf.Data[0] = 0x23;
        sendbuf.Data[1] = 0xFF;
        sendbuf.Data[2] = 0x60;
        sendbuf.Data[3] = 0x00;
        sendbuf.Data[4] = speed[0];
        sendbuf.Data[5] = speed[1];
        sendbuf.Data[6] = speed[2];
        sendbuf.Data[7] = speed[3];
        QString RowStr;
        sendbuf.DataLen=8 ;
        sendbuf.ExternFlag=0 ;
        sendbuf.RemoteFlag=0;
        sendbuf.ID=0x601&0x7ff;
        sendbuf.SendType=0;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        ULONG flag;
        flag=Transmit(3,0,0,&sendbuf,1); //调用动态链接库发送函数
        _sleep(5);
        if(flag<1)  //发送不正常
        {
        }
        else {
        }
    }
    if(id == 0x141){

        if(_currentA2Bmq>383416/*83416*/+524287*4){

            if(angle<0){
                qDebug()<<"[ID:A2]"<<" Over limit position "<<_currentA2Bmq<<angle;
                stopRmd(0x141);
                return;
            }

        }
        else if (_currentA2Bmq<=524287+6842/*306842*/) {
            if(angle>0){
                qDebug()<<"[ID:A2]"<<" Over limit position "<<_currentA2Bmq<<angle;
                stopRmd(0x141);
                return;
            }

        }

        CAN_OBJ sendbuf[1];
        QString id = "141";
        QStringList sendMsg;
        bool ok;
        QString datastr = "A2 00 00 00";
        unsigned char s[4]={0,0,0,0} ;
        int32_t value = angle*100;//(0.01dps/lsb) 1秒钟转0.01度  3000dps/lsb 表示 3000/360*60 rpm 转/min
        memmove(s,&value,4);

        datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

        sendMsg.append(datastr.simplified());
        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;


            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);

            ULONG flag =Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            if(flag<1)  //发送不正常
            {

            }
            else {
                qDebug()<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8);
            }
        }
    }
    if(id == 0x145){
        CAN_OBJ sendbuf[1];
        QString id = "145";
        QStringList sendMsg;
        bool ok;
        QString datastr = "A8 00";
        unsigned char s[2]={0,0} ;
        uint16_t valueMaxSpeed = 1000;//最大加速度

        unsigned char s1[4]={0,0,0,0} ;
        int32_t valueAngle = angle*100;

        memmove(s,&valueMaxSpeed,2);
        memmove(s1,&valueAngle,4);
        datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+publicClass::getInstance()->Byte_16(s1,4).simplified() ;

        sendMsg.append(datastr.simplified());
        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;

            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);

            ULONG flag =Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {
                qDebug()<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8);
            }
        }
    }
#endif
}
