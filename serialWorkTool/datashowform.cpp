#include "datashowform.h"
#include "ui_datashowform.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>


dataShowForm::dataShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataShowForm)
{
    ui->setupUi(this);
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBox_port->addItem(info.portName());
    }
    P_Serial= new QSerialWork;
    P_Serial->InitSerialPort();
    connect(P_Serial,&QSerialWork::State,this,&dataShowForm::slotState);
    connect(P_Serial,&QSerialWork::NewData,this,&dataShowForm::slotNewData);
    //    connect(_timer,&QTimer::timeout,this,&dataShowForm::slotTimer);



}

dataShowForm::~dataShowForm()
{
    P_Serial->ClosePort();
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
        emit signalStatus(QStringLiteral("连接成功"));
        break;
    }
    case 2:{
        emit signalStatus(QStringLiteral("连接失败"));
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
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(arr.toInt(), 16).toUpper());
        break;
    }
    case data_16:{
        int16_t ss = arr.toShort();
        unsigned char out[2] ={};
        publicClass::getInstance()->shortArr2Bytes(&ss,2,out);
        QByteArray byArr((const char*)out,2);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),2);
        ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(ssss));
        break;
    }
    case data_32:{
        if(arr.contains(".")){
            float ss = arr.toFloat();
            unsigned char out[4] ={};
            publicClass::getInstance()->floatArr2Bytes(&ss,4,out);
            QByteArray byArr((const char*)out,4);

            QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
            ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(ssss));
        }
        else {
            int32_t ss = arr.toInt();
            unsigned char out[4] ={};
            publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
            QByteArray byArr((const char*)out,4);

            QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
            ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(ssss));
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
            ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(hex));
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
            ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(hex));
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
        ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(hex));
        break;
    }
    case data_u32:{
        uint32_t ss = arr.toUInt();
        unsigned char out[4] ={};
        publicClass::getInstance()->uint32Arr2Bytes(&ss,4,out);
        QByteArray byArr((const char*)out,4);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
        ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(ssss));

        break;
    }
    case data_u16:{
        uint16_t ss = arr.toUShort();
        unsigned char out[2] ={};
        publicClass::getInstance()->ushortArr2Bytes(&ss,2,out);
        QByteArray byArr((const char*)out,2);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),2);
        ui->textEdit_sum->append(QStringLiteral("结果:%1").arg(ssss));
        break;
    }
    case data_u8:{
        unsigned int pos = 0;
        unsigned char * temp = nullptr;

        QByteArray array = arr.toUtf8();
        QString string1=array.toHex();
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(arr.toInt(), 16).toUpper());
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
        ui->textEdit_recv->append(QStringLiteral("head校验和:")+src+"send size:"+QString::number(byte.size()));
        P_Serial->WriteData(byte,byte.size());
    }
    else{
        QString  data = QString(datahead+databody);
        QByteArray byte = QByteArray::fromHex(data.toLatin1());

        ui->textEdit_recv->append("send data:"+data);
        ui->textEdit_recv->append(QStringLiteral("head校验和:")+src+QStringLiteral("body校验和:")+srcbody+"send size:"+QString::number(byte.size()));
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
    emit signalStatus(QStringLiteral("断开成功"));
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
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(val));
        break;
    }
    case 1:{ //int_32
        int32_t val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(val));

        break;
    }
    case 2:{//float
        float val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(val));
        break;
    }
    case 3:{//short
        int16_t val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(val));
        break;
    }
    case 4:{//char
        QString data = ui->lineEdit_sum->text().simplified();
        double f;
        bool ok;
        f = ui->lineEdit_sum->text().simplified().toInt(&ok, 16);
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(f));
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

        ui->textEdit_sum->append(QStringLiteral("结果:")+str);
        break;
    }

    case 6:{//转10进制
        QString data = ui->lineEdit_sum->text().simplified();
        bool ok;
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(data.toLongLong(&ok,16)));
        break;
    }
    case 7:{
        double val;
        QString data = ui->lineEdit_sum->text().simplified();
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        memcpy(&val,byte.data(),byte.size());
        ui->textEdit_sum->append(QStringLiteral("结果:")+QString::number(val,'f',9));//精度9
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
    ui->textEdit_sum->append(QStringLiteral( "结果:")+sss);

    //    QString str1("123abc这是测试");
    //    QByteArray byte1 = str1.toLatin1(); //按照ASCII编码转换，无法转换中文
    //    QByteArray byte2 = str1.toUtf8();    //按照Utf-8编码转换，可以转换中文
    //    qDebug() <<  "byte1:" << byte1 << "byte2:" << byte2;
}
