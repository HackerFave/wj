#include "datashowform.h"
#include "ui_datashowform.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include <QProcess>

#define TEST_GKJ 0
dataShowForm::dataShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataShowForm)
{
    ui->setupUi(this);

    exitProcess();

    _A2 = publicClass::getInstance()->readValueIni("COM/A2").simplified();
    _A3 = publicClass::getInstance()->readValueIni("COM/A3").simplified();
    _A4 = publicClass::getInstance()->readValueIni("COM/A4").simplified();
    _A8 = publicClass::getInstance()->readValueIni("COM/A8").simplified();
    qRegisterMetaType<int16_t>("int32_t");
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(info.portName());
    }
    //     publicClass::getInstance()->setValueIni(QString("COM/A%1").arg(QString::number(i)),info.portName());
    P_Serial= new QSerialWork;

    P_port= P_Serial->InitSerialPort();

    connect(P_Serial,&QSerialWork::State,this,&dataShowForm::slotState);
    connect(P_Serial,&QSerialWork::NewData,this,&dataShowForm::slotNewData);
    //    connect(_timer,&QTimer::timeout,this,&dataShowForm::slotTimer);

    ui->textEdit_recv->document()->setMaximumBlockCount(1000);
#if TEST_GKJ
    _process_A2 = new QProcess(0);
    QString str = QApplication::applicationDirPath()+ "/A2/encoder.exe";//加可执行文件路径

    _process_A2->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A2->start(str);

    if (!_process_A2->waitForStarted()) {
        qDebug() << "start failed:" << _process_A2->errorString();
    } else {
        qDebug() << "start success:";
    }

    _process_A3 = new QProcess(0);
    QString str_A3 = QApplication::applicationDirPath()+ "/A3/encoder.exe";//加可执行文件路径

    _process_A3->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A3->start(str_A3);

    if (!_process_A3->waitForStarted()) {
        qDebug() << "start failed:" << _process_A3->errorString();
    } else {
        qDebug() << "start success:";
    }


    _process_A4 = new QProcess(0);
    QString str_A4 = QApplication::applicationDirPath()+ "/A4/encoder.exe";//加可执行文件路径

    _process_A4->setProcessChannelMode(QProcess::MergedChannels);
    //    connect(_process , &QProcess::readyReadStandardOutput , this , &dataShowForm::onOut);
    _process_A4->start(str_A4);

    if (!_process_A4->waitForStarted()) {
        qDebug() << "start failed:" << _process_A4->errorString();
    } else {
        qDebug() << "start success:";
    }

    _process_A8 = new QProcess(0);
    QString str_A8 = QApplication::applicationDirPath()+ "/A8/encoder.exe";//加可执行文件路径

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
    initThread();
#endif
    //    connect(this,&dataShowForm::signalBmqDataToForm_A2,_serialWorkThreadPool_BMQ_A2,&serialWorkThreadPool_BMQ_A2::slotWorkData,Qt::DirectConnection);
    //    connect(this,&dataShowForm::signalBmqDataToForm_A3,_serialWorkThreadPool_BMQ_A3,&serialWorkThreadPool_BMQ_A3::slotWorkData,Qt::DirectConnection);
    //    connect(this,&dataShowForm::signalBmqDataToForm_A4,_serialWorkThreadPool_BMQ_A4,&serialWorkThreadPool_BMQ_A4::slotWorkData,Qt::DirectConnection);
    ////    connect(this,&dataShowForm::signalBmqDataToForm_A8,_serialWorkThreadPool_BMQ_A8,&serialWorkThreadPool_BMQ_A8::slotWorkData,Qt::DirectConnection);
    //    connect(this,&dataShowForm::signalBmqDataToForm_A1,_serialWorkThreadPool_BMQ_A1,&serialWorkThreadPool_BMQ_A1::slotWorkData,Qt::DirectConnection);

    ////    connect(this,SIGNAL(signalBmqDataToForm01(QString,int32_t,int32_t)),_serialWorkThreadPool_BMQ_XT_1,SLOT(slotWorkData(QString,int32_t,int32_t)),Qt::DirectConnection);
    ////    connect(this,SIGNAL(signalBmqDataToForm02(QString,int32_t,int32_t)),_serialWorkThreadPool_BMQ_XT_2,SLOT(slotWorkData(QString,int32_t,int32_t)),Qt::DirectConnection);

    //    connect(this,&dataShowForm::signalMachineData_A2,_serialWorkThreadPool_BMQ_A2,&serialWorkThreadPool_BMQ_A2::slotMachineData,Qt::DirectConnection);
    //    connect(this,&dataShowForm::signalMachineData_A3,_serialWorkThreadPool_BMQ_A3,&serialWorkThreadPool_BMQ_A3::slotMachineData,Qt::DirectConnection);
    //    connect(this,&dataShowForm::signalMachineData_A4,_serialWorkThreadPool_BMQ_A4,&serialWorkThreadPool_BMQ_A4::slotMachineData,Qt::DirectConnection);
    ////    connect(this,&dataShowForm::signalMachineData_A8,_serialWorkThreadPool_BMQ_A8,&serialWorkThreadPool_BMQ_A8::slotMachineData,Qt::DirectConnection);

    //    connect(this,&dataShowForm::signalMachineData_A1,_serialWorkThreadPool_BMQ_A1,&serialWorkThreadPool_BMQ_A1::slotMachineData,Qt::DirectConnection);
    ////    connect(this,&dataShowForm::signalMachineData_XT01,_serialWorkThreadPool_BMQ_XT_1,&serialWorkThreadPool_BMQ_XT_1::slotMachineData,Qt::DirectConnection);
    ////    connect(this,&dataShowForm::signalMachineData_XT02,_serialWorkThreadPool_BMQ_XT_2,&serialWorkThreadPool_BMQ_XT_2::slotMachineData,Qt::DirectConnection);

}

dataShowForm::~dataShowForm()
{
    _timerBmqRead.stop();
    if (_process_A2) {
        _process_A2->close();
        delete _process_A2;
    }
    if (_process_A3) {
        _process_A3->close();
        delete _process_A3;
    }
    if (_process_A4) {
        _process_A4->close();
        delete _process_A4;
    }if (_process_A8) {
        _process_A8->close();
        delete _process_A8;
    }
    P_Serial->ClosePort();
    _poolBMQ.releaseThread();
    delete P_Serial;
    delete ui;
}

void dataShowForm::on_pushButton_connect_clicked()
{
    P_Serial->OpenPort(ui->comboBox_port->currentText().simplified(),
                       static_cast<QSerialPort::BaudRate>(ui->comboBox_BaudRate->currentText().toUInt()),
                       static_cast<QSerialPort::DataBits>(ui->comboBox_databit->currentText().toUInt()));

}
void dataShowForm::slotState(int err)
{
    switch (err) {
    case 1:{
        emit signalStatus("connect success");
        break;
    }
    case 2:{
        emit signalStatus("connect failed");
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
void dataShowForm::uinttoBytes(data_type type, QString arr)
{
    switch (type) {
    case data_8:{
        unsigned int pos = 0;
        unsigned char * temp = nullptr;

        QByteArray array = arr.toUtf8();
        QString string1=array.toHex();
        ui->textEdit_sum->append("[result:]"+QString::number(arr.toInt(), 16).toUpper());
        break;
    }
    case data_16:{
        int16_t ss = arr.toShort();
        unsigned char out[2] ={};
        publicClass::getInstance()->shortArr2Bytes(&ss,2,out);
        QByteArray byArr((const char*)out,2);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),2);
        ui->textEdit_sum->append(QString("[result:]:%1").arg(ssss));
        break;
    }
    case data_32:{
        if(arr.contains(".")){
            float ss = arr.toFloat();
            unsigned char out[4] ={};
            publicClass::getInstance()->floatArr2Bytes(&ss,4,out);
            QByteArray byArr((const char*)out,4);

            QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
            ui->textEdit_sum->append(QString("[result:]:%1").arg(ssss));
        }
        else {
            int32_t ss = arr.toInt();
            unsigned char out[4] ={};
            publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
            QByteArray byArr((const char*)out,4);

            QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
            ui->textEdit_sum->append(QString("[result:]:%1").arg(ssss));
        }

        break;
    }
    case data_64:{
        if(arr.contains(".")){
            double ss = arr.toDouble();
            unsigned char out[8] ={};
            memset(out,0,8);
            memmove(out,&ss,8);
            QString hex;
            for(int i=0;i<8;i++){
                QString str(out[i]);
                QByteArray array = str.toLatin1();
                QString string1=array.toHex().toUpper();
                hex.append(string1+" ");

            }
            ui->textEdit_sum->append(QString("[result:]:%1").arg(hex));
        }
        else {
            int64_t ss = arr.toLongLong();
            unsigned char out[8] ={};
            memset(out,0,8);
            memmove(out,&ss,8);
            QString hex;
            for(int i=0;i<8;i++){
                QString str(out[i]);
                QByteArray array = str.toLatin1();
                QString string1=array.toHex().toUpper();
                hex.append(string1+" ");

            }
            ui->textEdit_sum->append(QString("[result:]:%1").arg(hex));
        }
        break;
    }
    case data_u64:{
        uint64_t ss = arr.toULongLong();
        unsigned char out[8] ={};
        memset(out,0,8);
        memmove(out,&ss,8);
        QString hex;
        for(int i=0;i<8;i++){
            QString str(out[i]);
            QByteArray array = str.toLatin1();
            QString string1=array.toHex().toUpper();
            hex.append(string1+" ");

        }
        ui->textEdit_sum->append(QString("[result:]:%1").arg(hex));
        break;
    }
    case data_u32:{
        uint32_t ss = arr.toUInt();
        unsigned char out[4] ={};
        publicClass::getInstance()->uint32Arr2Bytes(&ss,4,out);
        QByteArray byArr((const char*)out,4);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
        ui->textEdit_sum->append(QString("[result:]:%1").arg(ssss));

        break;
    }
    case data_u16:{
        uint16_t ss = arr.toUShort();
        unsigned char out[2] ={};
        publicClass::getInstance()->ushortArr2Bytes(&ss,2,out);
        QByteArray byArr((const char*)out,2);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),2);
        ui->textEdit_sum->append(QString("[result:]:%1").arg(ssss));
        break;
    }
    case data_u8:{
        unsigned int pos = 0;
        unsigned char * temp = nullptr;

        QByteArray array = arr.toUtf8();
        QString string1=array.toHex();
        ui->textEdit_sum->append(QString("[result:]:")+QString::number(arr.toInt(), 16).toUpper());
        break;
    }
    default:
        break;
    }


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
{


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
        P_Serial->WriteData(byte,byte.size());
    }
    else{
        QString  data = QString(datahead+databody);
        QByteArray byte = QByteArray::fromHex(data.toLatin1());

        ui->textEdit_recv->append("send data:"+data);
        ui->textEdit_recv->append(QString("head src:")+src+QString("body src:")+srcbody+"send size:"+QString::number(byte.size()));
        ui->textEdit_recv->append(QString("send:")+ QString(byte.toUpper()));
        P_Serial->WriteData(byte,byte.size());
    }



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
    emit signalDataTest(publicClass::getInstance()->ByteArrayToHexStr(data),"");
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
    P_Serial->ClosePort();
    emit signalStatus(QString("disconnect succes"));
}

void dataShowForm::on_pushButton_sum_clicked()
{

    int id_byte = ui->comboBox_byte->currentIndex();

    switch (id_byte) {
    case 0:{ //int_64
        int64_t val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(val));
        break;
    }
    case 1:{ //int_32
        int32_t val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(val));

        break;
    }
    case 2:{//float
        float val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(val));
        break;
    }
    case 3:{//short
        int16_t val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(val));
        break;
    }
    case 4:{//char
        QString data = ui->lineEdit_sum->text().simplified();
        double f;
        bool ok;
        f = ui->lineEdit_sum->text().simplified().toInt(&ok, 16);
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(f));
        break;
    }
    case 5:{//ASC码
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toUtf8());
        QString str;
        for(int i = 0; i < byte.count(); ++i)
        {
            str.append(QChar(byte .at(i)));
        }

        ui->textEdit_sum->append(QString("[result:]:%1")+str);
        break;
    }

    case 6:{//转10进制
        QString data = ui->lineEdit_sum->text().simplified();
        bool ok;
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(data.toLongLong(&ok,16)));
        break;
    }
    case 7:{
        double val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QString("[result:]:%1")+QString::number(val,'f',9));//精度9
        break;
    }
    default:
        break;
    }
}

void dataShowForm::on_pushButton_sum_2_clicked()
{
    int id_hex = ui->comboBox_hex->currentIndex();
    switch (id_hex) {
    case 0:{ //64位
        uinttoBytes(data_64,ui->lineEdit_sum_2->text().simplified());

        break;
    }
    case 1:{ //32位

        uinttoBytes(data_32,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    case 2:{//16位
        uinttoBytes(data_16,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    case 3:{ //8位
        uinttoBytes(data_8,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    case 4:{ //u64
        uinttoBytes(data_u64,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    case 5:{//u32
        uinttoBytes(data_u32,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    case 6:{ //u16
        uinttoBytes(data_u16,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    case 7:{ //u8
        uinttoBytes(data_u8,ui->lineEdit_sum_2->text().simplified());
        break;
    }
    default:
        break;
    }
}

void dataShowForm::on_pushButton_sum_asc_clicked()
{
    QString str = ui->lineEdit_asc->text();
    QByteArray data = str.toLatin1();
    QString sss= publicClass::getInstance()->Byte_16((unsigned char*)data.data(),data.size());
    ui->textEdit_sum->append(QString("[result:]:%1")+sss);

    //    QString str1("123abc这是测试");
    //    QByteArray byte1 = str1.toLatin1(); //按照ASCII编码转换，无法转换中文
    //    QByteArray byte2 = str1.toUtf8();    //按照Utf-8编码转换，可以转换中文
    //    qDebug() <<  "byte1:" << byte1 << "byte2:" << byte2;
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
    ui->comboBox->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(info.portName());
    }
}
//void dataShowForm::slotReadShareMemory()
//{
//    if(!_sharememory.attach())
//    {
//        qDebug() << "cann't attach sahrememory";
//    }
//    QBuffer buffer;
//    _sharememory.lock();
//    buffer.setData((char*)_sharememory.constData(),_sharememory.size());
//    buffer.open(QBuffer::ReadWrite);
//    buffer.readAll();
//    _sharememory.unlock();
//    _sharememory.detach();
//    qDebug() << buffer.data().data();

//}
void dataShowForm::initServer()
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
void dataShowForm::slot_new_connection()
{
    QLocalSocket *newsocket = m_server->nextPendingConnection();  //获取连接上的客户端句柄
    connect(newsocket, SIGNAL(readyRead()), this, SLOT(slot_recv_data())); //关联数据接收槽函数
}
void dataShowForm::slot_recv_data()
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
        emit signalBmqDataToForm(rcvstr.mid(8),str);
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

bool dataShowForm::is_first_connect(QLocalSocket *newsocket)  //是否为首次连接
{
    int len = _local_sockets.length();
    for(int i=0; i<len; i++)
    {
        if(newsocket == (QLocalSocket *)_local_sockets.at(i))
            return false;
    }
    _local_sockets.append(newsocket);
    return true;
}

void dataShowForm::initThread()
{
    _poolBMQ.setMaxThreadCount(7);

    //    QString com_A2 = "COM6";
    //    QString com_A3 = "COM5";
    //    QString com_A4 = "COM7";
    //    QString com_A8 = "COM8";
    //    QString com =" ";
    //    _serialWorkThreadPool_BMQ_A2 = new serialWorkThreadPool_BMQ_A2(com_A2);
    //    _serialWorkThreadPool_BMQ_A3 = new serialWorkThreadPool_BMQ_A3(com_A3);
    //    _serialWorkThreadPool_BMQ_A4 = new serialWorkThreadPool_BMQ_A4(com_A4);
    ////    _serialWorkThreadPool_BMQ_A8 = new serialWorkThreadPool_BMQ_A8(com_A8);
    //    _serialWorkThreadPool_BMQ_A1 = new serialWorkThreadPool_BMQ_A1(com);// 603
    ////    _serialWorkThreadPool_BMQ_XT_1 = new serialWorkThreadPool_BMQ_XT_1(com);//01
    ////    _serialWorkThreadPool_BMQ_XT_2 = new serialWorkThreadPool_BMQ_XT_2(com);//02

    //    _serialWorkThreadPool_BMQ_A2->setAutoDelete(true);
    //    _serialWorkThreadPool_BMQ_A3->setAutoDelete(true);
    //    _serialWorkThreadPool_BMQ_A4->setAutoDelete(true);
    ////    _serialWorkThreadPool_BMQ_A8->setAutoDelete(true);
    //    _serialWorkThreadPool_BMQ_A1->setAutoDelete(true);
    ////    _serialWorkThreadPool_BMQ_XT_1->setAutoDelete(true);
    ////    _serialWorkThreadPool_BMQ_XT_2->setAutoDelete(true);

    //    _serialWorkThreadPool_BMQ_A2->startWork();
    //    _serialWorkThreadPool_BMQ_A3->startWork();
    //    _serialWorkThreadPool_BMQ_A4->startWork();
    ////    _serialWorkThreadPool_BMQ_A8->startWork();
    //    _serialWorkThreadPool_BMQ_A1->startWork();
    ////    _serialWorkThreadPool_BMQ_XT_1->startWork();
    ////    _serialWorkThreadPool_BMQ_XT_2->startWork();

    //    _poolBMQ.start(_serialWorkThreadPool_BMQ_A2);
    //    _poolBMQ.start(_serialWorkThreadPool_BMQ_A3);
    //    _poolBMQ.start(_serialWorkThreadPool_BMQ_A4);
    ////    _poolBMQ.start(_serialWorkThreadPool_BMQ_A8);
    //    _poolBMQ.start(_serialWorkThreadPool_BMQ_A1);
    ////    _poolBMQ.start(_serialWorkThreadPool_BMQ_XT_1);
    ////    _poolBMQ.start(_serialWorkThreadPool_BMQ_XT_2);

}
void dataShowForm::exitProcess()
{
    QSharedPointer<QProcess> process(new QProcess(0));
    QString exe ="encoder.exe";
    QString c = "taskkill /f /t /im encoder.exe";    //exeFileName为要杀死的进程名
    process.data()->execute(c);
    process.data()->close();

}
void dataShowForm::slotUpdateBmq()
{
    if(_isA2Start==true&&_isA3Start==true&&_isA4Start==true/*&&_isA8Start==true*/){
        _timerBmqRead.stop();
        qDebug()<<"running";
        return;
    }

    exitProcess();
    QString str = QApplication::applicationDirPath()+ "/A2/encoder.exe";//加可执行文件路径

    _process_A2->setProcessChannelMode(QProcess::MergedChannels);
    _process_A2->start(str);

    if (!_process_A2->waitForStarted()) {
        qDebug() << "start failed:" << _process_A2->errorString();
    } else {
        qDebug() << "start success:";
    }

    QString str_A3 = QApplication::applicationDirPath()+ "/A3/encoder.exe";//加可执行文件路径

    _process_A3->setProcessChannelMode(QProcess::MergedChannels);
    _process_A3->start(str_A3);

    if (!_process_A3->waitForStarted()) {
        qDebug() << "start failed:" << _process_A3->errorString();
    } else {
        qDebug() << "start success:";
    }

    QString str_A4 = QApplication::applicationDirPath()+ "/A4/encoder.exe";//加可执行文件路径

    _process_A4->setProcessChannelMode(QProcess::MergedChannels);
    _process_A4->start(str_A4);

    if (!_process_A4->waitForStarted()) {
        qDebug() << "start failed:" << _process_A4->errorString();
    } else {
        qDebug() << "start success:";
    }

    QString str_A8 = QApplication::applicationDirPath()+ "/A8/encoder.exe";//加可执行文件路径

    _process_A8->setProcessChannelMode(QProcess::MergedChannels);
    _process_A8->start(str_A8);

    if (!_process_A8->waitForStarted()) {
        qDebug() << "start failed:" << _process_A8->errorString();
    } else {
        qDebug() << "start success:";
    }
}
void dataShowForm::slotRecvMachineData(UINT id, BYTE *data)
{
    switch (id) {
    case 0x141:
    {
        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(0);
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        memcpy(&index,byte.data(),byte.size());
        if(index == 0x9c){
            int16_t value3;
            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1()+" "+datastr.split(" ").at(5).toLatin1());//电机转速
            memcpy(&value3,byte.data(),byte.size());
            int32_t value =value3;
            emit signalMachineData_A2(value);
        }
        break;
    }
    case 0x145:
    {
        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(0);
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        memcpy(&index,byte.data(),byte.size());
        if(index == 0x9c){
            int16_t value3;
            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1()+" "+datastr.split(" ").at(5).toLatin1());//电机转速
            memcpy(&value3,byte.data(),byte.size());
            int32_t value = value3;
            emit signalMachineData_A4(value);
        }
        break;
    }
    case 0x143:
    {
        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(0);
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        memcpy(&index,byte.data(),byte.size());
        if(index == 0x9c){
            int16_t value3;
            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1()+" "+datastr.split(" ").at(5).toLatin1());//电机转速
            memcpy(&value3,byte.data(),byte.size());

            int32_t value = value3;
            emit signalMachineData_A8(value);

        }
        break;
    }
    case 0x581:
    {

        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(1) +" "+ datastr.split(" ").at(2);
        QString valuestr = datastr.split(" ").at(4) +" "+ datastr.split(" ").at(5)+" "+ datastr.split(" ").at(6)+" "+ datastr.split(" ").at(7);
        QByteArray array = datastr.toLatin1();
        int16_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        memcpy(&index,byte.data(),byte.size());
        if(index == 12288){
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int16_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            int32_t value1 = value;
            emit signalMachineData_A3(value1);
        }
        break;
    }
    case 0x583:
    {
        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(1) +" "+ datastr.split(" ").at(2);
        QString valuestr = datastr.split(" ").at(4) +" "+ datastr.split(" ").at(5)+" "+ datastr.split(" ").at(6)+" "+ datastr.split(" ").at(7);
        QByteArray array = datastr.toLatin1();
        int16_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
        int32_t value;
        memcpy(&value,valuebyte.data(),valuebyte.size());
        memcpy(&index,byte.data(),byte.size());
        if (index==0x6069) {

            emit signalMachineData_A1(value);
        }
        if (index==0x6064) {
            QMap<QString,QVariant> MAP;
            MAP["dan"] = value;
            emit signalBmqDataToForm_A1("583",0,value);
        }

    }
    case 0x01:
    {
        QString datastr = publicClass::getInstance()->Byte_16(data,6);
        QString ids = datastr.split(" ").at(1);
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.simplified().toLatin1());
        memcpy(&index,byte.data(),byte.size());
        if(index == 0x04){
            int32_t value;
            QByteArray bytevalue ;
            QString str ="";
            for(int i = datastr.split(" ").size()-1;i>=2;i--){
                str+=datastr.split(" ").at(i)+" ";
            }
            bytevalue = QByteArray::fromHex(str.toLatin1());
            memcpy(&value,bytevalue.data(),bytevalue.size());

            emit signalMachineData_XT01(value);
        }
        if(index == 0x11){
            int32_t value;
            QByteArray bytevalue ;
            QString str ="";
            for(int i = datastr.split(" ").size()-1;i>=2;i--){
                str+=datastr.split(" ").at(i)+" ";
            }
            bytevalue = QByteArray::fromHex(str.toLatin1());
            memcpy(&value,bytevalue.data(),bytevalue.size());
            emit signalBmqDataToForm01("01",0,value);
        }
        break;
    }
    case 0x02:
    {
        QString datastr = publicClass::getInstance()->Byte_16(data,6);
        QString ids = datastr.split(" ").at(1);
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.simplified().toLatin1());
        memcpy(&index,byte.data(),byte.size());
        if(index == 0x04){
            int32_t value;
            QByteArray bytevalue ;
            QString str ="";
            for(int i = datastr.split(" ").size()-1;i>=2;i--){
                str+=datastr.split(" ").at(i)+" ";
            }
            bytevalue = QByteArray::fromHex(str.toLatin1());
            memcpy(&value,bytevalue.data(),bytevalue.size());

            emit signalMachineData_XT02(value);
        }
        if(index == 0x11){
            int32_t value;
            QByteArray bytevalue ;
            QString str ="";
            for(int i = datastr.split(" ").size()-1;i>=2;i--){
                str+=datastr.split(" ").at(i)+" ";
            }
            bytevalue = QByteArray::fromHex(str.toLatin1());
            memcpy(&value,bytevalue.data(),bytevalue.size());
            emit signalBmqDataToForm02("02",0,value);
        }
        break;
    }
    default:
        break;
    }

}
