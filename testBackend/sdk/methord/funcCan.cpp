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
    initSerialPort();//初始化底盘
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
    _A2 = publicClass::getInstance()->readValueIni("COM/A2").simplified();
    _A3 = publicClass::getInstance()->readValueIni("COM/A3").simplified();
    _A4 = publicClass::getInstance()->readValueIni("COM/A4").simplified();
    _A8 = publicClass::getInstance()->readValueIni("COM/A8").simplified();
    qRegisterMetaType<int16_t>("int32_t");

    _process_A2 = new QProcess(0);
    QString str = QCoreApplication::applicationDirPath()+ "/A2/encoder.exe";//加可执行文件路径

    _process_A2->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A2->start(str);

    if (!_process_A2->waitForStarted()) {
        qDebug() << "start failed:" << _process_A2->errorString();
    } else {
        qDebug() << "start success:";
    }

    _process_A3 = new QProcess(0);
    QString str_A3 = QCoreApplication::applicationDirPath()+ "/A3/encoder.exe";//加可执行文件路径

    _process_A3->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A3->start(str_A3);

    if (!_process_A3->waitForStarted()) {
        qDebug() << "start failed:" << _process_A3->errorString();
    } else {
        qDebug() << "start success:";
    }


    _process_A4 = new QProcess(0);
    QString str_A4 = QCoreApplication::applicationDirPath()+ "/A4/encoder.exe";//加可执行文件路径

    _process_A4->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A4->start(str_A4);

    if (!_process_A4->waitForStarted()) {
        qDebug() << "start failed:" << _process_A4->errorString();
    } else {
        qDebug() << "start success:";
    }

    _process_A8 = new QProcess(0);
    QString str_A8 = QCoreApplication::applicationDirPath()+ "/A8/encoder.exe";//加可执行文件路径

    _process_A8->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A8->start(str_A8);

    if (!_process_A8->waitForStarted()) {
        qDebug() << "start failed:" << _process_A8->errorString();
    } else {
        qDebug() << "start success:";
    }
    connect(&_timerBmqRead,SIGNAL(timeout()),this,SLOT(slotUpdateBmq()));
    _timerBmqRead.start(3000);
    initServer();
}
void funcCan::closeCan()
{
    VCI_ClearBuffer(4, 0, 0);//清理接收和发送缓冲器数据
    VCI_ClearBuffer(4, 0, 1);//清理接收和发送缓冲器数据
    if(VCI_CloseDevice(4,0)!=1)
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
    _pool.setMaxThreadCount(4);
    //    _threadMap[0] = new messageReportThreadPool_XT_01(0,1);
    //    _threadMap[0]->startWork();
    //    _threadMap[0]->setAutoDelete(true);

    //    _threadMap[1] = new messageReportThreadPool_XT_02(1,1);
    //    _threadMap[1]->startWork();
    //    _threadMap[1]->setAutoDelete(true);

    _threadMap[2] = new messageReportThreadPool_LX_603(2,0);
    _threadMap[2]->startWork();
    _threadMap[2]->setAutoDelete(true);

    _threadMap[3] = new messageReportThreadPool_TT_602(3,0);
    _threadMap[3]->startWork();
    _threadMap[3]->setAutoDelete(true);

    _threadMap[4] = new messageReportThreadPool_MT_141(4,0);
    _threadMap[4]->startWork();
    _threadMap[4]->setAutoDelete(true);

    //    _threadMap[5] = new messageReportThreadPool_MT_142(5,1);
    //    _threadMap[5]->startWork();
    //    _threadMap[5]->setAutoDelete(true);

    //    _threadMap[6] = new messageReportThreadPool_MT_143(6,1);
    //    _threadMap[6]->startWork();
    //    _threadMap[6]->setAutoDelete(true);

    _threadMap[7] = new messageReportThreadPool_MT_145(7,0);
    _threadMap[7]->startWork();
    _threadMap[7]->setAutoDelete(true);

    //    _pool.start(_threadMap[0]);
    //    _pool.start(_threadMap[1]);
    _pool.start(_threadMap[2]);
    _pool.start(_threadMap[3]);
    _pool.start(_threadMap[4]);
    //    _pool.start(_threadMap[5]);
    //    _pool.start(_threadMap[6]);
    _pool.start(_threadMap[7]);
    /*
 * @brief   :初始化recv线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */
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
            CAN_OBJ obj;
            std::lock_guard<std::mutex> lgd(_mutex);
            memmove(&obj,&((CAN_OBJ*)Recv)[i],sizeof (CAN_OBJ));
            emit signalDataToForm(obj.ID, obj.Data);
            setBuf(obj.ID, obj.Data,obj.DataLen);
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
    frame. DataLen=8;
    frame. SendType=0;
    frame. RemoteFlag=0;
    frame. ExternFlag=0;
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



QSerialPort* funcCan::initSerialPort()
{
    _serialPort = new QSerialPort(this);
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        qDebug()<<"[在线端口:]"<<info.portName();

    }
    _com = publicClass::getInstance()->readValueIni("COM/port").toLatin1();
    _serialPort->setPortName(_com);
    _serialPort->setBaudRate((QSerialPort::BaudRate)115200,QSerialPort::AllDirections);//波特率
    _serialPort->setDataBits((QSerialPort::DataBits)8);//数据位
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);
    _serialPort->setFlowControl(QSerialPort::NoFlowControl);
    if(_serialPort->open(QSerialPort::ReadWrite))
    {
        //        initThread();
        //        connect(&_timerTest, &QTimer::timeout, this, &func::slotWriteData);
        connect(_serialPort, &QSerialPort::readyRead, this, &funcCan::slotDataArrived);
        //        _timerTest.start(50);
        //        emit signalStatus(QSERIALWORK_ERR_OPEN_SUCCESS);
        //        _shareMemory.setKey(publicClass::getInstance()->readValueIni("COM/port"));//创建共享内存
        qDebug()<<"OPEN SUCCESS:"<<"[端口"<<publicClass::getInstance()->readValueIni("COM/port")<<"]";
    }else
    {
        qDebug() << __FUNCTION__ << "open fail，error info: " << this->_serialPort->errorString();
        //        emit signalStatus(QSERIALWORK_ERR_OPEN_FAILED);
        qDebug()<<"OPEN ERROR:"<<"[端口"<<publicClass::getInstance()->readValueIni("COM/port")<<"不在线]";
    }
    return _serialPort;
}



void funcCan::slotDataArrived()
{
    _buffer.append(_com);
    _buffer.append(_serialPort->readAll());
    QString ret(_buffer.toHex().toUpper());
    //    m_socket->write(_buffer);
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId()<<ret;
    _buffer.clear();
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
        QByteArray byte = QByteArray::fromHex(rcvstr.left(8).toUtf8());
        QString str;
        for(int i = 0; i < byte.count(); ++i)
        {
            str.append(QChar(byte .at(i)));
        }
        if(str==_A2){
            _isA2Start = true;
            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(8),rcvstr.mid(8).size()).split(" ");
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
                emit signalBmqDataToForm_A2(str,valueDuoquan,valueDanquan);
            }

        }
        if(str==_A3){
            _isA3Start = true;
            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(8),rcvstr.mid(8).size()).split(" ");
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

                emit signalBmqDataToForm_A3(str,valueDuoquan,valueDanquan);
            }

            //             _serialWorkThreadPool_BMQ_A3->slotWorkData(rcvstr.mid(8),str);
        }
        if(str==_A4){

            _isA4Start = true;
            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(8),rcvstr.mid(8).size()).split(" ");
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

                emit signalBmqDataToForm_A4(str,valueDuoquan,valueDanquan);
            }

            //             _serialWorkThreadPool_BMQ_A4->slotWorkData(rcvstr.mid(8),str);
        }
        if(str==_A8){
            _isA8Start = true;
            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(8),rcvstr.mid(8).size()).split(" ");
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

                emit signalBmqDataToForm_A8(str,valueDuoquan,valueDanquan);
            }
        }
    }
}

void funcCan::slotUpdateBmq()
{
    if(_isA2Start==true&&_isA3Start==true&&_isA4Start==true&&_isA8Start==true){
        _timerBmqRead.stop();
        qDebug()<<"running";
        return;
    }
    BYTE ss[8] = "1111111";
    setBuf(0x131,ss,8);
    exitProcess();
    QString str = QCoreApplication::applicationDirPath()+ "/A2/encoder.exe";//加可执行文件路径

    _process_A2->setProcessChannelMode(QProcess::MergedChannels);
    _process_A2->start(str);

    if (!_process_A2->waitForStarted()) {
        qDebug() << "start failed:" << _process_A2->errorString();
    } else {
        qDebug() << "start success:";
    }

    QString str_A3 = QCoreApplication::applicationDirPath()+ "/A3/encoder.exe";//加可执行文件路径

    _process_A3->setProcessChannelMode(QProcess::MergedChannels);
    _process_A3->start(str_A3);

    if (!_process_A3->waitForStarted()) {
        qDebug() << "start failed:" << _process_A3->errorString();
    } else {
        qDebug() << "start success:";
    }

    QString str_A4 = QCoreApplication::applicationDirPath()+ "/A4/encoder.exe";//加可执行文件路径

    _process_A4->setProcessChannelMode(QProcess::MergedChannels);
    _process_A4->start(str_A4);

    if (!_process_A4->waitForStarted()) {
        qDebug() << "start failed:" << _process_A4->errorString();
    } else {
        qDebug() << "start success:";
    }

    QString str_A8 = QCoreApplication::applicationDirPath()+ "/A8/encoder.exe";//加可执行文件路径

    _process_A8->setProcessChannelMode(QProcess::MergedChannels);
    _process_A8->start(str_A8);

    if (!_process_A8->waitForStarted()) {
        qDebug() << "start failed:" << _process_A8->errorString();
    } else {
        qDebug() << "start success:";
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
void funcCan::setBuf(UINT id, BYTE *data,int len)
{
    _fun(id,data);
}
void funcCan::regeditCallBack(Func fun)/*注册回调函数*/
{
    _fun = fun;
}
