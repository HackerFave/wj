#include "canDataShowForm.h"
#include "ui_canDataShowForm.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDateTime>
#include <synchapi.h>  //QSleep
#include <QDebug>
#define TIMEOUT 3000
#define TESTNUM 50
#define NOT_TT 1
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
    _timer = new QTimer(this);
    connect(_timer,&QTimer::timeout,this,&canDataShowForm::slotTimerTest);

    _timer1 = new QTimer(this);
    connect(_timer1,&QTimer::timeout,this,&canDataShowForm::slotTimerTest1);

    _timer2 = new QTimer(this);
    connect(_timer2,&QTimer::timeout,this,&canDataShowForm::slotTimerTest2);
    //    _timer2->start(1000);
    StartInit();
#if NOT_TT
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
    ui->groupBox_6->setEnabled(false);
#endif
}
//初始化线程
void canDataShowForm::initThread()
{
    //线程池
    _threadMap.clear();
    _pool.setMaxThreadCount(5);
    _threadMap[0] = new serialWorkThreadPool(0);
    _threadMap[0]->startWork();
    _threadMap[0]->setAutoDelete(true);

    _threadMap[1] = new serialWorkThreadPool_1(1);
    _threadMap[1]->startWork();
    _threadMap[1]->setAutoDelete(true);

    _threadMap[2] = new serialWorkThreadPool_2(2);
    _threadMap[2]->startWork();
    _threadMap[2]->setAutoDelete(true);

    _threadMap[3] = new serialWorkThreadPool_3(3);
    _threadMap[3]->startWork();
    _threadMap[3]->setAutoDelete(true);

    _threadMap[4] = new serialWorkThreadPool_4(4);
    _threadMap[4]->startWork();
    _threadMap[4]->setAutoDelete(true);

    _pool.start(_threadMap[0]);
    _pool.start(_threadMap[1]);
    _pool.start(_threadMap[2]);
    _pool.start(_threadMap[3]);
    _pool.start(_threadMap[4]);

    /*
 * @brief   :初始化recv线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */
    P_testDataThread = new testDataThread(m_DevType,m_DevIndex,m_CanIndex);
    P_ThreadRecv = new QThread;
    P_testDataThread->moveToThread(P_ThreadRecv);
    connect(P_ThreadRecv,SIGNAL(finished()),P_testDataThread,SLOT(deleteLater()));
    connect(P_ThreadRecv,SIGNAL(started()),P_testDataThread,SLOT(slotWork()));
    P_ThreadRecv->start();
    P_testDataThread->startWork();
    connect(P_testDataThread,&testDataThread::signalSendRecvData,this,&canDataShowForm::slotRealTimeUpdateMsg);

    P_canDataSendThread = new canDataSendThread(m_DevType,m_DevIndex,m_CanIndex);
    P_ThreadSend = new QThread;
    P_canDataSendThread->moveToThread(P_ThreadSend);
    connect(P_ThreadSend,SIGNAL(finished()),P_canDataSendThread,SLOT(deleteLater()));
    connect(P_ThreadSend,SIGNAL(started()),P_canDataSendThread,SLOT(slotWork()));

    //can报文写入线程
        connect(this,SIGNAL(signalSendCanBuf(void *,int)),P_canDataSendThread,SLOT(slotSendCanBuf(void *,int)),Qt::DirectConnection);
    //    connect(this,SIGNAL(signalRecvId(QString)),P_canDataSendThread,SLOT(slotRecvId(QString)),Qt::DirectConnection);

    P_ThreadSend->start();
    P_canDataSendThread->startWork();

}
//释放线程池
void canDataShowForm::releaseThread()
{
    if(!_threadMap.isEmpty()){
        if( _threadMap[0]&&_threadMap[0]->isStart()){
            _threadMap[0]->stopWork();
        }
        if( _threadMap[1]&&_threadMap[1]->isStart()){

            _threadMap[1]->stopWork();
        }
        if( _threadMap[2]&&_threadMap[2]->isStart()){
            _threadMap[2]->stopWork();
        }
        if( _threadMap[3]&&_threadMap[3]->isStart()){
            _threadMap[3]->stopWork();
        }
        if( _threadMap[4]&&_threadMap[4]->isStart()){
            _threadMap[4]->stopWork();
        }
        _threadMap.clear();
    }
    if(P_ThreadRecv){
        P_testDataThread->stopWork();
        P_ThreadRecv->quit();
    }
    if(P_ThreadSend){
        P_canDataSendThread->stopWork();
        P_ThreadSend->quit();
    }
    _pool.releaseThread();
}
/*
 * @brief   : 析构
 * @author  :tanchuang
 * @date    :2023.03.31
 */
canDataShowForm::~canDataShowForm()
{
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
        QMessageBox::warning(this,tr(""),"open failed");
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
    if(VCI_InitCAN(m_DevType,m_DevIndex,m_CanIndex,InitInfo)!=1)	//
    {
        VCI_CloseDevice(m_DevType, m_DevIndex);

        QMessageBox::warning(this,tr(""),"Init-CAN failed!");
        return;
    }
    Sleep(100);
    if(VCI_StartCAN(m_DevType,m_DevIndex,m_CanIndex)!=1)	//
    {
        QMessageBox::warning(this,tr(""),"Start-CAN1 failed!");
        return;
    }
    QMessageBox::warning(this,tr(""),"Open successfule!\n Start CAN OK!");
    publicClass::getInstance()->setValueIni("index/DevIndex",QString::number(m_DevIndex));
    publicClass::getInstance()->setValueIni("index/CanIndex",QString::number(m_CanIndex));

    initThread();

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
    //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
    //           <<"sendMsg"<<sendMsg;
    flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,sendbuf,1); //调用动态链接库发送函数
    //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
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
          /*<<QStringLiteral("CAN chanel")*/<<QStringLiteral("传输方向")<<QStringLiteral("ID号")
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
    releaseThread();
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
          /*<<QStringLiteral("CAN chanel")*/<<QStringLiteral("传输方向")<<QStringLiteral("ID号")
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
    m_DevType=/*VCI_USBCAN2*/publicClass::getInstance()->readValueIni("index/devtype").toUInt();
    m_DevIndex=0;  // 第一个设备

    ui->label_limit->setText(QStringLiteral("角度限制:")+ publicClass::getInstance()->readValueIni("index/limit"));

    ui->lineEdit_0->setText( publicClass::getInstance()->readValueIni("index/limit0"));

    ui->lineEdit_1->setText( publicClass::getInstance()->readValueIni("index/limit1"));

    ui->lineEdit_fu->setText( publicClass::getInstance()->readValueIni("index/limitfu"));

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
QList<QStandardItem*> canDataShowForm::AddRowRecv(PVCI_CAN_OBJ Recv,QString *rowstr)
{
    QList<QStandardItem *> Rowtext;
    QString index=QString::number(RecvCnt);

    QString systime=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"); //系统时间
    QString timeStamp=QString::number(QDateTime::currentMSecsSinceEpoch());  //当前毫秒级时间戳
    QString channel=ui->comboBox_Channel->currentText(); //当前can通道（can1或者can2）
    QString direct="Recv"; //接收
    QString id=QString::number(Recv->ID,16).toUpper();  //CanID
    QString type=ui->comboBox_frame_type->currentText();  //帧类型 数据帧 远程帧
    QString format=ui->comboBox_format->currentText(); //帧格式 标准帧 扩展帧
    QString datalen=QString::number(Recv->DataLen,10); //数据长度
    QString data=publicClass::getInstance()->hex2Str(Recv->Data,Recv->DataLen); //数据
    *rowstr=index+":    "+systime+"   "+timeStamp+"   "+channel+"   "+direct+"   "+id+"   "+type+"   "+format+"   "+datalen+"   "+data+"\n";
    QStandardItem *itemmodel = new QStandardItem(direct);
    itemmodel->setForeground(QBrush(QColor(0, 255, 0)));
    Rowtext<</*new QStandardItem(index)<<*/new QStandardItem(systime)<</*new QStandardItem(timeStamp)<<*//*new QStandardItem(channel)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        <<*/itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
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
    Rowtext<</*new QStandardItem(index)<<*/new QStandardItem(systime)<</*new QStandardItem(timeStamp)<<*//*new QStandardItem(channel)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        <<*/itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
          <<new QStandardItem(datalen)<<new QStandardItem(data);
    return Rowtext;
}
/*
 * @brief   : 接收线程
 * @author  :tanchuang
 * @date    :2023.04.10
 */
void  canDataShowForm::slotRealTimeUpdateMsg(/*UINT id, BYTE *data*/VCI_CAN_OBJ *Recv,  DWORD Recv_Len)
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
            theModel->appendRow(AddRowRecv(&Recv[i],&RowStr));
#if NOT_TT
            emit signalDataToRmdForm(Recv[i].ID, Recv[i].Data);
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
//电机初始化
void canDataShowForm::on_pushButton_init_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    ui->lineEdit_frame_id->setText("02");
    bool ok;
    QString sendMsg="10 10";//发送数据
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    sendbuf->ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf->RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

    if((sendbuf->ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf->ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
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
    //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
    //           <<"sendMsg"<<sendMsg;
    flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,sendbuf,1); //调用动态链接库发送函数
    //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
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

void canDataShowForm::on_pushButton_foreward_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    //    sendMsg.append(QString("2F 60 60 00 03 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 0f 00 00 00"));
    int32_t  ss2 = ui->lineEdit_suduRpm->text().simplified().toInt()*10; //设置速度

    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    QByteArray byArr2((const char*)out2,4);

    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    QString sudu = QString("23 FF 60 00 %1").arg(ssss2);
    sendMsg.append(sudu);

    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<1;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
        if(flag<1)  //发送不正常
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
            if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
            {   AutoSendTimer->stop();
                ui->checkBox_autoSend->setChecked(false);
            }
        }
        else {
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
        }
    }

}

void canDataShowForm::on_pushButton_reversal_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    //    sendMsg.append(QString("2F 60 60 00 03 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 0f 00 00 00"));

    int32_t  ss2 = -ui->lineEdit_suduRpm->text().simplified().toInt()*10; //设置速度

    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    QByteArray byArr2((const char*)out2,4);

    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    QString sudu = QString("23 FF 60 00 %1").arg(ssss2);
    sendMsg.append(sudu);
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<1;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
        if(flag<1)  //发送不正常
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
            if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
            {   AutoSendTimer->stop();
                ui->checkBox_autoSend->setChecked(false);
            }
        }
        else {
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
        }
    }

}
/*
 * @brief   :速度模式使能
 * @author  :tanchuang
 * @date    :2023.04.04
 */
void canDataShowForm::on_pushButton_enable_clicked()
{
    VCI_CAN_OBJ sendbuf[5];
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 60 60 00 03 00 00 00"));//速度模式
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0f 00 00 00"));
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<5;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
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
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
        }
    }
}
//停止使能
void canDataShowForm::on_pushButton_stopEnable_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2B 40 60 00 02 00 00 00"));
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    sendbuf->ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf->RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

    if((sendbuf->ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf->ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
    }
    else//标准帧格式
    {
        sendbuf->ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
    }

    sendbuf->SendType=1;
    sendbuf->TimeFlag=0;
    sendbuf->TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg[0],sendbuf->Data,&sendbuf->DataLen);
    ULONG flag;
    SendCnt++;
    //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
    //           <<"sendMsg"<<sendMsg;
    flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,sendbuf,1); //调用动态链接库发送函数
    //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
    if(flag<1)  //发送不正常
    {
        QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
        if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
        {   AutoSendTimer->stop();
            ui->checkBox_autoSend->setChecked(false);
        }
    }
    else {
        theModel->appendRow(AddRowSend(sendMsg[0],sendbuf->DataLen,&RowStr));
        if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
            SaveData2File(file,RowStr);
        }
        ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
    }


}

/*
 * @brief   :原点定位
 * @author  :tanchuang
 * @date    :2023.04.04
 */
void canDataShowForm::on_pushButton_setyuandian_clicked()
{
    VCI_CAN_OBJ sendbuf[7];
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 98 60 00 23 00 00 00"));//速度模式
    sendMsg.append(QString("2F 60 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

    //    sendMsg.append(QString("23 FF 60 00 E8 03 00 00"));
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<7;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
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
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
        }
    }
}

void canDataShowForm::on_pushButton_enable_weizhimoshi_clicked()
{


    int num =  publicClass::getInstance()->readValueIni("index/limit").toInt();

    if(ui->comboBox_xiangduiweizhi->currentIndex()==0){
        VCI_CAN_OBJ sendbuf[10];
        bool ok;
        ui->lineEdit_frame_id->setText("602");
        QList<QString>   sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//相对位置模式


        int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
        unsigned char out[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
        QByteArray byArr((const char*)out,4);
        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
        sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms


        int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
        unsigned char out1[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
        QByteArray byArr1((const char*)out1,4);
        QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);
        sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms
        int32_t  ssangle = 0;

#if LIMIT
        
        if(abs(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())>num){

            //            if(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt()>0){
            //                ssangle = (32768*101* num)/360; //设置角度
            //            }
            //            else {
            //                ssangle = (32768*101* (-num))/360; //设置角度
            //            }
            QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前角度超过限位"));
            return;
        }
        else {
            ssangle = (32768*101* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())/360; //设置角度
        }

#else
        ssangle = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
#endif
        unsigned char outangle[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
        QByteArray byArrangle((const char*)outangle,4);

        QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

        QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
        sendMsg.append(jiaodu);//设置转动角度

        int32_t  ss2 =  ui->lineEdit_weizhiRpm->text().simplified().toInt()*10;
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);


        sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));

        QString RowStr;
        if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
        {
            QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
            ui->checkBox_autoSend->setChecked(false);
            AutoSendTimer->stop();
            return;
        }
        for(int i=0;i<10;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            SendCnt++;
            //            qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
            //                   <<"sendMsg"<<sendMsg;
            flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
                if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
                {   AutoSendTimer->stop();
                    ui->checkBox_autoSend->setChecked(false);
                }
                return;
            }
            else {
                theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
                if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                    SaveData2File(file,RowStr);
                }
                ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
            }
        }
    }
    else {
        VCI_CAN_OBJ sendbuf[10];
        bool ok;
        ui->lineEdit_frame_id->setText("602");
        QList<QString>   sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式

        int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
        unsigned char out[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
        QByteArray byArr((const char*)out,4);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);

        sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms

        int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
        unsigned char out1[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
        QByteArray byArr1((const char*)out1,4);

        QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);


        sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms

        //        sendMsg.append(QString("23 7A 60 00 10 27 00 00"));//设置目标位置 一圈32768 除以减速比1/101

        //        sendMsg.append(QString("23 7A 60 00 00 00 00 00"));//设置转动角度

        int32_t  ssangle = 0;

#if LIMIT
        if(abs(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())>num){

            //            if(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt()>0){
            //                ssangle = (32768*101* num)/360; //设置角度
            //            }
            //            else {
            //                ssangle = (32768*101* (-num))/360; //设置角度
            //            }
            QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前角度超过限位"));
            return;
        }
        else {
            ssangle = (32768*101* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())/360; //设置角度
        }

#else
        ssangle = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
#endif
        unsigned char outangle[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
        QByteArray byArrangle((const char*)outangle,4);

        QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

        QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
        sendMsg.append(jiaodu);//设置转动角度

        int32_t  ss2 =  ui->lineEdit_weizhiRpm->text().simplified().toInt()*10;
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
        sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

        QString RowStr;
        if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
        {
            QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
            ui->checkBox_autoSend->setChecked(false);
            AutoSendTimer->stop();
            return;
        }
        for(int i=0;i<10;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            SendCnt++;
            //            qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
            //                   <<"sendMsg"<<sendMsg;
            flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));

            _sleep(10);
            if(flag<1)  //发送不正常
            {
                QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
                if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
                {   AutoSendTimer->stop();
                    ui->checkBox_autoSend->setChecked(false);
                }
                return;
            }
            else {
                theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
                if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                    SaveData2File(file,RowStr);
                }
                ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数
            }
        }
    }

}

void canDataShowForm::on_pushButton_zhuandong_clicked()
{


    if(ui->comboBox_xiangduiweizhi->currentIndex()==0){ // 相对位置
        VCI_CAN_OBJ sendbuf[3];
        bool ok;
        QString id = "602";
        QList<QString>   sendMsg;
        sendMsg.clear();
        int32_t  ss2 = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
        //        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//相对位置模式
        QString jiaodu = QString("23 7A 60 00 %1").arg(ssss2);
        sendMsg.append(jiaodu);//设置转动角度
        //        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));
        for(int i=0;i<3;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }

    }
    else{//绝对位置
        VCI_CAN_OBJ sendbuf[3];
        bool ok;
        QString id = "602";
        QList<QString>  sendMsg;
        sendMsg.clear();
        int32_t  ss2 = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);

        //        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式
        QString jiaodu = QString("23 7A 60 00 %1").arg(ssss2);
        sendMsg.append(jiaodu);//设置转动角度
        //        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

        for(int i=0;i<3;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
    }

}
//记录0点
void canDataShowForm::on_pushButton_clicked()
{
    publicClass::getInstance()->setValueIni("index/limit0",getValue());
    ui->lineEdit_0->setText( publicClass::getInstance()->readValueIni("index/limit0"));
}

void canDataShowForm::on_pushButton_2_clicked()
{
    publicClass::getInstance()->setValueIni("index/limit1",getValue());
    ui->lineEdit_1->setText( publicClass::getInstance()->readValueIni("index/limit1"));
}

void canDataShowForm::on_pushButton_3_clicked()
{
    publicClass::getInstance()->setValueIni("index/limitfu",getValue());
    ui->lineEdit_fu->setText( publicClass::getInstance()->readValueIni("index/limitfu"));
}
void canDataShowForm::slotTimerTest()
{
    VCI_CAN_OBJ sendbuf[3]={};
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>  sendMsg;
    sendMsg.clear();
    //    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式

    //    int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
    //    unsigned char out[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
    //    QByteArray byArr((const char*)out,4);

    //    QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);

    //    sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms

    //    int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
    //    unsigned char out1[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
    //    QByteArray byArr1((const char*)out1,4);

    //    QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);


    //    sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms

    //        sendMsg.append(QString("23 7A 60 00 10 27 00 00"));//设置目标位置 一圈32768 除以减速比1/101

    //        sendMsg.append(QString("23 7A 60 00 00 00 00 00"));//设置转动角度

    int32_t  ssangle = 0;
    ssangle = (32768*101*8)/360; //设置角度
    _lastDirection = 1;
    unsigned char outangle[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
    QByteArray byArrangle((const char*)outangle,4);

    QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

    QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
    sendMsg.append(jiaodu);//设置转动角度

    //    int32_t  ss2 =  400*10;
    //    unsigned char out2[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    //    QByteArray byArr2((const char*)out2,4);

    //    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    //    sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
    //    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

    //    qDebug()<<sendMsg.size()<<"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK";
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<3;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));


        _sleep(10);
        if(flag<1)  //发送不正常
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
            if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
            {   AutoSendTimer->stop();
                ui->checkBox_autoSend->setChecked(false);
            }
            return;
        }
        else {
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数

        }
    }
    _timer->stop();
    _timer1->start(TIMEOUT);
    _testNum ++;
    if(_testNum == TESTNUM){
        _timer->stop();
        _timer1->stop();
        _sleep(3000);
        //        on_pushButton_STOP_clicked();
        //        _sleep(2000);
        //        _timer2->stop();
        //        slotTimerTest2();
        //        _sleep(2000);
        on_pushButton_STOP_clicked();
    }
}
void canDataShowForm::slotTimerTest1()
{
    VCI_CAN_OBJ sendbuf[3]={};
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    //    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式

    //    int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
    //    unsigned char out[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
    //    QByteArray byArr((const char*)out,4);

    //    QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);

    //    sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms

    //    int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
    //    unsigned char out1[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
    //    QByteArray byArr1((const char*)out1,4);

    //    QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);


    //    sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms

    //        sendMsg.append(QString("23 7A 60 00 10 27 00 00"));//设置目标位置 一圈32768 除以减速比1/101

    //        sendMsg.append(QString("23 7A 60 00 00 00 00 00"));//设置转动角度

    int32_t  ssangle = 0;

    ssangle = (32768*101* (-8))/360; //设置角度

    _lastDirection = -1;
    //        qDebug()<<ssangle<<"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
    //                   <<ui->lineEdit_zhuandongjiaodu->text().simplified().toInt();
    unsigned char outangle[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
    QByteArray byArrangle((const char*)outangle,4);

    QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

    QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
    sendMsg.append(jiaodu);//设置转动角度

    //    int32_t  ss2 =  400*10;
    //    unsigned char out2[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    //    QByteArray byArr2((const char*)out2,4);

    //    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    //    sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
    //    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));
    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<3;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));


        _sleep(10);
        if(flag<1)  //发送不正常
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
            if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
            {   AutoSendTimer->stop();
                ui->checkBox_autoSend->setChecked(false);
            }
            return;
        }
        else {
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数

        }
    }
    _timer1->stop();
    _timer->start(TIMEOUT);
    _testNum ++;
    if(_testNum == TESTNUM){
        _timer->stop();
        _timer1->stop();
        _sleep(3000);
        //        on_pushButton_STOP_clicked();
        //        _sleep(2000);
        //        _timer2->stop();
        //        slotTimerTest2();
        //        _sleep(2000);
        on_pushButton_STOP_clicked();
    }
}
void canDataShowForm::on_pushButton_test_clicked()
{
    _timer->start(TIMEOUT);

}

void canDataShowForm::on_pushButton_STOP_clicked()
{
    _timer->stop();
    _timer1->stop();
    VCI_CAN_OBJ sendbuf[3]={};
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
    QByteArray byArr((const char*)out,4);

    QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
    int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
    QByteArray byArr1((const char*)out1,4);

    QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);

    int32_t  ssangle = 0;
    ssangle = (32768*101* 0)/360; //设置角度
    unsigned char outangle[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
    QByteArray byArrangle((const char*)outangle,4);
    QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);
    QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
    sendMsg.append(jiaodu);//设置转动角度
    sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<3;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //        emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));

        _sleep(10);
        if(flag<1)  //发送不正常
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
            if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
            {   AutoSendTimer->stop();
                ui->checkBox_autoSend->setChecked(false);
            }
            return;
        }
        else {
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数

        }
    }
    _testNum = 0;
}
void canDataShowForm::test()
{

}

void canDataShowForm::on_pushButton_4_clicked()
{

}

void canDataShowForm::slotTimerTest2()
{
    VCI_CAN_OBJ sendbuf[10];
    bool ok;
    ui->lineEdit_frame_id->setText("602");
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式

    int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
    QByteArray byArr((const char*)out,4);

    QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);

    sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms

    int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
    QByteArray byArr1((const char*)out1,4);

    QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);


    sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms

    //        sendMsg.append(QString("23 7A 60 00 10 27 00 00"));//设置目标位置 一圈32768 除以减速比1/101

    //        sendMsg.append(QString("23 7A 60 00 00 00 00 00"));//设置转动角度

    int32_t  ssangle = 0;
    if(_lastDirection==1){
        ssangle = (32768*101* (-6))/360; //设置角度
    }
    else if(_lastDirection==-1){
        ssangle = (32768*101* 6)/360; //设置角度
    }
    unsigned char outangle[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
    QByteArray byArrangle((const char*)outangle,4);

    QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

    QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
    sendMsg.append(jiaodu);//设置转动角度

    int32_t  ss2 =  600*10;
    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    QByteArray byArr2((const char*)out2,4);

    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

    QString RowStr;
    if(ui->comboBox_work_mode->currentIndex()==1)//"只听模式"
    {
        QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前为只听模式"));
        ui->checkBox_autoSend->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    for(int i=0;i<10;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(ui->lineEdit_frame_id->text().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(ui->lineEdit_frame_id->text().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        SendCnt++;
        //        qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
        //               <<"sendMsg"<<sendMsg;
        flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&sendbuf[i],1); //调用动态链接库发送函数
        //                emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            QMessageBox::warning(this,QStringLiteral("警告"),QStringLiteral("发送失败\n"));
            if(ui->checkBox_autoSend->isChecked())  //关闭自动发送
            {   AutoSendTimer->stop();
                ui->checkBox_autoSend->setChecked(false);
            }
            return;
        }
        else {
            theModel->appendRow(AddRowSend(sendMsg[i],sendbuf[i].DataLen,&RowStr));
            if(ui->checkBox_cansave->isChecked()){ //如果勾选了保存实时数据
                SaveData2File(file,RowStr);
            }
            ui->label_sendNum->setText(QString::number(SendCnt,10)); // 显示发送计数

        }
    }

}
