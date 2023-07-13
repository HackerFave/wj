#include "datashowform.h"
#include "ui_datashowform.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include <QProcess>
#include <QMetaType>
#include <QFile>
#include <QDateTime>
#define TEST_GKJ 0
dataShowForm* dataShowForm::p_dataShowForm = nullptr;
dataShowForm::dataShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataShowForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏
    p_dataShowForm = this;
    qInstallMessageHandler(logOutput);
    //    ui->groupBox_2->setVisible(false);
    //    ui->groupBox_3->setVisible(false);
    //    ui->groupBox->setVisible(false);
    //    ui->textEdit_recv->setVisible(false);
    //        ui->pushButton_close->setVisible(false);
    ui->pushButton_stop->setVisible(false);
    ui->pushButton_reboot->setVisible(false);
    ui->pushButton_close->setVisible(false);
    ui->pushButton_run->setVisible(false);
    ui->textEdit_recv->document()->setMaximumBlockCount(500);
    _minbmq = (publicClass::getInstance()->readValueIni("MIN/duo").toInt()+1)*524287+publicClass::getInstance()->readValueIni("MIN/dan").toInt();
    _maxbmq = (publicClass::getInstance()->readValueIni("MAX/duo").toInt()-1)*524287+publicClass::getInstance()->readValueIni("MAX/dan").toInt();
    qRegisterMetaType<int32_t>("int32_t");
    P_func = new func;
    connect(&_timer,&QTimer::timeout,this,&dataShowForm::slotTimer);
    _time.setHMS(0,0,0,0);
    ui->label_time->setText("00:00:00:000");
//        connect(P_func,&func::signalBmq,this,&dataShowForm::slotBmq);
    connect(P_func,&func::signalBmqError,this,&dataShowForm::slotBmqError);
    //    connect(&_timerNum,&QTimer::timeout,this,&dataShowForm::slotTimerNum);
    connect(&_timerMove,&QTimer::timeout,this,&dataShowForm::slotTimerMove);
    qDebug()<<_minbmq<<":"<<_maxbmq;
    initJasudu();

}

dataShowForm::~dataShowForm()
{

    delete ui;
}

void dataShowForm::on_pushButton_connect_clicked()
{

}
void dataShowForm::slotState(int err)
{
    switch (err) {
    case 1:{
        break;
    }
    case 2:{
        break;
    }
    default:
        break;
    }
}

char ConvertHexChar(char c)
{
    if((c >= '0') && (c <= '9'))
        return c - 0x30;
    else if((c >= 'A') && (c <= 'F'))
        return c - 'A' + 10;//'A' = 65;
    else if((c >= 'a') && (c <= 'f'))
        return c - 'a' + 10;
    else
        return -1;
}

QString getStringFromUnsignedChar(unsigned char *str)
{

    QString s;
    QString result = "";
    int rev = std::strlen((const char*)str);

    // Print String in Reverse order....
    for ( int i = 0; i<rev; i++)
    {
        s = QString("%1").arg(str[i],0,16);

        if(s == "0"){
            s="00";
        }
        result.append(s);

    }
    return result;
}

void dataShowForm::on_pushButton_send_clicked()
{/*
    QString datahead = ui->lineEdit_data->text().simplified();

    QByteArray byteHead = QByteArray::fromHex(datahead.toLatin1());

    unsigned char p = publicClass::getInstance()->cllc_checkSum((unsigned char *)byteHead.data(),byteHead.size());
    QString src =  publicClass::getInstance()->Byte_16(&p,sizeof (char));
    QString send = datahead;
    if(!ui->checkBox_jiaoyan->isChecked()){
        src ="";
    }
    datahead = QString(datahead+" "+src);


    QString databody = ui->lineEdit_body->text().simplified();

    QByteArray bytebody = QByteArray::fromHex(databody.toLatin1());

    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)bytebody.data(),bytebody.size());
    QString srcbody =  publicClass::getInstance()->Byte_16(&pbody,sizeof (char));
    QString sendBody = databody;
    databody = databody+" "+srcbody;


    if(ui->lineEdit_body->text().simplified().isEmpty()){

        QString  data = QString(datahead);
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        ui->textEdit_recv->append("send data:"+data);
        ui->textEdit_recv->append(QString("head src:")+src+"send size:"+QString::number(byte.size()));
        //                P_func->writeData(byte,byte.size());
    }
    else{
        QString  data = QString(datahead+databody);
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        ui->textEdit_recv->append("send data:"+data);
        ui->textEdit_recv->append(QString("head src:")+src+QString("body src:")+srcbody+"send size:"+QString::number(byte.size()));
        ui->textEdit_recv->append(QString("send:")+ QString(byte.toUpper()));
        //        P_func->writeData(byte,byte.size());
    }*/



}

//void dataShowForm::slotTimer()
//{
//    _timer.stop();
//}
//返回数据
void  dataShowForm::slotNewData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");

    ui->textEdit_recv->append("DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );
    //    emit signalDataTest(publicClass::getInstance()->ByteArrayToHexStr(data),"");
    for(int i =5;i<list.size()-1;i++){

        double f;
        bool ok;
        f = list.at(i).toInt(&ok, 16);
        ui->textEdit_recv->append(list.at(i)+ "recv dec data:"+QString::number(f));

    }

    //    float val;
    //    unsigned char hexdata[4]={0x00,0x00,0x48,0x41};
    //    memcpy(&val,hexdata,4);


}
uint16_t dataShowForm::ModbusCRC16(QByteArray senddata)
{
    int len=senddata.size();
    qDebug()<<"len"<<len;
    uint16_t wcrc=0XFFFF;//预置16位crc寄存器，初值全部为1
    uint8_t temp;//定义中间变量
    int i=0,j=0; //定义计数
    for(i=0;i<len;i++)//循环计算每个数据
    {
        temp=senddata.at(i);
        wcrc^=temp;
        for(j=0;j<8;j++){
            //判断右移出的是不是1，如果是1则与多项式进行异或。
            if(wcrc&0X0001){
                wcrc>>=1;//先将数据右移一位
                wcrc^=0XA001;//与上面的多项式进行异或
            }
            else//如果不是1，则直接移出
                wcrc>>=1;//直接移出
        }
    }
    temp=wcrc;//crc的值
    return wcrc;
}


void dataShowForm::on_pushButton_disconnect_clicked()
{
    //    P_Serial->ClosePort();
    //    emit signalStatus(QString("disconnect succes"));
}


//校验函数表生成函数
//uint8_t dataShowForm::CRC_C(uint8_t *CRCbuf,uint8_t Length)
//{
//    uint8_t CRCResult=0;
//    uint8_t CRCLength=0;
//    while(CRCLength<Length)
//    {
//        CRCResult ^= CRCbuf[CRCLength];
//        CRCResult = (CRCResult&0x00ff);
//        CRCLength++;
//        CRCResult = CRC_8X1[CRCResult];
//    }
//    return CRCResult;
//}

//void dataShowForm::CRC_8X1_TAB_Creat(void)
//{
//    Uint16 i,j;
//    Uint8 CRCResult;
//    for(j = 0;j < 256;j++)
//    {
//        CRCResult = j;
//        for(i = 0;i < 8;i++)
//        {
//            if(CRCResult & 0x80)
//            {
//                CRCResult = (CRCResult << 1) ^ 0x01; //0x01--x^8+1
//            }
//            else
//            {
//                CRCResult <<= 1;
//            }
//        }
//        CRC_8X1[j] = (CRCResult&0x00ff);
//    }
//}

void dataShowForm::on_pushButton_shuaxin_clicked()
{
    //    //    ui->comboBox->clear();
    //    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    //    {
    //        ui->comboBox_port->addItem(info.portName());
    //    }
}
void dataShowForm::slotTimer()
{
//    static int num = 0;

//    uint8_t data[14]={0x00};
//    uint8_t head[5]={0x00};
//    uint8_t bodyAngle[4]={0x00};
//    uint8_t bodySpeed[4]={0x00};
//    uint8_t body[9] = {0x00};
//    head[0] = 0x3e;
//    head[1] = 0xa8;
//    head[2] = 0x01;
//    head[3] = 0x08;

//    //位置环控制
//    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
//    head[4] = p;

//    int32_t valueAngle = 6.6* (-2232)*100;
//    memmove(&bodyAngle,&valueAngle,4);

//    uint32_t speed = 500*100;
//    memmove(&bodySpeed,&speed,4);

//    memmove(&body[0],bodyAngle,4);
//    memmove(&body[4],bodySpeed,4);

//    unsigned char pbody = publicClass::getInstance()->cllc_checkSum(body,8);

//    body[8] = pbody;
//    //    qDebug()<<QString::number(pbody,16)<<":::::::::";
//    memmove(data,head,sizeof (head));
//    memmove(&data[5],body,sizeof (body));
//    P_func->writeData(data,14,"");
    _time = _time.addMSecs(40);
    ui->label_time->setText(_time.toString("hh:mm:ss:zzz"));
}


void dataShowForm::on_pushButton_write_jiasudu_clicked()
{
    //    uint8_t head[5]={};
    //    head[0] = 0x3e;
    //    head[1] = 0x34;
    //    head[2] = 0x01;
    //    head[3] = 0x04;

    //    //速度环控制
    //    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    //    head[4] = p;
    //    //    QString databody = ui->lineEdit_body->text().simplified();

    //    int32_t valuebody = ui->lineEdit_jiasudu->text().simplified().toInt();
    //    uint8_t body[5]={};
    //    memmove(body,&valuebody,4);
    //    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,4);

    //    body[4] = pbody;

    //    uint8_t data[10] = {};

    //    memmove(data,head,5);
    //    memmove(&data[5],body,5);

    //    P_func->writeData(data,10,"");

}

void dataShowForm::on_pushButton_stop_clicked()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0xa2;
    head[2] = 0x01;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;

    int32_t valuebody = 0;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

    body[4] = pbody;

    uint8_t data[10] = {};

    memmove(data,head,5);
    memmove(&data[5],body,5);
    _isStop = true;
    P_func->writeData(data,10,"");
    //    uint8_t head[5]={};
    //    head[0] = 0x3e;
    //    head[1] = 0x81;
    //    head[2] = 0x01;
    //    head[3] = 0x00;

    //    //速度环控制
    //    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    //    head[4] = p;
    //    _isStop = true;
    //    P_func->writeData(head,5,"");

}

void dataShowForm::on_pushButton_start_clicked()
{
#if 0
    uint8_t data[14]={0x00};
    uint8_t head[5]={0x00};
    uint8_t bodyAngle[4]={0x00};
    uint8_t bodySpeed[4]={0x00};
    uint8_t body[9] = {0x00};
    head[0] = 0x3e;
    head[1] = 0xa8;
    head[2] = 0x01;
    head[3] = 0x08;

    //位置环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
    head[4] = p;

    int32_t valueAngle = -2232*100*8;
    memmove(&bodyAngle,&valueAngle,4);

    uint32_t speed = 2000*100;
    memmove(&bodySpeed,&speed,4);

    memmove(&body[0],bodyAngle,4);
    memmove(&body[4],bodySpeed,4);

    unsigned char pbody = publicClass::getInstance()->cllc_checkSum(body,8);

    body[8] = pbody;
    //    qDebug()<<QString::number(pbody,16)<<":::::::::";
    memmove(data,head,sizeof (head));
    memmove(&data[5],body,sizeof (body));

    P_func->writeData(data,14,"3E A8 01 08");
#endif
    int numtime = ui->lineEdit->text().toInt();
    _timerMove.start(numtime);
    _timer.start(30);
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0xa2;

    head[2] = 0x01;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;

    int32_t valuebody = -2000*100;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

    body[4] = pbody;

    uint8_t data[10] = {};
    memmove(data,head,5);
    memmove(&data[5],body,5);
    QString check = "3E A2 01 07";
    P_func->writeData(data,10,check);
    _nummove = 1;
}

void dataShowForm::on_pushButton_weizhi_clicked()
{
    //    uint8_t data[14]={0x00};
    //    uint8_t head[5]={0x00};
    //    uint8_t bodyAngle[4]={0x00};
    //    uint8_t bodySpeed[4]={0x00};
    //    uint8_t body[9] = {0x00};
    //    head[0] = 0x3e;
    //    head[1] = 0xa8;
    //    head[2] = 0x01;
    //    head[3] = 0x08;

    //    //位置环控制
    //    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
    //    head[4] = p;

    //    int32_t valueAngle = ui->lineEdit_jiaodu->text().toInt()*100;
    //    memmove(&bodyAngle,&valueAngle,4);

    //    uint32_t speed = ui->lineEdit_sudu->text().toUInt()*100;
    //    memmove(&bodySpeed,&speed,4);

    //    memmove(&body[0],bodyAngle,4);
    //    memmove(&body[4],bodySpeed,4);

    //    unsigned char pbody = publicClass::getInstance()->cllc_checkSum(body,8);

    //    body[8] = pbody;
    //    //    qDebug()<<QString::number(pbody,16)<<":::::::::";
    //    memmove(data,head,sizeof (head));
    //    memmove(&data[5],body,sizeof (body));

    //    P_func->writeData(data,14,"");
}
//编码器报错停止电机
void dataShowForm::slotBmqError()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x81;
    head[2] = 0x01;
    head[3] = 0x00;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;

    P_func->writeData(head,5,"");
    qCritical()<<("<font color = red>ERROR:检查编码器是否掉线!</font>");
    ui->label_status->setText("<font color = red>ERROR:检查编码器是否掉线!</font>");

}
void  dataShowForm::slotTimerNum()
{
    _timerC++;
}
void dataShowForm::slotBmq(int32_t dan,int32_t fbl,int32_t duo)
{
    ui->label_bmq_danquan->setText(QString::number(dan));
    ui->label_bmq_duoquan->setText(QString::number(duo));
    return;

    if(_isStop){
        return;
    }

    int32_t value = duo*524287+dan;
    if(value<_minbmq||value>_maxbmq){
        uint8_t head[5]={};
        head[0] = 0x3e;
        head[1] = 0xa2;
        head[2] = 0x01;
        head[3] = 0x04;

        //速度环控制
        unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

        head[4] = p;

        int32_t valuebody = 0;
        uint8_t body[5]={};
        memmove(body,&valuebody,4);
        unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

        body[4] = pbody;

        uint8_t data[10] = {};

        memmove(data,head,5);
        memmove(&data[5],body,5);
        _isStop = true;
        P_func->writeData(data,10,"");
        _timerMove.stop();

    }
    if ((!_isInit)&&(value>_minbmq)&&(value<_maxbmq)) {
#if 1
        uint8_t head[5]={};
        head[0] = 0x3e;
        head[1] = 0xa2;
        head[2] = 0x01;
        head[3] = 0x04;

        //速度环控制
        unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

        head[4] = p;

        int32_t valuebody = 600*100;
        uint8_t body[5]={};
        memmove(body,&valuebody,4);
        unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

        body[4] = pbody;

        uint8_t data[10] = {};

        memmove(data,head,5);
        memmove(&data[5],body,5);
        QString check = "3E A2 01 07";
        P_func->writeData(data,10,check);

#endif

        //        _timer.start(5000);
        if(P_func->get485Status()){
            _isInit = true;
            qInfo()<<"[初始化归0]";
            P_func->set485Status(false);
        }
    }
    if(value<=_minbmq){
        if(!_left){
#if 1
            uint8_t head[5]={};
            head[0] = 0x3e;
            head[1] = 0xa2;
            head[2] = 0x01;
            head[3] = 0x04;

            //速度环控制
            unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

            head[4] = p;

            int32_t valuebody = -2500*100;
            uint8_t body[5]={};
            memmove(body,&valuebody,4);
            unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

            body[4] = pbody;

            uint8_t data[10] = {};
            memmove(data,head,5);
            memmove(&data[5],body,5);
            QString check = "3E A2 01 07";
            P_func->writeData(data,10,check);
#endif
            if(P_func->get485Status()){
                qInfo()<<"[right move]";
                _left = true;
                _right = false;
                _isInit = true;
                P_func->set485Status(false);
            }

        }
    }
    else if (value>=_maxbmq) {
        if(!_right){
#if 1
            uint8_t head[5]={};
            head[0] = 0x3e;
            head[1] = 0xa2;

            head[2] = 0x01;
            head[3] = 0x04;

            //速度环控制
            unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

            head[4] = p;

            int32_t valuebody = 2500*100;
            uint8_t body[5]={};
            memmove(body,&valuebody,4);
            unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

            body[4] = pbody;

            uint8_t data[10] = {};
            memmove(data,head,5);
            memmove(&data[5],body,5);
            QString check = "3E A2 01 07";
            P_func->writeData(data,10,check);
#endif
            if(P_func->get485Status()){
                qInfo()<<"[left move]";
                _right = true;
                _left = false;
                _isInit = true;
                P_func->set485Status(false);
            }
        }

    }

}
void dataShowForm::initJasudu()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x34;
    head[2] = 0x01;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;
    //    QString databody = ui->lineEdit_body->text().simplified();

    int32_t valuebody = 3000;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,4);

    body[4] = pbody;

    uint8_t data[10] = {};

    memmove(data,head,5);
    memmove(&data[5],body,5);

    P_func->writeData(data,10,"");
}

void dataShowForm::on_pushButton_reboot_clicked()
{
    _isStop = false;
    _isInit = false;
    _left = false;
    _right = false;
}

void dataShowForm::on_pushButton_close_clicked()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x80;
    head[2] = 0x01;
    head[3] = 0x00;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;
    //    _isStop = true;
    P_func->writeData(head,5,"");
    _timerMove.stop();
}

void dataShowForm::on_pushButton_run_clicked()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x88;
    head[2] = 0x01;
    head[3] = 0x00;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;
    _isStop = true;
    P_func->writeData(head,5,"");
}
void dataShowForm::logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");//
        break;
    case QtWarningMsg:
        text = QString("Warning:");//警告
        break;
    case QtCriticalMsg:
        text = QString("Critical:"); //严重错误
        break;
    case QtInfoMsg:
        text = QString("info:");//提示信息
        break;
    case QtFatalMsg:
        text = QString("Fatal:");//致命错误
        break;
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);

    QString message = QString("{%1 %2 %3 %4}").arg(text).arg(context_info).arg(msg).arg(current_date);
    writeOutPut(message,type);


    QFile file("test.log");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
}
void dataShowForm::writeOutPut(const QString &text,QtMsgType type)
{

    switch(type)
    {
    case QtDebugMsg:
        p_dataShowForm->showOutPut(QString("<font color='green'><b>%1</font><br>").arg(text));
        break;
    case QtWarningMsg:
        p_dataShowForm->showOutPut(QString("<font color='yellow'><b>%1</font><br>").arg(text));
        break;
    case QtCriticalMsg:
        p_dataShowForm->showOutPut(QString("<font color='red'><b>%1</font><br>").arg(text));
        break;
    case QtInfoMsg:
        p_dataShowForm->showOutPut(QString("<font color='blue'><b>%1</font><br>").arg(text));
        break;
    case QtFatalMsg:
        p_dataShowForm->showOutPut(QString("<font color='red'><b>%1</font><br>").arg(text));
        break;
    }


}
void dataShowForm::showOutPut(const QString &text)
{
    ui->textEdit_recv->append(text);
}
//void dataShowForm::mousePressEvent(QMouseEvent *event)
//{

//}

void dataShowForm::on_pushButton_min_clicked()
{
    this->showMinimized();
}

void dataShowForm::on_pushButton_closeform_clicked()
{
    on_pushButton_stop_clicked();

    P_func->exitProc();
    this->close();
}

void dataShowForm::on_pushButton_reset_clicked()
{

}
void dataShowForm::slotTimerMove()
{
//    static int sum = 0;
//    if(sum == 600){
//        _timerMove.stop();
//        on_pushButton_close_clicked();
//        sum = 0;
//        ui->label_status->setText("<font color = green>提示:运行时间过长，建议重启标定</font>");
//        return;
//    }
#if 0
    if(_nummove == 1){
        uint8_t data[14]={0x00};
        uint8_t head[5]={0x00};
        uint8_t bodyAngle[4]={0x00};
        uint8_t bodySpeed[4]={0x00};
        uint8_t body[9] = {0x00};
        head[0] = 0x3e;
        head[1] = 0xa8;
        head[2] = 0x01;
        head[3] = 0x08;

        //位置环控制
        unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
        head[4] = p;

        int32_t valueAngle = 2232*100*8;
        memmove(&bodyAngle,&valueAngle,4);

        uint32_t speed = 2000*100;
        memmove(&bodySpeed,&speed,4);

        memmove(&body[0],bodyAngle,4);
        memmove(&body[4],bodySpeed,4);

        unsigned char pbody = publicClass::getInstance()->cllc_checkSum(body,8);

        body[8] = pbody;
        //    qDebug()<<QString::number(pbody,16)<<":::::::::";
        memmove(data,head,sizeof (head));
        memmove(&data[5],body,sizeof (body));

        P_func->writeData(data,14,"3E A8 01 08");

        _nummove = 2;
    }
    else if (_nummove == 2) {
        uint8_t data[14]={0x00};
        uint8_t head[5]={0x00};
        uint8_t bodyAngle[4]={0x00};
        uint8_t bodySpeed[4]={0x00};
        uint8_t body[9] = {0x00};
        head[0] = 0x3e;
        head[1] = 0xa8;
        head[2] = 0x01;
        head[3] = 0x08;

        //位置环控制
        unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
        head[4] = p;

        int32_t valueAngle = -2232*100*8;
        memmove(&bodyAngle,&valueAngle,4);

        uint32_t speed = 2000*100;
        memmove(&bodySpeed,&speed,4);

        memmove(&body[0],bodyAngle,4);
        memmove(&body[4],bodySpeed,4);

        unsigned char pbody = publicClass::getInstance()->cllc_checkSum(body,8);

        body[8] = pbody;
        //    qDebug()<<QString::number(pbody,16)<<":::::::::";
        memmove(data,head,sizeof (head));
        memmove(&data[5],body,sizeof (body));

        P_func->writeData(data,14,"3E A8 01 08");
        _nummove = 1;
    }
#endif

    if(_nummove == 1){
        uint8_t head[5]={};
        head[0] = 0x3e;
        head[1] = 0xa2;

        head[2] = 0x01;
        head[3] = 0x04;

        //速度环控制
        unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

        head[4] = p;

        int32_t valuebody = 2000*100;
        uint8_t body[5]={};
        memmove(body,&valuebody,4);
        unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

        body[4] = pbody;

        uint8_t data[10] = {};
        memmove(data,head,5);
        memmove(&data[5],body,5);
        QString check = "3E A2 01 07";
        P_func->writeData(data,10,check);
        qInfo()<<"[left move]";
        _nummove = 2;

    }
    else if (_nummove == 2) {
        uint8_t head[5]={};
        head[0] = 0x3e;
        head[1] = 0xa2;

        head[2] = 0x01;
        head[3] = 0x04;

        //速度环控制
        unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

        head[4] = p;

        int32_t valuebody = -2000*100;
        uint8_t body[5]={};
        memmove(body,&valuebody,4);
        unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

        body[4] = pbody;

        uint8_t data[10] = {};
        memmove(data,head,5);
        memmove(&data[5],body,5);
        QString check = "3E A2 01 07";
        P_func->writeData(data,10,check);
        qInfo()<<"[right move]";
        _nummove = 1;

    }
//    sum++;
}

void dataShowForm::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
