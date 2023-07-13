#include "start.h"
#include "ui_start.h"
#include <QMessageBox>

#include <QTextStream>
#include <QDateTime>
#include <synchapi.h>  //QSleep
#include <QDebug>


start::start(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
   // this->setMaximumSize(800,600);
    SendCntlab=new QLabel(QStringLiteral("发送计数:"));
    RecvCntlab=new QLabel(QStringLiteral("接收计数:"));
    SendCntlab->setMinimumWidth(400);
    RecvCntlab->setMinimumWidth(400);
    ui->statusBar->addWidget(SendCntlab);
    ui->statusBar->addWidget(RecvCntlab);
    mtimer=new QTimer(this);
    AutoSendTimer=new QTimer(this);
    connect(mtimer,&QTimer::timeout,this,&start::RealTimeUpdateMsg);
    connect(AutoSendTimer,&QTimer::timeout,this,&start::on_Send_Btn_clicked);
    StartInit();
    //----------------波形相关设置-------------------//
    auto graph =ui->plot1->addGraph();

    graphMap["current"] =graph;//电流
    graph->setName("current");//电流
    graph->setPen(QPen(QColor(255,0,0)));

    graph =ui->plot1->addGraph();
    graphMap["voltage"] =graph;//电压
    graph->setName("voltage");
    graph->setPen(QPen(QColor(0,255,0)));

    graph =ui->plot1->addGraph();
    graphMap["speed"] =graph;//转速
    graph->setName("speed");//转速
    graph->setPen(QPen(QColor(0,0,255)));

    ui->plot1->xAxis->setRange(0,100);
    ui->plot1->yAxis->setRange(-1,3);
    ui->plot1->axisRect()->setupFullAxesBox(true);
    ui->plot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->plot1->legend->setVisible(true);
    ui->plot1->legend->setIconSize(QSize(100,20));

    ui->checkBox_Rpm->setChecked(true);
    ui->checkBox_Volt->setChecked(true);
    ui->checkBox_Current->setChecked(true);
}

start::~start()
{
    delete ui;
}

/**
  *@brief:初始化函数，表格首行数据头显示
  *@param:
  *@date:
  */
void start::StartInit()
{
    theModel=new QStandardItemModel(this);
    QStringList lstr;
    lstr<<QStringLiteral("序号")<<QStringLiteral("系统时间")<<QStringLiteral("时间标识")
       <<QStringLiteral("CAN chanel")<<QStringLiteral("传输方向")<<QStringLiteral("ID号")
      <<QStringLiteral("帧类型")<<QStringLiteral("帧格式")<<QStringLiteral("长度")<<QStringLiteral("数据");
    theModel->setHorizontalHeaderLabels(lstr);  
    ui->RecvText->setModel(theModel);
    ui->RecvText->setColumnWidth(0,60);
    ui->RecvText->setColumnWidth(3,70);
    ui->RecvText->setColumnWidth(4,70);
    ui->RecvText->setColumnWidth(9,160); //设置tableView的数据显示列宽

    ui->FrameId_LineE->setText("0232");
    ui->SendData_Text->setText("11 22 33 44 55 66 77 88");
    ui->SendPeriod_LineE->setText("1000");
    ui->BaudRate_ComB->setCurrentIndex(13);
    ui->CanRecv_Chek->setChecked(true);
    m_CanIndex=static_cast<DWORD>(ui->CanIndex_ComB->currentIndex());  //Can1或者Can2
    m_DevType=VCI_USBCAN2;
    m_DevIndex=0;  // 第一个设备
}
/*************************************************内部调用函数************************************************************/

//16进制数据转字符串形式，数据间插入空格
QString start::hex2Str(unsigned char *in, int len)
{
    QString s;
    for(int i=0;i<len;i++)
    {
        s+=QString("%1").arg(in[i]&0xFF,2,16,QLatin1Char('0')).toUpper();
        s.append(" ");
    }
    return s;
}
//16进制转float
float start::hex2Float(unsigned char *m)
{
    union{
        unsigned char data[4];
        float num;
   }v_type;
  // memcpy(v_type.data,m,4);
   v_type.data[0]=m[3];
   v_type.data[1]=m[2];
   v_type.data[2]=m[1];
   v_type.data[3]=m[0];
   return v_type.num;
}

//16进制转浮点型字符串格式
QString start::hex2StrFloat(unsigned char *m)
{
     union{
         unsigned char data[4];
         float num;
    }v_type;
   // memcpy(v_type.data,m,4);
    v_type.data[0]=m[3];
    v_type.data[1]=m[2];
    v_type.data[2]=m[1];
    v_type.data[3]=m[0];
    return QString("%1").arg(static_cast<double>(v_type.num),0,'f');
}
/**
  *@brief:将发送框里面的字符串s去除空格，保存到*C,并反馈出数据的长度到len
  *@param:
  *@date:
  */
void start::Str2CharSplitBlank(QString s, uchar *c,uchar *len)
{
    bool ok;
    QStringList lstr=s.split(" ");
    *len =static_cast<uchar>(lstr.length());
    if(*len!=0){
        for(int i=0;i<*len;i++)
        {
             c[i]=static_cast<unsigned char>(lstr[i].toInt(&ok,16));
        }
    }
}

/**
  *@brief: 将接收数据信息保存到指定的文件（.txt）
  *@param: failname:文件名
  *@date:
  */
void start::SaveData2File(QFile *file,QString msg)
{
    if(!file->exists())
    {
        QMessageBox::warning(this,"警告",QStringLiteral("文件不存在"));
        return;
    }
    else {
        QTextStream stream(file);
        stream<<msg;
    }
}

double start::GetX()
{
    return timeStamp;
}

/**
  *@brief:增加一行接收信息
  *@param:
  *@date:
  */
QList<QStandardItem*> start::AddRowRecv(PVCI_CAN_OBJ Recv,QString *rowstr)
{
    QList<QStandardItem *> Rowtext;
    QString index=QString::number(RecvCnt);

    QString systime=QDateTime::currentDateTime().toString("hh:mm:ss.zzz"); //系统时间
    QString timeStamp=QString::number(QDateTime::currentMSecsSinceEpoch());  //当前毫秒级时间戳
    QString channel=ui->CanIndex_ComB->currentText(); //当前can通道（can1或者can2）
    QString direct="Recv"; //接收
    QString id=QString::number(Recv->ID,16).toUpper();  //CanID
    QString type=ui->FrameType_ComB->currentText();  //帧类型
    QString format=ui->FrameFormt_ComB->currentText(); //帧格式
    QString datalen=QString::number(Recv->DataLen,10); //数据长度
    QString data=hex2Str(Recv->Data,Recv->DataLen); //数据
    *rowstr=index+":    "+systime+"   "+timeStamp+"   "+channel+"   "+direct+"   "+id+"   "+type+"   "+format+"   "+datalen+"   "+data+"\n";
     QStandardItem *itemmodel = new QStandardItem(direct);
     itemmodel->setForeground(QBrush(QColor(0, 255, 0)));
    Rowtext<<new QStandardItem(index)<<new QStandardItem(systime)<<new QStandardItem(timeStamp)<<new QStandardItem(channel)
           <<itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
           <<new QStandardItem(datalen)<<new QStandardItem(data);
    return Rowtext;
}
/**
  *@brief:增加一行发送信息
  *@param:
  *@date:
  */
QList<QStandardItem *> start::AddRowSend(QString sendstr,uchar len,QString *rowstr)
{
    QList<QStandardItem *> Rowtext;
    QString index=QString::number(SendCnt);
    QString systime=QDateTime::currentDateTime().toString("hh:mm:ss.zzz"); //系统时间
    QString timeStamp=QString::number(QDateTime::currentMSecsSinceEpoch());  //当前毫秒级时间戳
    QString channel=ui->CanIndex_ComB->currentText(); //当前can通道（can1或者can2）
    QString direct="Send"; //接收
    QString id=ui->FrameId_LineE->text().toUpper();  //CanID
    QString type=ui->FrameType_ComB->currentText();  //帧类型
    QString format=ui->FrameFormt_ComB->currentText(); //帧格式
    QString datalen=QString::number(len,10); //数据长度
    QString data=sendstr; //数据
    *rowstr=index+":   "+systime+"   "+timeStamp+"   "+channel+"   "+direct+"   "+id+"   "+type+"   "+format+"   "+datalen+"   "+data+"\n";
    QStandardItem *itemmodel = new QStandardItem(direct);
    itemmodel->setForeground(QBrush(QColor(255, 0, 0)));
    Rowtext<<new QStandardItem(index)<<new QStandardItem(systime)<<new QStandardItem(timeStamp)<<new QStandardItem(channel)
           <<itemmodel<<new QStandardItem(id)<<new QStandardItem(type)<<new QStandardItem(format)
           <<new QStandardItem(datalen)<<new QStandardItem(data);
    return Rowtext;
}

/*************************************************UI控件执行函数***************************************************/
/**
  *@brief:打开设备，并进行can1和Can2的初始化
  *@param:
  *@author:Mr H
  *@date:
  */
void start::on_OpenDev_Btn_clicked()
{
    DWORD Reserved=0;
    uchar BaudIndex=static_cast<uchar>(ui->BaudRate_ComB->currentIndex());  //获取波特率选取序号
    //打开设备
    if(VCI_OpenDevice(m_DevType,m_DevIndex,Reserved)!=1)
    {
        QMessageBox::warning(this,tr(""),"open failed");
        return;
    }
    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=Bsp[BaudIndex][0];
    InitInfo->Timing1=Bsp[BaudIndex][1];
    InitInfo->Filter=static_cast<UCHAR>(ui->filterMod->currentIndex()+1);
    InitInfo->AccCode=0x80000008; //验收码
    //InitInfo->AccCode=0x80000000;
    InitInfo->AccMask=0xFFFFFFFF; //屏蔽码,表示全部接接收
    InitInfo->Mode=static_cast<UCHAR>(ui->WorkMode_ComB->currentIndex());  //正常模式
    //初始化通道can1
    m_CanIndex=static_cast<DWORD>(ui->CanIndex_ComB->currentIndex());  //Can1或者Can2
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
//    //初始化通道can2
//    if(VCI_InitCAN(m_DevType,m_DevIndex,1,InitInfo)!=1)	//can1
//    {
//        VCI_CloseDevice(m_DevType, m_DevIndex);
//        QMessageBox::warning(this,tr(""),"Init-CAN1 failed!");
//        return;
//    }
//    Sleep(100);
//    if(VCI_StartCAN(m_DevType,m_DevIndex,1)!=1)	//can2
//    {
//        QMessageBox::warning(this,tr(""),"Start-CAN2 failed!");
//        return;
//    }
//    Sleep(100);
    QMessageBox::warning(this,tr(""),"Open successfule!\n Start CAN OK!");
    mtimer->start(30); //30ms
}
/**
  *@brief:按钮关闭设备连接
  *@param:
  *@author:Mr H
  *@date:
  */
void start::on_CloseDev_Btn_clicked()
{  
   mtimer->stop();
   AutoSendTimer->stop();
   VCI_ClearBuffer(m_DevType, m_DevIndex, m_CanIndex);//清理接收和发送缓冲器数据
   if(VCI_CloseDevice(m_DevType,m_DevIndex)!=1)
   {
       QMessageBox::warning(this,tr(""),"Close failed！");
       return;
   }
   QMessageBox::warning(this,tr(""),"Close successful!");
}
/**
  *@brief:按钮发送数据
  *@param:
  *@author:Mr H
  *@date:
  */
void start::on_Send_Btn_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    bool ok;
    QString sendMsg=ui->SendData_Text->text();//发送数据
    QString RowStr;
    if(ui->WorkMode_ComB->currentIndex()/*currentText()*/==1)//"只听模式"
    {
        QMessageBox::warning(this,"注意!","当前为只听模式");
        ui->AutoSend_Chek->setChecked(false);
        AutoSendTimer->stop();
        return;
    }
    sendbuf->ExternFlag=static_cast<BYTE>(ui->FrameFormt_ComB->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf->RemoteFlag=static_cast<BYTE>(ui->FrameType_ComB->currentIndex());  //帧类型 （数据帧0 远程帧1）
    if((sendbuf->ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf->ID =(ui->FrameId_LineE->text().toUInt(&ok,16)); //&0x1FFFFFFF;
      qDebug()<<"sendID:"<<sendbuf->ID<<endl;
    }
    else//标准帧格式
    {     
        sendbuf->ID=(ui->FrameId_LineE->text().toUInt(&ok,16))&0x7FF;
        qDebug()<<"sendID:"<<sendbuf->ID<<endl;
    }
    sendbuf->SendType=1;
    sendbuf->TimeFlag=0;
    sendbuf->TimeStamp=0;
    Str2CharSplitBlank(sendMsg,sendbuf->Data,&sendbuf->DataLen);
    ULONG flag;
    SendCnt++;
    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
           <<"sendMsg"<<sendMsg;
    flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,sendbuf,1); //调用动态链接库发送函数
    qDebug()<<flag;
    if(flag<1)  //发送不正常
    {
        QMessageBox::warning(this,"警告","发送失败\n");
        if(ui->AutoSend_Chek->isChecked())  //关闭自动发送
        {   AutoSendTimer->stop();
            ui->AutoSend_Chek->setChecked(false);
        }
    }
    else {
        theModel->appendRow(AddRowSend(sendMsg,sendbuf->DataLen,&RowStr));
        if(ui->RealStore_Chek->isChecked()){ //如果勾选了保存实时数据
            SaveData2File(file,RowStr);
          }
        //qDebug()<<RowStr;
        SendCntlab->setText(QStringLiteral("发送计数:")+QString::number(SendCnt,10)); // 显示发送计数
    }
}
/**
  *@brief:按钮清除发送
  *@param:
  *@author:Mr H
  *@date:
  */
void start::on_clear_Btn_clicked()
{
    QStringList lstr;
    lstr<<QStringLiteral("序号")<<QStringLiteral("系统时间")<<QStringLiteral("时间标识")
       <<QStringLiteral("CAN chanel")<<QStringLiteral("传输方向")<<QStringLiteral("ID号")
      <<QStringLiteral("帧类型")<<QStringLiteral("帧格式")<<QStringLiteral("长度")<<QStringLiteral("数据");

    theModel->clear();
    theModel->setHorizontalHeaderLabels(lstr);
    ui->RecvText->setModel(theModel);
    ui->RecvText->setColumnWidth(0,60);
    ui->RecvText->setColumnWidth(3,70);
    ui->RecvText->setColumnWidth(4,70);
    ui->RecvText->setColumnWidth(9,160); //设置tableView的数据显示列宽
    RecvCnt=0;
    SendCnt=0;
}
/**
  *@brief:开启和关闭数据存储，文件保存在log文件夹中
  *@param: checked: true:创建文件，false:关闭文件
  *@date:
  */
void start::on_RealStore_Chek_clicked(bool checked)
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
/**
  *@brief:开启和关闭自动定时发送数据
  *@param:checked：true:开启，false：关闭
  *@date:
  */
void start::on_AutoSend_Chek_clicked(bool checked)
{
    int sendPeriod=ui->SendPeriod_LineE->text().toInt();
    if(checked)
    {
        AutoSendTimer->start(sendPeriod);
    }
    else {
        AutoSendTimer->stop();
    }
}

/*********************************************************执行函数******************************************************/
/**
  *@brief:30ms实时更新接收数据，定时读取设备缓存数据，
  *@param:
  *@author:Mr H
  *@date:
  */
void start::RealTimeUpdateMsg()
{
    VCI_CAN_OBJ Recv[2500];
    DWORD Recv_Len;
    QString RowStr;
    bool IsStartRecv=ui->CanRecv_Chek->isChecked();
    timeStamp+=0.03; //30ms更新一次
    if(IsStartRecv==false) return;  
    Recv_Len=VCI_Receive(m_DevType, m_DevIndex,m_CanIndex,Recv,2500,0);
   // qDebug()<<Recv_Len;
    if(Recv_Len>0)
    {

        for(DWORD i=0;i<Recv_Len;i++){
            RecvCnt+=1;
            theModel->appendRow(AddRowRecv(&Recv[i],&RowStr));
            PlotViewUpdate(Recv[i].ID, Recv[i].Data); //波形更新
            RecvCntlab->setText(QStringLiteral("接收计数:")+QString::number(RecvCnt,10));
            if(ui->RealStore_Chek->isChecked()) //如果勾选了保存实时数据
            {
                SaveData2File(file,RowStr);
            }
        }      
    }
}
//实时更新波形数据（注意：此处节点信息波形只做示范例子，具体要显示的内容根据自己测试内容仿照修改）
void start::PlotViewUpdate(UINT id, BYTE *data)
{
    switch(id)
    {
    case 0x0308:
        ui->label_Current->setText(QString("电流:%1A").arg(hex2StrFloat(data)));
        graphMap["current"]->addData(GetX(),hex2Float(data));
        ui->plot1->replot();
        break;
    case 0x050C:
        ui->label_Volt->setText(QString("电压:%1V").arg(hex2StrFloat(data)));
        ui->label_Rpm->setText(QString("转速:%1").arg(data[4]<<8|data[5]));
        graphMap["voltage"]->addData(GetX(),hex2Float(data));
        graphMap["speed"]->addData(GetX(),data[4]<<8|data[5]);
        ui->plot1->replot();
        break;

    default:
        break;
  }
}
//波形打开或隐藏
void start::on_checkBox_Rpm_clicked(bool checked)
{
    graphMap["speed"]->setVisible(checked);
}
//波形打开或隐藏
void start::on_checkBox_Volt_clicked(bool checked)
{
     graphMap["voltage"]->setVisible(checked);
}
//波形打开或隐藏
void start::on_checkBox_Current_clicked(bool checked)
{
     graphMap["current"]->setVisible(checked);
}
