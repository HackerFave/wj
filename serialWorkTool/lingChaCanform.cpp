#include "lingChaCanform.h"
#include "ui_lingChaCanform.h"
#include <QtDebug>
lingChaCanform::lingChaCanform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lingChaCanform)
{
    ui->setupUi(this);
    connect(&_testTimer,SIGNAL(timeout()),this,SLOT(slotTimer()));
}

lingChaCanform::~lingChaCanform()
{
    delete ui;
}

void lingChaCanform::on_pushButton_start_clicked()
{
    switch (ui->comboBox_mode->currentIndex()) {
    case 0:
    {
        sportsMode_jueduiweizhi();
    }
        break;
    case 1:
    {
        sportsMode_xiangduiyundong();
    }
        break;
    case 2:
    {
        sportsMode_lianxuyundong();
    }
        break;
    case 3:
    {
        sportsMode_sudumoshi();
    }
        break;
    case 4:
    {
        sportsMode_lijumoshi();
    }
        break;
    default:
        break;
    }
}

void  lingChaCanform::on_pushButton_stop_clicked()
{
    VCI_CAN_OBJ sendbuf[2];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 84"));//停止运动
    //    sendMsg.append(QString("01 00 00 00 00 00"));//停止使能

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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
/*
 * @brief   :停止使能
 * @author  :tanchuang
 * @date    :2023.04.23
 */
void  lingChaCanform::on_pushButton_disenable_clicked()
{
    VCI_CAN_OBJ sendbuf[2];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 84"));//停止运动
    sendMsg.append(QString("01 00 00 00 00 00"));//停止使能

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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
void  lingChaCanform::sportsMode_jueduiweizhi()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式

    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    memmove(out,&value,4);
    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));//设置加速度为 10000 count/s²

    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    memmove(out2,&value2,4);
    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
                   +str2.split(" ").at(2)+" "
                   +str2.split(" ").at(1)+" "
                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²

    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    memmove(out1,&value1,4);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    sendMsg.append(QString("00 8A ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 8A 00 00 27 10"));

    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能

    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
    unsigned char out3[4] ={};
    memmove(out3,&value3,4);
    QString str3 =  publicClass::getInstance()->Byte_16(out3,4);
    sendMsg.append(QString("00 87 ")+str3.split(" ").at(3)+" "
                   +str3.split(" ").at(2)+" "
                   +str3.split(" ").at(1)+" "
                   +str3.split(" ").at(0));//设置相对位置为 0 count
    //    sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
    /***
     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
     * */
    int32_t value4 =  ui->lineEdit_mubiaoweizhi->text().simplified().toInt();
    unsigned char out4[4] ={};
    memmove(out4,&value4,4);
    QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
    sendMsg.append(QString("00 86 ")+str4.split(" ").at(3)+" "
                   +str4.split(" ").at(2)+" "
                   +str4.split(" ").at(1)+" "
                   +str4.split(" ").at(0));//262144count 相当于180度=262144*（360/524287）
    //    sendMsg.append(QString("00 86 00 04 00 00"));//262144count 相当于180度=262144*（360/524287）
    sendMsg.append(QString("00 83"));//开始运动
    for(int i=0;i<9;i++){
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
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
void  lingChaCanform::sportsMode_xiangduiyundong()
{
    VCI_CAN_OBJ sendbuf[8];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式

    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    memmove(out,&value,4);
    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));//设置加速度为 10000 count/s²

    int32_t value1 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    memmove(out1,&value1,4);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    sendMsg.append(QString("00 89 ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置减速度为 10000 count/s²



    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能//
    int32_t value2 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    memmove(out2,&value2,4);
    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    qDebug()<<"str"<<str2;
    sendMsg.append(QString("00 8A ")+str2.split(" ").at(3)+" "
                   +str2.split(" ").at(2)+" "
                   +str2.split(" ").at(1)+" "
                   +str2.split(" ").at(0));//设置目标速度为 10000 count/s

    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
    unsigned char out3[4] ={};
    memmove(out3,&value3,4);
    QString str3 =  publicClass::getInstance()->Byte_16(out3,4);
    sendMsg.append(QString("00 87 ")+str3.split(" ").at(3)+" "
                   +str3.split(" ").at(2)+" "
                   +str3.split(" ").at(1)+" "
                   +str3.split(" ").at(0));//设置相对位置为 0 count

    sendMsg.append(QString("00 83"));//开始运动

    for(int i=0;i<8;i++){
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
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
//连续模式
void  lingChaCanform::sportsMode_lianxuyundong()
{
    VCI_CAN_OBJ sendbuf[7];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    sendMsg.append(QString("00 8D 00 00 00 00"));//设置运动模式为目标绝对位置模式

    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));//设置加速度为 10000 count/s²
    //    sendMsg.append(QString("00 88 00 00 27 10"));

    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);
    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
                   +str2.split(" ").at(2)+" "
                   +str2.split(" ").at(1)+" "
                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²
    //    sendMsg.append(QString("00 89 00 00 27 10"));

    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    sendMsg.append(QString("00 8A ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 8A 00 00 27 10"));

    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能
    sendMsg.append(QString("00 83"));//开始运动

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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
void  lingChaCanform::sportsMode_sudumoshi()
{
    VCI_CAN_OBJ sendbuf[7];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 02"));//设置控制模式为速度控制
    sendMsg.append(QString("01 12 00 00 00 00"));//设置控制源为不使用
    sendMsg.append(QString("01 FD 00 00 00 00"));//设置模拟量类型为内部使用
    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));//设置加速度为 10000 count/s²
    //    sendMsg.append(QString("00 88 00 00 27 10"));

    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);
    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
                   +str2.split(" ").at(2)+" "
                   +str2.split(" ").at(1)+" "
                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²
    //    sendMsg.append(QString("00 89 00 00 27 10"));

    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    sendMsg.append(QString("01 FE ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 8A 00 00 27 10"));

    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能

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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
void  lingChaCanform::sportsMode_lijumoshi()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 01"));//设置控制模式为位置控制
    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式

    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));//设置加速度为 10000 count/s²
    //    sendMsg.append(QString("00 88 00 00 27 10"));

    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);\




    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
                   +str2.split(" ").at(2)+" "
                   +str2.split(" ").at(1)+" "
                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²
    //    sendMsg.append(QString("00 89 00 00 27 10"));

    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    sendMsg.append(QString("00 8A ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 8A 00 00 27 10"));

    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能

    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
    unsigned char out3[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value3,4,out3);
    QString str3 =  publicClass::getInstance()->Byte_16(out3,4);
    sendMsg.append(QString("00 87 ")+str3.split(" ").at(3)+" "
                   +str3.split(" ").at(2)+" "
                   +str3.split(" ").at(1)+" "
                   +str3.split(" ").at(0));//设置相对位置为 0 count
    //    sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
    /***
     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
     * */
    int32_t value4 =  ui->lineEdit_mubiaoweizhi->text().simplified().toInt();
    unsigned char out4[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value4,4,out4);
    QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
    sendMsg.append(QString("00 86 ")+str4.split(" ").at(3)+" "
                   +str4.split(" ").at(2)+" "
                   +str4.split(" ").at(1)+" "
                   +str4.split(" ").at(0));//262144count 相当于180度=262144*（360/524287）
    //    sendMsg.append(QString("00 86 00 04 00 00"));//262144count 相当于180度=262144*（360/524287）
    sendMsg.append(QString("00 83"));//开始运动

    for(int i=0;i<9;i++){
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
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
//电机使能
//void lingChaCanform::on_pushButton_enable_clicked()
//{
//    //    VCI_CAN_OBJ sendbuf[9];
//    //    bool ok;
//    //    QString id = "643";
//    //    QStringList sendMsg;
//    //    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
//    //    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式

//    //    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
//    //    unsigned char out[4] ={};
//    //    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
//    //    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
//    //    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
//    //                   +str.split(" ").at(2)+" "
//    //                   +str.split(" ").at(1)+" "
//    //                   +str.split(" ").at(0));//设置加速度为 10000 count/s²
//    //    //    sendMsg.append(QString("00 88 00 00 27 10"));

//    //    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
//    //    unsigned char out2[4] ={};
//    //    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);
//    //    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
//    //    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
//    //                   +str2.split(" ").at(2)+" "
//    //                   +str2.split(" ").at(1)+" "
//    //                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²
//    //    //    sendMsg.append(QString("00 89 00 00 27 10"));

//    //    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
//    //    unsigned char out1[4] ={};
//    //    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
//    //    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
//    //    sendMsg.append(QString("00 8A ")+str1.split(" ").at(3)+" "
//    //                   +str1.split(" ").at(2)+" "
//    //                   +str1.split(" ").at(1)+" "
//    //                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
//    //    //    sendMsg.append(QString("00 8A 00 00 27 10"));

//    //    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能

//    //    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
//    //    unsigned char out3[4] ={};
//    //    publicClass::getInstance()->int32Arr2Bytes(&value3,4,out3);
//    //    QString str3 =  publicClass::getInstance()->Byte_16(out3,4);
//    //    sendMsg.append(QString("00 87 ")+str3.split(" ").at(3)+" "
//    //                   +str3.split(" ").at(2)+" "
//    //                   +str3.split(" ").at(1)+" "
//    //                   +str3.split(" ").at(0));//设置相对位置为 0 count
//    //    //    sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
//    //    /***
//    //     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
//    //     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
//    //     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
//    //     * */
//    //    int32_t value4 =  ui->lineEdit_mubiaoweizhi->text().simplified().toInt();
//    //    unsigned char out4[4] ={};
//    //    publicClass::getInstance()->int32Arr2Bytes(&value4,4,out4);
//    //    QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
//    //    sendMsg.append(QString("00 86 ")+str4.split(" ").at(3)+" "
//    //                   +str4.split(" ").at(2)+" "
//    //                   +str4.split(" ").at(1)+" "
//    //                   +str4.split(" ").at(0));//262144count 相当于180度=262144*（360/524287）
//    //    //    sendMsg.append(QString("00 86 00 04 00 00"));//262144count 相当于180度=262144*（360/524287）
//    //    sendMsg.append(QString("00 83"));//开始运动

//    //    for(int i=0;i<9;i++){
//    //        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
//    //        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

//    //        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
//    //        {
//    //            sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
//    //        }
//    //        else//标准帧格式
//    //        {
//    //            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
//    //        }

//    //        sendbuf[i].SendType=1;
//    //        sendbuf[i].TimeFlag=0;
//    //        sendbuf[i].TimeStamp=0;
//    //        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
//    //        ULONG flag;

//    //        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
//    //        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
//    //        _sleep(10);
//    //        if(flag<1)  //发送不正常
//    //        {
//    //            qDebug()<<"error";

//    //        }
//    //        else {

//    //        }
//    //    }
//}
//471090 左
//292569 右
void lingChaCanform::on_pushButton_sudu_clicked()
{
    VCI_CAN_OBJ sendbuf[7];
    bool ok;
    QString id = "643";
    QStringList sendMsg;

    // 00 88 00 00 75 30
    // 00 89 00 00 75 30


    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);

    //    sendMsg.append(QString("00 4E 00 00 00 02"));
    //    sendMsg.append(QString("01 12 00 00 00 00"));
    //    sendMsg.append(QString("01 FD 00 00 00 00"));
    //    sendMsg.append(QString("00 88 00 00 75 30"));
    //    sendMsg.append(QString("00 89 00 00 75 30"));
    sendMsg.append(QString("01 FE ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 83"));//开始运动
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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void lingChaCanform::on_pushButton_xiangdui_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = "643";
    QStringList sendMsg;


    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
    unsigned char out3[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value3,4,out3);
    QString str3 =  publicClass::getInstance()->Byte_16(out3,4);
    sendMsg.append(QString("00 87 ")+str3.split(" ").at(3)+" "
                   +str3.split(" ").at(2)+" "
                   +str3.split(" ").at(1)+" "
                   +str3.split(" ").at(0));//设置相对位置为 0 count
    sendMsg.append(QString("00 83"));//开始运动
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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void lingChaCanform::on_pushButton_juedui_clicked()
{
    VCI_CAN_OBJ sendbuf[9];
    bool ok;
    QString id = "643";
    QStringList sendMsg;


    //    sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
    /***
     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
     * */
    int32_t value4 =  ui->lineEdit_mubiaoweizhi->text().simplified().toInt();
    unsigned char out4[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value4,4,out4);
    QString str4 =  publicClass::getInstance()->Byte_16(out4,4);
    sendMsg.append(QString("00 86 ")+str4.split(" ").at(3)+" "
                   +str4.split(" ").at(2)+" "
                   +str4.split(" ").at(1)+" "
                   +str4.split(" ").at(0));//262144count 相当于180度=262144*（360/524287）
    sendMsg.append(QString("00 83"));//开始运动

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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}
void lingChaCanform::slotRecvLingChaData(UINT id, BYTE *data)
{

    //        sendMsg.append(QString("40 6C 60 00 00 00 00 00"));//获取实际速度
    //        sendMsg.append(QString("40 64 60 00 00 00 00 00"));//获取当前位置
    //        sendMsg.append(QString("40 3F 60 00 00 00 00 00"));//错误码
    //        sendMsg.append(QString("40 78 60 00 00 00 00 00"));//电机实际电流
    //        sendMsg.append(QString("40 77 60 00 00 00 00 00"));//电机实际扭矩
    //        sendMsg.append(QString("40 40 22 00 00 00 00 00"));//电机编码器位置
    //        sendMsg.append(QString("40 A2 22 00 00 00 00 00"));//驱动器温度
    //        sendMsg.append(QString("40 69 60 00 00 00 00 00"));//速度传感器实际值
    //        sendMsg.append(QString("40 79 60 00 00 00 00 00"));//直流链路电路电压
    //        sendMsg.append(QString("40 7c 60 00 00 00 00 00"));//原点偏移
    if(id==0x583){
        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(1)+" "+datastr.split(" ").at(2);
        uint16_t index;
        QByteArray byte = QByteArray::fromHex(ids.simplified().toLatin1());
        memcpy(&index,byte.data(),byte.size());
        int32_t value;
        QByteArray bytevalue ;
        QString str ="";
        for(int i = 4;i<datastr.split(" ").size();i++){
            str+=datastr.split(" ").at(i)+" ";
        }
        bytevalue = QByteArray::fromHex(str.toLatin1());
        memcpy(&value,bytevalue.data(),bytevalue.size());
        switch (index)
        {
        case 0x606c:
        {//实际速度

            //            ui->label_sudu->setText(QStringLiteral("实际速度：%1").arg(QString::number(value)));
            break;
        }
        case 0x6064:{ //获取当前位置
            ui->label_weizhi->setText(QStringLiteral("当前位置：%1").arg(QString::number(value)));
            _bmq = value;
            break;
        }
        case 0x603F:{//错误码
            QString datastr = publicClass::getInstance()->Byte_16(data,8);
            ui->label_errorCode->setText(QStringLiteral("错误码：%1").arg(/*QString::number(value)*/str));
            break;
        }
        case 0x6078:{//电机实际电流
            ui->label_dianliu->setText(QStringLiteral("当前电流：%1").arg(QString::number(value*25000/1000/1000)));
            break;
        }
        case 0x6075:{//电机额定电流
            _valuemA = value;
            ui->label_edingdianliu->setText(QStringLiteral("额定电流：%1").arg(QString::number(value)));
            break;
        }
        case 0x6077:{//电机实际扭矩
            break;
        }
        case 0x2240:{//电机编码器位置
            ui->label_weizhi_2->setText(QStringLiteral("电机编码器位置：%1").arg(QString::number(value)));
            break;
        }
        case 0x22A2:{//驱动器温度
            ui->label_wendu->setText(QStringLiteral("驱动器温度：%1").arg(QString::number(value)));
            break;
        }
        case 0x6069:{//速度传感器实际值
            ui->label_sudu->setText(QStringLiteral("实际速度：%1").arg(QString::number(value)));
            break;
        }
        case 0x6079:{//直流链路电路电压
            ui->label_dianya->setText(QStringLiteral("直流链路电路电压：%1").arg(QString::number(value)));
            break;
        }
        case 0x607C:{//原点偏移
            ui->label_yuandianpianyi->setText(QStringLiteral("原点偏移: %1").arg(QString::number(value)));
            break;
        }
        default:
            break;
        }
    }

}

void lingChaCanform::slotTimer()
{
    //471090 左
    //292569 右
    if(_bmq>=471090){
        VCI_CAN_OBJ sendbuf[7];
        bool ok;
        QString id = "643";
        QStringList sendMsg;

        // 00 88 00 00 75 30
        // 00 89 00 00 75 30


        int32_t value1 = -5000 /*(ui->lineEdit_mubiaosudu->text().simplified().toInt())*/;
        unsigned char out1[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
        QString str1 =  publicClass::getInstance()->Byte_16(out1,4);

        //    sendMsg.append(QString("00 4E 00 00 00 02"));
        //    sendMsg.append(QString("01 12 00 00 00 00"));
        //    sendMsg.append(QString("01 FD 00 00 00 00"));
        //    sendMsg.append(QString("00 88 00 00 75 30"));
        //    sendMsg.append(QString("00 89 00 00 75 30"));
        sendMsg.append(QString("01 FE ")+str1.split(" ").at(3)+" "
                       +str1.split(" ").at(2)+" "
                       +str1.split(" ").at(1)+" "
                       +str1.split(" ").at(0));//设置目标速度为 10000 count/s
        //    sendMsg.append(QString("00 83"));//开始运动
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

            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"error";

            }
            else {

            }
        }
    }
    else if (_bmq<= 292569) {
        VCI_CAN_OBJ sendbuf[7];
        bool ok;
        QString id = "643";
        QStringList sendMsg;

        // 00 88 00 00 75 30
        // 00 89 00 00 75 30


        int32_t value1 =  /*ui->lineEdit_mubiaosudu->text().simplified().toInt()*/5000;
        unsigned char out1[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
        QString str1 =  publicClass::getInstance()->Byte_16(out1,4);

        //    sendMsg.append(QString("00 4E 00 00 00 02"));
        //    sendMsg.append(QString("01 12 00 00 00 00"));
        //    sendMsg.append(QString("01 FD 00 00 00 00"));
        //    sendMsg.append(QString("00 88 00 00 75 30"));
        //    sendMsg.append(QString("00 89 00 00 75 30"));
        sendMsg.append(QString("01 FE ")+str1.split(" ").at(3)+" "
                       +str1.split(" ").at(2)+" "
                       +str1.split(" ").at(1)+" "
                       +str1.split(" ").at(0));//设置目标速度为 10000 count/s
        //    sendMsg.append(QString("00 83"));//开始运动
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

            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"error";

            }
            else {

            }
        }
    }
}
void lingChaCanform::on_pushButton_lianxu_clicked()
{
    VCI_CAN_OBJ sendbuf[7];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    sendMsg.append(QString("00 8D 00 00 00 00"));//设置运动模式为目标绝对位置模式

    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
                   +str.split(" ").at(2)+" "
                   +str.split(" ").at(1)+" "
                   +str.split(" ").at(0));//设置加速度为 10000 count/s²
    //    sendMsg.append(QString("00 88 00 00 27 10"));

    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);
    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
                   +str2.split(" ").at(2)+" "
                   +str2.split(" ").at(1)+" "
                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²
    //    sendMsg.append(QString("00 89 00 00 27 10"));

    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    sendMsg.append(QString("00 8A ")+str1.split(" ").at(3)+" "
                   +str1.split(" ").at(2)+" "
                   +str1.split(" ").at(1)+" "
                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 8A 00 00 27 10"));


    sendMsg.append(QString("00 83"));//开始运动

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

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error";

        }
        else {

        }
    }
}

void lingChaCanform::on_pushButton_ceshi_clicked()
{
    _testTimer.start(500);
}

void lingChaCanform::on_pushButton_xiangduienable_clicked()
{
    VCI_CAN_OBJ sendbuf[8];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    QVector<char*> dataVec;

    //设置控制模式为位置控制
    sendbuf[0].Data[0] = 0x00;
    sendbuf[0].Data[1] = 0x4E;
    sendbuf[0].Data[2] = 0x00;
    sendbuf[0].Data[3] = 0x00;
    sendbuf[0].Data[4] = 0x00;
    sendbuf[0].Data[5] = 0x03;
    //    sendbuf[0].Data[6] = 0x00;
    //    sendbuf[0].Data[7] = 0x00;
    //设置运动模式为目标绝对位置模式
    sendbuf[1].Data[0] = 0x00;
    sendbuf[1].Data[1] = 0x8D;
    sendbuf[1].Data[2] = 0x00;
    sendbuf[1].Data[3] = 0x00;
    sendbuf[1].Data[4] = 0x00;
    sendbuf[1].Data[5] = 0x01;
    //    sendbuf[1].Data[6] = 0x00;
    //    sendbuf[1].Data[7] = 0x00;

    //设置加速度为 10000 count/s²
    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    unsigned char out[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    sendbuf[2].Data[0] = 0x00;
    sendbuf[2].Data[1] = 0x88;
    sendbuf[2].Data[2] = out[3];
    sendbuf[2].Data[3] = out[2];;
    sendbuf[2].Data[4] = out[1];;
    sendbuf[2].Data[5] = out[0];;
    //    sendbuf[2].Data[6] = 0x00;
    //    sendbuf[2].Data[7] = 0x00;

    //设置减速度为 10000 count/s²
    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);
    sendbuf[3].Data[0] = 0x00;
    sendbuf[3].Data[1] = 0x89;
    sendbuf[3].Data[2] = out2[3];
    sendbuf[3].Data[3] = out2[2];;
    sendbuf[3].Data[4] = out2[1];;
    sendbuf[3].Data[5] = out2[0];;
    //    sendbuf[3].Data[6] = 0x00;
    //    sendbuf[3].Data[7] = 0x00;
    //设置目标速度为 10000 count/s
    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    unsigned char out1[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    sendbuf[4].Data[0] = 0x00;
    sendbuf[4].Data[1] = 0x8A;
    sendbuf[4].Data[2] = out1[3];
    sendbuf[4].Data[3] = out1[2];;
    sendbuf[4].Data[4] = out1[1];;
    sendbuf[4].Data[5] = out1[0];;
    //    sendbuf[4].Data[6] = 0x00;
    //    sendbuf[4].Data[7] = 0x00;
    //电机使能
    sendbuf[5].Data[0] = 0x01;
    sendbuf[5].Data[1] = 0x00;
    sendbuf[5].Data[2] = 0x00;
    sendbuf[5].Data[3] = 0x00;
    sendbuf[5].Data[4] = 0x00;
    sendbuf[5].Data[5] = 0x01;
    //    sendbuf[5].Data[6] = 0x00;
    //    sendbuf[5].Data[7] = 0x00;
    //设置相对位置为
    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
    unsigned char out3[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&value3,4,out3);
    sendbuf[6].Data[0] = 0x00;
    sendbuf[6].Data[1] = 0x87;
    sendbuf[6].Data[2] = out3[3];
    sendbuf[6].Data[3] = out3[2];;
    sendbuf[6].Data[4] = out3[1];;
    sendbuf[6].Data[5] = out3[0];;
    //    sendbuf[6].Data[6] = 0x00;
    //    sendbuf[6].Data[7] = 0x00;
    //开始运动
    sendbuf[7].Data[0] = 0x00;
    sendbuf[7].Data[1] = 0x83;
    //    sendbuf[7].Data[2] = 0x00;
    //    sendbuf[7].Data[3] = 0x00;
    //    sendbuf[7].Data[4] = 0x00;
    //    sendbuf[7].Data[5] = 0x00;
    //    sendbuf[7].Data[6] = 0x00;
    //    sendbuf[7].Data[7] = 0x00;

    //    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    //    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式

    //    int32_t  value =  ui->lineEdit_jiasudu->text().simplified().toInt();
    //    unsigned char out[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&value,4,out);
    //    QString str =  publicClass::getInstance()->Byte_16((unsigned char *)out,4);
    //    sendMsg.append(QString("00 88 ")+str.split(" ").at(3)+" "
    //                   +str.split(" ").at(2)+" "
    //                   +str.split(" ").at(1)+" "
    //                   +str.split(" ").at(0));//设置加速度为 10000 count/s²
    //    sendMsg.append(QString("00 88 00 00 27 10"));

    //    int32_t value2 =  ui->lineEdit_jiansudu->text().simplified().toInt();
    //    unsigned char out2[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&value2,4,out2);
    //    QString str2 =  publicClass::getInstance()->Byte_16(out2,4);
    //    sendMsg.append(QString("00 89 ")+str2.split(" ").at(3)+" "
    //                   +str2.split(" ").at(2)+" "
    //                   +str2.split(" ").at(1)+" "
    //                   +str2.split(" ").at(0));//设置减速度为 10000 count/s²
    //    sendMsg.append(QString("00 89 00 00 27 10"));

    //    int32_t value1 =  ui->lineEdit_mubiaosudu->text().simplified().toInt();
    //    unsigned char out1[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&value1,4,out1);
    //    QString str1 =  publicClass::getInstance()->Byte_16(out1,4);
    //    sendMsg.append(QString("00 8A ")+str1.split(" ").at(3)+" "
    //                   +str1.split(" ").at(2)+" "
    //                   +str1.split(" ").at(1)+" "
    //                   +str1.split(" ").at(0));//设置目标速度为 10000 count/s
    //    sendMsg.append(QString("00 8A 00 00 27 10"));

    //    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能

    //    int32_t value3 =  ui->lineEdit_xiangduiweizhi->text().simplified().toInt();
    //    unsigned char out3[4] ={};
    //    publicClass::getInstance()->int32Arr2Bytes(&value3,4,out3);
    //    QString str3 =  publicClass::getInstance()->Byte_16(out3,4);
    //    sendMsg.append(QString("00 87 ")+str3.split(" ").at(3)+" "
    //                   +str3.split(" ").at(2)+" "
    //                   +str3.split(" ").at(1)+" "
    //                   +str3.split(" ").at(0));//设置相对位置为 0 count

    //    sendMsg.append(QString("00 83"));//开始运动
    //    for(int i = 0;i<sendMsg.size();i++){
    //        publicClass::getInstance()->sendCanBuf(id,sendMsg[i],0);
    //    }
    for(int i=0;i<8;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        //        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        //        {
        //            sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        //        }
        //        else//标准帧格式
        //        {
        sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
        //        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        //        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"error"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen);

        }
        else {
            //          qDebug()<<  publicClass::getInstance()->Byte_16(sendbuf[i].Data,8)<<"XXXXXXXXXXXXXXX";
        }
        //        qDebug()<<  publicClass::getInstance()->Byte_16(sendbuf[i].Data,8)<<"XXXXXXXXXXXXXXX";
    }
}
