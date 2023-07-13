#include "xintuoCanForm.h"
#include "ui_xintuoCanForm.h"
#include <QtDebug>
xintuoCanForm::xintuoCanForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xintuoCanForm)
{
    ui->setupUi(this);
    connect(&_timerTest,SIGNAL(timeout()),this,SLOT(slotTimer()));

    _minValueDan_BMQ_XT_1 = publicClass::getInstance()->readValueIni("XT01-min/danquan").toLong();
    _maxValueDan_BMQ_XT_1 = publicClass::getInstance()->readValueIni("XT01-max/danquan").toLong();
    _minValueDan_BMQ_XT_2 = publicClass::getInstance()->readValueIni("XT02-min/danquan").toLong();
    _maxValueDan_BMQ_XT_2 = publicClass::getInstance()->readValueIni("XT02-max/danquan").toLong();

}

xintuoCanForm::~xintuoCanForm()
{
    delete ui;
}

void xintuoCanForm::on_pushButton_0x80_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x80->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("80 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x81_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x81->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("81 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x82_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x82_weizhi->text().simplified().toInt();
    int16_t valuerpm =  ui->lineEdit_0x82_zhuansu->text().simplified().toShort();
    unsigned char out[4] ={};
    unsigned char outrpm[2] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    publicClass::getInstance()->shortArr2Bytes(&valuerpm,2,outrpm);
    QString str =  publicClass::getInstance()->Byte_16(out,4);
    QString strrpm =  publicClass::getInstance()->Byte_16(outrpm,2);

    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("82 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0)+" "
                   +strrpm.split(" ").at(1)+" "
                   +strrpm.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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
        qDebug()<<sendMsg<<":"<<sendbuf[i].ID;

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x9C_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x9C->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("9C ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x9B_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x9B->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("9B ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x86_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit__0x86->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("86 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        qDebug()<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,8)<<"HHHHHHHHHHHHHHHHHHHHHHH";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x87_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x87->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("87 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {
            qDebug()<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,8);
        }
    }
}

void xintuoCanForm::on_pushButton_0x88_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x88->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x89_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x89->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("89 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x8f_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x8f->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("8f ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x91_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x91->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("91 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x92_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x92->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("92 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x93_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x93->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("93 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x94_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x94->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("94 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x95_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x95->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("95 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void xintuoCanForm::on_pushButton_0x99_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = ui->comboBox->currentText().simplified();
    QStringList sendMsg;

    int32_t value =  ui->lineEdit_0x99->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16(out,4);


    sendMsg.append(ui->comboBox->currentText().simplified()+" "+QString("99 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));
    for(int i=0;i<sendMsg.size();i++){
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

        flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
void xintuoCanForm::slotRecvxintuoData(UINT id, BYTE *data)
{
    QString datastr = publicClass::getInstance()->Byte_16(data,6);
    if(datastr.split(" ").at(0)==ui->comboBox->currentText().simplified()){
        QString ids = datastr.split(" ").at(1);
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.simplified().toLatin1());
        memcpy(&index,byte.data(),byte.size());
        int32_t value;
        QByteArray bytevalue ;
        QString str ="";
        for(int i = datastr.split(" ").size()-1;i>=2;i--){
            str+=datastr.split(" ").at(i)+" ";
        }
        bytevalue = QByteArray::fromHex(str.toLatin1());
        memcpy(&value,bytevalue.data(),bytevalue.size());
        switch (index)
        {
        case 0x00://读取伺服状态(0:关闭/1:打开)
        {
            ui->label_0x00->setText(QStringLiteral("伺服状态: %1").arg(QString::number(value)));
            break;
        }
        case 0x01:{ //读取电机编码器(1)单圈绝对位置
            ui->label_0x01->setText(QStringLiteral("单圈绝对位置: %1").arg(QString::number(value)));
            break;
        }
        case 0x02:{//读取电机编码器(1)圈数(断电清零)
            QString datastr = publicClass::getInstance()->Byte_16(data,8);
            ui->label_0x02->setText(QStringLiteral("编码器圈数: %1").arg(QString::number(value)));
            break;
        }
        case 0x03:{//读取电机编码器(1)累积位置(断电清零)
            ui->label_0x03->setText(QStringLiteral("编码器累积位置: %1").arg(QString::number(value)));
            _value2 = value;
            break;
        }
        case 0x04:{//读取当前转速(转/分钟)
            ui->label_0x04->setText(QStringLiteral("电机当前转速: %1").arg(QString::number(value)));
            _value1 = value;
            break;
        }
        case 0x05:{//读取 Kp1 比例系数(刚性)
            ui->label_0x05->setText(QStringLiteral("位置环系数(kpl): %1").arg(QString::number(value)));
            break;
        }
        case 0x06:{//读取 Ki1 积分系数(定位)
            ui->label_0x06->setText(QStringLiteral("位置环系数(kil): %1").arg(QString::number(value)));
            break;
        }
        case 0x07:{//读取 Kd1 微分系数(阻尼)
            ui->label_0x07->setText(QStringLiteral("位置环系数(kdl): %1").arg(QString::number(value)));
            break;
        }
        case 0x08:{//读取电机温度
            ui->label_0x08->setText(QStringLiteral("电机温度: %1").arg(QString::number(value)));
            break;
        }
        case 0x09:{//读取故障代码
            ui->label_0x09->setText(QStringLiteral("故障代码: %1").arg(QString::number(value)));
            break;
        }
        case 0x0A:{//读取电机 ID 号
            ui->label_0x0A->setText(QStringLiteral("设备地址: %1").arg(QString::number(value)));
            break;
        }
        case 0x11:{//读取输出轴编码器(2)单圈绝对位置
            ui->label_0x11->setText(QStringLiteral("输出轴绝对位置: %1").arg(QString::number(value)));
            break;
        }
        case 0x28:{//读取驱动电机电流(单位:毫安)
            ui->label_0x28->setText(QStringLiteral("驱动电流: %1").arg(QString::number(value)));
            break;
        }
        case 0x29:{//读取电机运行状态
            ui->label_0x29->setText(QStringLiteral("运行状态: %1").arg(QString::number(value)));
            break;
        }
        case 0x2B:{//读取加速度时间(单位:ms)
            ui->label_0x2B->setText(QStringLiteral("加速度: %1").arg(QString::number(value)));
            break;
        }
        case 0x2C:{//读取减速度时间(单位:ms)
            ui->label_0x2C->setText(QStringLiteral("减速度: %1").arg(QString::number(value)));
            break;
        }
        default:
            break;
        }
    }

}
void xintuoCanForm::slotTimer()
{

    VCI_CAN_OBJ sendbuf;
    bool ok;
    QString id = "02";

    sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

    if((sendbuf.ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
    }
    else//标准帧格式
    {
        sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
    }

    sendbuf.SendType=1;
    sendbuf.TimeFlag=0;
    sendbuf.TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(_valuemsg,sendbuf.Data,&sendbuf.DataLen);
    ULONG flag;

    flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
    //    qDebug()<<publicClass::getInstance()->Byte_16(sendbuf.Data,8)<<"HHHHHHHHHHHHHHHHHHHHHHH";
    _sleep(10);
    if(flag<1)  //发送不正常
    {
        qDebug()<<"error";

    }
    else {

    }

}

void xintuoCanForm::on_pushButton_test_clicked()
{
    //    _timerTest.start(2000);
}


void xintuoCanForm::slotWorkDataBMQ01(QString COM,int32_t duo,int32_t dan)
{
    if(dan<=_minValueDan_BMQ_XT_1){
        QString valuemsg = "01 86 00 00 00 C8";

        VCI_CAN_OBJ sendbuf;
        bool ok;
        QString id = "01";

        sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf.ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf.SendType=1;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(valuemsg,sendbuf.Data,&sendbuf.DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
        //            qDebug()<</*publicClass::getInstance()->Byte_16(sendbuf.Data,8)*/_minValueDan_BMQ_XT_1<<"HHHHHHHHHHHHHHHHHHHHHHH";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
    else if (dan>=_maxValueDan_BMQ_XT_1) {
        QString valuemsg  = "01 86 FF FF FF 38";

        VCI_CAN_OBJ sendbuf;
        bool ok;
        QString id = "01";

        sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf.ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf.SendType=1;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(valuemsg,sendbuf.Data,&sendbuf.DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
        //            qDebug()<</*publicClass::getInstance()->Byte_16(sendbuf.Data,8)*/_maxValueDan_BMQ_XT_1<<"dddddddddd";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
    else {
//        qDebug()<<COM <<duo<<dan<<"111111111111111111";

    }

}
void xintuoCanForm::slotWorkDataBMQ02(QString COM,int32_t duo,int32_t dan)
{
    //02 86 00 00 01 F4 4E A5 //500
    //02 86 FF FF FE 0C 4E A5  //-500

    if(dan<=_minValueDan_BMQ_XT_2){
        _valuemsg = "02 86 00 00 01 F4";

        VCI_CAN_OBJ sendbuf;
        bool ok;
        QString id = "02";

        sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf.ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf.SendType=1;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(_valuemsg,sendbuf.Data,&sendbuf.DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
        //    qDebug()<<publicClass::getInstance()->Byte_16(sendbuf.Data,8)<<"HHHHHHHHHHHHHHHHHHHHHHH";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
    else if (dan>=_maxValueDan_BMQ_XT_2) {
        _valuemsg = "02 86 FF FF FE 0C";

        VCI_CAN_OBJ sendbuf;
        bool ok;
        QString id = "02";

        sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf.ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf.SendType=1;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(_valuemsg,sendbuf.Data,&sendbuf.DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
        //    qDebug()<<publicClass::getInstance()->Byte_16(sendbuf.Data,8)<<"HHHHHHHHHHHHHHHHHHHHHHH";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
    else {
        //        qDebug()<<COM <<duo<<dan<<"22222222222222222222";

    }

}
//停止测试
void xintuoCanForm::on_pushButton_stop_test_clicked()
{
    VCI_CAN_OBJ sendbuf;
    bool ok;
    uint32_t id = 0xff;
    QStringList sendMsg;
    QString strsend ="ff 87 00 00 00 01 ";
    sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

    sendbuf.ID=id&0x7FF;

    sendbuf.SendType=1;
    sendbuf.TimeFlag=0;
    sendbuf.TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(strsend,sendbuf.Data,&sendbuf.DataLen);
    ULONG flag;
    flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
    _sleep(10);
    if(flag<1)  //发送不正常
    {
        qDebug()<<"error";

    }
    else {
        qDebug()<<publicClass::getInstance()->Byte_16(sendbuf.Data,8);
    }

}
