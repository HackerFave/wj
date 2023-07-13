#include "canDataShowForm.h"
#include "ui_canDataShowForm.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>
#include <synchapi.h>  //QSleep
#include <QDebug>
#include <usbscan.h>
#define TIMEOUT 3000
#define TESTNUM 50
#define NOT_TT 1
//A2 COM6
//A3 COM5
//A4 COM7
canDataShowForm::canDataShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canDataShowForm)
{
    ui->setupUi(this);
    qRegisterMetaType<UINT>("UINT");
    qRegisterMetaType<BYTE>("BYTE");
    qRegisterMetaType<VCI_CAN_OBJ>("VCI_CAN_OBJ");
    qRegisterMetaType<DWORD>("DWORD");
    qRegisterMetaType<int16_t>("int16_t");

    AutoSendTimer=new QTimer(this);
    connect(AutoSendTimer,&QTimer::timeout,this,&canDataShowForm::on_pushButton_send_clicked);
    StartInit();
    initThreadPool();
    initThreadRS();
#if NOT_TT
    //    ui->groupBox_3->setEnabled(false);
    //    ui->groupBox_4->setEnabled(false);
    //    ui->groupBox_5->setEnabled(false);
    //    ui->groupBox_6->setEnabled(false);
#endif
}
//初始化线程
void canDataShowForm::initThreadPool()
{
    //线程池
    //    _threadMap.clear();
    _pool.setMaxThreadCount(5);
    //    _serialWorkThreadPool_XT_01 = new serialWorkThreadPool_XT_01(0,1);

    //    _serialWorkThreadPool_XT_01->setAutoDelete(true);

    //    _serialWorkThreadPool_XT_02 = new serialWorkThreadPool_XT_02(1,1);

    //    _serialWorkThreadPool_XT_02->setAutoDelete(true);

    _serialWorkThreadPool_LX_603 = new serialWorkThreadPool_LX_603(2,0);

    _serialWorkThreadPool_LX_603->setAutoDelete(true);

    _serialWorkThreadPool_TT_601 = new serialWorkThreadPool_TT_601(3,0);

    _serialWorkThreadPool_TT_601->setAutoDelete(true);

    _serialWorkThreadPool_MT_141 = new serialWorkThreadPool_MT_141(4,0);

    _serialWorkThreadPool_MT_141->setAutoDelete(true);

    //    _serialWorkThreadPool_MT_142 = new serialWorkThreadPool_MT_142(5,1);

    //    _serialWorkThreadPool_MT_142->setAutoDelete(true);

    //    _serialWorkThreadPool_MT_143 = new serialWorkThreadPool_MT_143(6,1);

    //    _serialWorkThreadPool_MT_143->setAutoDelete(true);

    _serialWorkThreadPool_MT_145 = new serialWorkThreadPool_MT_145(7,0);

    _serialWorkThreadPool_MT_145->setAutoDelete(true);

    _serialWorkThreadPool_YK_602 = new serialWorkThreadPool_YK_602(8,0);

    _serialWorkThreadPool_YK_602->setAutoDelete(true);



}
void canDataShowForm::initThreadRS()
{
    /*
 * @brief   :初始化recv线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */
    /*****************************************CAN1***********************************/
    P_canDataRecvThread_CAN1 = new canDataRecvThread(m_DevType,m_DevIndex,0);
    P_ThreadRecv_CAN1 = new QThread;
    P_canDataRecvThread_CAN1->moveToThread(P_ThreadRecv_CAN1);

    connect(P_ThreadRecv_CAN1,SIGNAL(finished()),P_canDataRecvThread_CAN1,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN1,SIGNAL(started()),P_canDataRecvThread_CAN1,SLOT(slotWork()));
    P_ThreadRecv_CAN1->start();
    P_canDataRecvThread_CAN1->startWork();
    connect(P_canDataRecvThread_CAN1,&canDataRecvThread::signalSendRecvData,this,&canDataShowForm::slotRealTimeUpdateMsg);

    /*****************************************CAN2***********************************/
    P_canDataRecvThread_CAN2 = new canDataRecvThread(m_DevType,m_DevIndex,1);
    P_ThreadRecv_CAN2 = new QThread;
    P_canDataRecvThread_CAN2->moveToThread(P_ThreadRecv_CAN2);
    connect(P_ThreadRecv_CAN2,SIGNAL(finished()),P_canDataRecvThread_CAN2,SLOT(deleteLater()));
    connect(P_ThreadRecv_CAN2,SIGNAL(started()),P_canDataRecvThread_CAN2,SLOT(slotWork()));
    P_ThreadRecv_CAN2->start();
    P_canDataRecvThread_CAN2->startWork();

    connect(P_canDataRecvThread_CAN2,&canDataRecvThread::signalSendRecvData,this,&canDataShowForm::slotRealTimeUpdateMsg);

    connect(P_canDataRecvThread_CAN2,&canDataRecvThread::signalSendError,this,&canDataShowForm::slotOpenCan);


    /*****************************************CAN send***********************************/
    P_canDataSendThread = new canDataSendThread();
    P_ThreadSend = new QThread;

    P_canDataSendThread->moveToThread(P_ThreadSend);
    connect(P_ThreadSend,SIGNAL(finished()),P_canDataSendThread,SLOT(deleteLater()));
    connect(P_ThreadSend,SIGNAL(started()),P_canDataSendThread,SLOT(slotWork()));

    //can报文写入线程
    connect(P_canDataRecvThread_CAN1,SIGNAL(signalRecvStatus(bool)),P_canDataSendThread,SLOT(slotRecvStatus(bool)),Qt::DirectConnection);
    connect(P_canDataRecvThread_CAN2,SIGNAL(signalRecvStatus(bool)),P_canDataSendThread,SLOT(slotRecvStatus(bool)),Qt::DirectConnection);

    P_ThreadSend->start();
    P_canDataSendThread->startWork();


}
//释放线程池
void canDataShowForm::releaseThread()
{
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
    qDebug()<<"release pool";
}
void canDataShowForm::startThreadPoll()
{

    initThreadPool();
    //        _serialWorkThreadPool_XT_01->startWork();
    //        _serialWorkThreadPool_XT_02->startWork();
    _serialWorkThreadPool_LX_603->startWork();
//    _serialWorkThreadPool_YK_602->startWork();
    _serialWorkThreadPool_TT_601->startWork();
    _serialWorkThreadPool_MT_141->startWork();
    //        _serialWorkThreadPool_MT_142->startWork();
    //        _serialWorkThreadPool_MT_143->startWork();
    _serialWorkThreadPool_MT_145->startWork();
    //        _pool.start(_serialWorkThreadPool_XT_01);
    //        _pool.start(_serialWorkThreadPool_XT_02);
    _pool.start(_serialWorkThreadPool_LX_603);
//    _pool.start(_serialWorkThreadPool_YK_602);
    _pool.start(_serialWorkThreadPool_TT_601);
    _pool.start(_serialWorkThreadPool_MT_141);
    //        _pool.start(_serialWorkThreadPool_MT_142);
    //        _pool.start(_serialWorkThreadPool_MT_143);
    _pool.start(_serialWorkThreadPool_MT_145);

}
void canDataShowForm::stopThreadPoll()
{
    //    _serialWorkThreadPool_XT_01->stopWork();
    //    _serialWorkThreadPool_XT_02->stopWork();
    _serialWorkThreadPool_LX_603->stopWork();
//    _serialWorkThreadPool_YK_602->stopWork();
    _serialWorkThreadPool_TT_601->stopWork();
    _serialWorkThreadPool_MT_141->stopWork();
    //    _serialWorkThreadPool_MT_142->stopWork();
    //    _serialWorkThreadPool_MT_143->stopWork();
    _serialWorkThreadPool_MT_145->stopWork();
}
/*
 * @brief   : 析构
 * @author  :tanchuang
 * @date    :2023.03.31
 */
canDataShowForm::~canDataShowForm()
{
    if(!_isRelease){
        stopThreadPoll();
    }
    releaseThread();
    delete ui;
}
/**
  *@brief:打开设备，并进行can1和Can2的初始化
  *@param:
  *@author:tc
  *@date:
  */
void canDataShowForm::on_pushButton_open_clicked()
{

    DWORD Reserved=0;
    uchar BaudIndex=static_cast<uchar>(ui->comboBox_baudrate->currentIndex());  //获取波特率选取序号
    //打开设备
    if(VCI_OpenDevice(m_DevType,m_DevIndex,Reserved)!=1)
    {
        qDebug()<<m_DevType<<m_DevIndex;
        QMessageBox::warning(this,tr(""),"open failed");

        return;
    }
    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=Bsp[BaudIndex][0];
    InitInfo->Timing1=Bsp[BaudIndex][1];
    InitInfo->Filter=static_cast<UCHAR>(ui->comboBox_recvDataType->currentIndex()+1); //接收数据类型
    InitInfo->AccCode=0x80000008; //验收码
    //InitInfo->AccCode=0x80000000;
    InitInfo->AccMask=0xFFFFFFFF; //屏蔽码,表示全部接接收l
    InitInfo->Mode=static_cast<UCHAR>(ui->comboBox_work_mode->currentIndex());  //正常模式 工作模式
    //初始化通道can1
    m_CanIndex=static_cast<DWORD>(ui->comboBox_Channel->currentIndex());  //Can1或者Can2
    if(VCI_InitCAN(m_DevType,m_DevIndex,0,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);
        QMessageBox::warning(this,tr(""),"Init-CAN failed!");
        return;
    }
    if(VCI_InitCAN(m_DevType,m_DevIndex,1,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);
        QMessageBox::warning(this,tr(""),"Init-CAN failed!");
        return;
    }
    if(VCI_StartCAN(m_DevType,m_DevIndex,0)!=1)	//
    {
        QMessageBox::warning(this,tr(""),"Start-CAN1 failed!");
        return;
    }
    if(VCI_StartCAN(m_DevType,m_DevIndex,1)!=1)	//
    {
        QMessageBox::warning(this,tr(""),"Start-CAN1 failed!");
        return;
    }
    QMessageBox::warning(this,tr(""),"Open successfule!\n Start CAN OK!");

    startThreadPoll();
    _isRelease = false;

}
/**
  *@brief:按钮发送数据
  *@param:
  *@author:tc
  *@date:
  */
void canDataShowForm::on_pushButton_send_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    bool ok;
    QString sendMsg=ui->lineEdit_frame_date->text();//发送数据
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    sendbuf->ExternFlag=static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf->RemoteFlag=static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
    if((sendbuf->ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf->ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x1FFFFFFF;
    }
    else//标准帧格式
    {
        sendbuf->ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
    }
    sendbuf->SendType=1;
    sendbuf->TimeFlag=0;
    sendbuf->TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf->Data,&sendbuf->DataLen);
    ULONG flag;
    SendCnt++;
    //初始化通道can1
    m_CanIndex=static_cast<DWORD>(ui->comboBox_Channel->currentIndex());  //Can1或者Can2
    flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,sendbuf,1); //调用动态链接库发送函数
    _sleep(10);
    if(flag<1)  //发送不正常
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
        if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
        {   AutoSendTimer->stop();
            ui->checkBox_autoSend->setChecked(false);
        }
    }
    else {
        theModel->appendRow(AddRowSend(sendMsg,sendbuf->DataLen,&RowStr));
        if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
            SaveData2File(file,RowStr);
        }
        //qDebug()<<RowStr;
        ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
    }
}
/**
  *@brief:按钮清除发送
  *@param:
  *@author:tc
  *@date:
  */
void canDataShowForm::on_pushButton_cleanData_clicked()
{
    QStringList lstr;
    lstr<</*QStringLiteral("序号")<<*/QStringLiteral("系统时间")/*<<QStringLiteral("时间标识")*/
       <<QStringLiteral("CAN chanel")<<QStringLiteral("传输方向")<<QStringLiteral("ID号")
      <<QStringLiteral("帧类型")<<QStringLiteral("帧格式")<<QStringLiteral("长度")<<QStringLiteral("数据");

    theModel->clear();
    theModel->setHorizontalHeaderLabels(lstr);
    //    ui->tableView_data->setModel(theModel);
    //    ui->tableView_data->setColumnWidth(0,60);
    //    ui->tableView_data->setColumnWidth(3,70);
    //    ui->tableView_data->setColumnWidth(4,70);
    //    ui->tableView_data->setColumnWidth(9,160); //设置tableView的数据显示列宽
    RecvCnt=0;
    SendCnt=0;
}
/**
  *@brief:按钮关闭设备连接
  *@param:
  *@author:tc
  *@date:
  */
void canDataShowForm::on_pushButton_close_clicked()
{
    //    mtimer->stop();
    AutoSendTimer->stop();
    VCI_ClearBuffer(m_DevType, m_DevIndex, m_CanIndex);//清理接收和发送缓冲器数据
    if(VCI_CloseDevice(m_DevType,m_DevIndex)!=1)
    {
        QMessageBox::warning(this,tr(""),"Close failed！");
        return;
    }
    QMessageBox::warning(this,tr(""),"Close successful!");
    stopThreadPoll();
    _isRelease = true;
}


/**
  *@brief:初始化函数，表格首行数据头显示
  *@param:
  *@date:
  */
void canDataShowForm::StartInit()
{
    theModel=new QStandardItemModel(this);
    ui->tableView_data->verticalHeader()->setVisible(false);

    QStringList lstr;
    lstr<</*QStringLiteral("序号")<<*/QStringLiteral("系统时间")/*<<QStringLiteral("时间标识")*/
       <<QStringLiteral("CAN chanel")<<QStringLiteral("传输方向")<<QStringLiteral("ID号")
      <<QStringLiteral("帧类型")<<QStringLiteral("帧格式")<<QStringLiteral("长度")<<QStringLiteral("数据");
    theModel->setHorizontalHeaderLabels(lstr);
    ui->tableView_data->setModel(theModel);
    ui->tableView_data->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                          "color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");
    //    ui->tableView_data->setColumnWidth(0,60);
    //    ui->tableView_data->setColumnWidth(3,70);
    //    ui->tableView_data->setColumnWidth(4,70);
    //    ui->tableView_data->setColumnWidth(9,160); //设置tableView的数据显示列宽
    ui->tableView_data->scrollToTop();
    ui->tableView_data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->tableView_data->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->lineEdit_frame_id->setText("0602");
    ui->lineEdit_frame_date->setText("");
    ui->lineEdit_Period->setText("1000");
    ui->comboBox_baudrate->setCurrentIndex(13);
    ui->checkBox_canrecv->setChecked(true);
    m_CanIndex=static_cast<DWORD>(ui->comboBox_Channel->currentIndex());  //Can1或者Can2

    m_DevIndex=0;  // 第一个设备

}


/**
  *@brief: 将接收数据信息保存到指定的文件（.txt）
  *@param: failname:文件名
  *@date:
  */
void canDataShowForm::SaveData2File(QFile *file,QString msg)
{
    if(!file->exists())
    {
        ui->label_status->setText(QStringLiteral("文件不存在"));
        return;
    }
    else {
        QTextStream stream(file);
        stream<<msg;
    }
}

double canDataShowForm::GetX()
{
    return timeStamp;
}

/**
  *@brief:增加一行接收信息
  *@param:
  *@date:
  */
QList<QStandardItem*> canDataShowForm::AddRowRecv(PVCI_CAN_OBJ Recv,QString *rowstr,short can)
{
    QList<QStandardItem *> Rowtext;
    QString index=QString::number(RecvCnt);

    QString systime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"); //系统时间
    QString timeStamp=QString::number(QDateTime::currentMSecsSinceEpoch());  //当前毫秒级时间戳
    QString channel=QString("CAN%1").arg(QString::number(can)); //当前can通道（can1或者can2）
    QString direct="Recv"; //接收
    QString id=QString::number(Recv->ID,16).toUpper();  //CanID
    QString type=ui->comboBox_frame_type->currentText();  //帧类型 数据帧 远程帧
    QString format=ui->comboBox_format->currentText(); //帧格式 标准帧 扩展帧
    QString datalen=QString::number(Recv->DataLen,10); //数据长度
    QString data=publicClass::getInstance()->hex2Str(Recv->Data,Recv->DataLen); //数据
    *rowstr=index+":    "+systime+"   "+timeStamp+"   "+channel+"   "+direct+"   "+id+"   "+type+"   "+format+"   "+datalen+"   "+data+"\n";
    QStandardItem *itemmodel = new QStandardItem(direct);
    itemmodel->setForeground(QBrush(QColor(0, 255, 0)));
    Rowtext<</*new QStandardItem(index)<<*/new QStandardItem(systime)<</*new QStandardItem(timeStamp)*/new QStandardItem(channel)
          <<itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
         <<new QStandardItem(datalen)<<new QStandardItem(data);
    return Rowtext;
}
/**
  *@brief:增加一行发送信息
  *@param:
  *@date:
  */
QList<QStandardItem *> canDataShowForm::AddRowSend(QString sendstr,uchar len,QString *rowstr)
{
    QList<QStandardItem *> Rowtext;
    QString index=QString::number(SendCnt);
    QString systime=QDateTime::currentDateTime().toString("hh:mm:ss.zzz"); //系统时间
    QString timeStamp=QString::number(QDateTime::currentMSecsSinceEpoch());  //当前毫秒级时间戳
    QString channel=ui->comboBox_Channel->currentText(); //当前can通道（can1或者can2）
    QString direct="Send"; //接收
    QString id=ui->lineEdit_frame_id->text().toUpper();  //CanID
    QString type=ui->comboBox_frame_type->currentText();  //帧类型 数据帧 远程帧
    QString format=ui->comboBox_format->currentText(); //帧格式  标准帧 扩展帧
    QString datalen=QString::number(len,10); //数据长度
    QString data=sendstr; //数据
    *rowstr=index+":   "+systime+"   "+timeStamp+"   "+channel+"   "+direct+"   "+id+"   "+type+"   "+format+"   "+datalen+"   "+data+"\n";
    QStandardItem *itemmodel = new QStandardItem(direct);
    itemmodel->setForeground(QBrush(QColor(255, 0, 0)));
    Rowtext<</*new QStandardItem(index)<<*/new QStandardItem(systime)<</*new QStandardItem(timeStamp)<<*/new QStandardItem(channel)
          <<itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
         <<new QStandardItem(datalen)<<new QStandardItem(data);
    return Rowtext;
}
/*
 * @brief   : 接收线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */
void  canDataShowForm::slotRealTimeUpdateMsg(/*UINT id, BYTE *data*/VCI_CAN_OBJ *Recv,  DWORD Recv_Len,short can)
{
    if(ui->tableView_data->model()->rowCount()>1000){
        on_pushButton_cleanData_clicked();
    }

    QString RowStr;
    bool IsStartRecv=ui->checkBox_canrecv->isChecked();
    if(IsStartRecv==false) return;
    if(Recv_Len>0)
    {
        for(DWORD i=0;i<Recv_Len;i++){
            RecvCnt+=1;
            VCI_CAN_OBJ obj;
            std::lock_guard<std::mutex> lgd(_mutex);
            memmove(&obj,&Recv[i],sizeof (VCI_CAN_OBJ));
            theModel->appendRow(AddRowRecv(&obj,&RowStr,can));
#if NOT_TT
            emit signalDataToForm(obj.ID, obj.Data);
#else
            emit signalDataToView(Recv[i].ID, Recv[i].Data); //波形更新
            QString datastr = publicClass::getInstance()->Byte_16(Recv[i].Data,8);
            QString ids = datastr.split(" ").at(1) +" "+ datastr.split(" ").at(2);
            QString valuestr = datastr.split(" ").at(4) +" "+ datastr.split(" ").at(5)+" "+ datastr.split(" ").at(6)+" "+ datastr.split(" ").at(7);
            QByteArray array = datastr.toLatin1();
            int16_t index;
            QByteArray byte = QByteArray::fromHex(ids.toLatin1());
            memcpy(&index,byte.data(),byte.size());
            if(index == 12303)//第二位置编码器
            {
                QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
                int32_t value;
                memcpy(&value,valuebyte.data(),valuebyte.size());
                setValue(QString::number(value));
            }
#endif
            //            emit signalRecvId(ids.simplified());//接收到的id
            ui->label_recvNum->setText(QString::number(RecvCnt,10));
            if(ui->checkBox_cansave->isChecked()) //如果勾选了保存实时数据
            {
                SaveData2File(file,RowStr);
            }
            ui->tableView_data->scrollToBottom();  //让滚动条滚动到最底部
            //            ui->tableWidget->scrollToTop();  //让滚动条滚动到最顶部
        }
    }
}

/**
  *@brief:开启和关闭自动定时发送数据
  *@param:checked：true:开启，false：关闭
  *@date:
  */
void canDataShowForm::on_checkBox_autoSend_clicked(bool checked)
{
    int sendPeriod=ui->lineEdit_Period->text().toInt();
    if(checked)
    {
        AutoSendTimer->start(sendPeriod);
    }
    else {
        AutoSendTimer->stop();
    }
}


void canDataShowForm::on_checkBox_canrecv_clicked(bool checked)
{

}
/**
  *@brief:开启和关闭数据存储，文件保存在log文件夹中
  *@param: checked: true:创建文件，false:关闭文件
  *@date:
  */
void canDataShowForm::on_checkBox_cansave_clicked(bool checked)
{
    if(checked==true)
    {
        filename="./log/"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+".txt";
        file=new QFile(filename);
        if(!file->open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("创建文件")+filename+QStringLiteral("失败"));
            return;
        }
    }
    else {
        file->close();
        file->deleteLater();
        filename.clear();
    }
}
void canDataShowForm::slotOpenCan(short canIndex)
{
    VCI_ClearBuffer(m_DevType, m_DevIndex, m_CanIndex);//清理接收和发送缓冲器数据
    //           stopThreadPoll();
    //    if(VCI_CloseDevice(m_DevType,m_DevIndex)!=1)
    //    {
    //        qDebug()<<"reboot can failed";
    //        return;
    //    }

    DWORD Reserved=0;
    uchar BaudIndex=static_cast<uchar>(ui->comboBox_baudrate->currentIndex());  //获取波特率选取序号
    //打开设备
    if(VCI_OpenDevice(m_DevType,m_DevIndex,Reserved)!=1)
    {
        qDebug()<<m_DevType<<m_DevIndex;
        return;
    }
    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=Bsp[BaudIndex][0];
    InitInfo->Timing1=Bsp[BaudIndex][1];
    InitInfo->Filter=static_cast<UCHAR>(ui->comboBox_recvDataType->currentIndex()+1); //接收数据类型
    InitInfo->AccCode=0x80000008; //验收码
    //InitInfo->AccCode=0x80000000;
    InitInfo->AccMask=0xFFFFFFFF; //屏蔽码,表示全部接接收
    InitInfo->Mode=static_cast<UCHAR>(ui->comboBox_work_mode->currentIndex());  //正常模式 工作模式
    //初始化通道can1
    m_CanIndex=static_cast<DWORD>(ui->comboBox_Channel->currentIndex());  //Can1或者Can2
    if(VCI_InitCAN(m_DevType,m_DevIndex,0,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);
        qDebug()<<"Init-CAN failed!";
        return;
    }
    if(VCI_InitCAN(m_DevType,m_DevIndex,1,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);
        qDebug()<<"Init-CAN failed!";
        return;
    }
    if(VCI_StartCAN(m_DevType,m_DevIndex,0)!=1)	//
    {
        qDebug()<<"Start-CAN1 failed!";
        return;
    }
    if(VCI_StartCAN(m_DevType,m_DevIndex,1)!=1)	//
    {
        qDebug()<<"Start-CAN1 failed!";
        return;
    }
    startThreadPoll();
    _isRelease = false;
}
void canDataShowForm::readShareMemary()
{
    //    QString A2 =  publicClass::getInstance()->readValueIni("COM/A2");
    //    _threadPool_A2 = new serialWorkThreadPool_BMQ(A2);
    //    _threadPool_A2->startWork();
    //    _threadPool_A2->setAutoDelete(true);
    //    _poolBmq.start(_threadPool_A2);
    //    //转发编码器数据
    //    connect(_threadPool_A2,&serialWorkThreadPool_BMQ::signalComData,this,&canDataShowForm::signalBmqDataToForm);

    //    QString A3 =  publicClass::getInstance()->readValueIni("COM/A3");
    //    _threadPool_A3 = new serialWorkThreadPool_BMQ(A3);
    //    _threadPool_A3->startWork();
    //    _threadPool_A3->setAutoDelete(true);
    //    _poolBmq.start(_threadPool_A3);
    //    //转发编码器数据
    //    connect(_threadPool_A3,&serialWorkThreadPool_BMQ::signalComData,this,&canDataShowForm::signalBmqDataToForm);

    //    QString A4 =  publicClass::getInstance()->readValueIni("COM/A4");
    //    _threadPool_A4 = new serialWorkThreadPool_BMQ(A4);
    //    _threadPool_A4->startWork();
    //    _threadPool_A4->setAutoDelete(true);
    //    _poolBmq.start(_threadPool_A4);
    //    //转发编码器数据
    //    connect(_threadPool_A4,&serialWorkThreadPool_BMQ::signalComData,this,&canDataShowForm::signalBmqDataToForm);

    //    QString A8 =  publicClass::getInstance()->readValueIni("COM/A8");
    //    _threadPool_A8 = new serialWorkThreadPool_BMQ(A8);
    //    _threadPool_A8->startWork();
    //    _threadPool_A8->setAutoDelete(true);
    //    _poolBmq.start(_threadPool_A8);
    //    //转发编码器数据
    //    connect(_threadPool_A8,&serialWorkThreadPool_BMQ::signalComData,this,&canDataShowForm::signalBmqDataToForm);
}
