#include "rmdSettingForm.h"
#include "ui_rmdSettingForm.h"
#include <QtDebug>
rmdSettingForm::rmdSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rmdSettingForm)
{
    ui->setupUi(this);
    QStringList list =  publicClass::getInstance()->readValueIni("index/machineId").simplified().split(":");
    for(auto i :list)
        ui->comboBox_id->addItem(i);
    ui->textEdit_rmd_data->document()->setMaximumBlockCount(1000);
}

rmdSettingForm::~rmdSettingForm()
{
    delete ui;
}

void rmdSettingForm::on_pushButton_write_ram_clicked()
{

    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "31 00";
    datastr = datastr+ " "+ QString::number(ui->lineEdit_weizhi_p->text().simplified().toShort(), 16) ;
    datastr  =datastr+ " "+ QString::number(ui->lineEdit_weizhi_i->text().simplified().toShort(), 16) ;
    datastr = datastr+ " "+ QString::number(ui->lineEdit_sudu_p->text().simplified().toShort(), 16) ;
    datastr = datastr+ " "+ QString::number(ui->lineEdit_sudu_i->text().simplified().toShort(), 16) ;
    datastr  =datastr+ " "+ QString::number(ui->lineEdit_zhuanju_p->text().simplified().toShort(), 16) ;
    datastr = datastr+ " "+ QString::number(ui->lineEdit_zhuanju_i->text().simplified().toShort(), 16) ;
    sendMsg.append(datastr.simplified());

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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_rom_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "32 00";
    datastr = datastr+ " "+ QString::number(ui->lineEdit_weizhi_p->text().simplified().toShort(), 16) ;
    datastr  =datastr+ " "+ QString::number(ui->lineEdit_weizhi_i->text().simplified().toShort(), 16) ;
    datastr = datastr+ " "+ QString::number(ui->lineEdit_sudu_p->text().simplified().toShort(), 16) ;
    datastr = datastr+ " "+ QString::number(ui->lineEdit_sudu_i->text().simplified().toShort(), 16) ;
    datastr  =datastr+ " "+ QString::number(ui->lineEdit_zhuanju_p->text().simplified().toShort(), 16) ;
    datastr = datastr+ " "+ QString::number(ui->lineEdit_zhuanju_i->text().simplified().toShort(), 16) ;
    sendMsg.append(datastr.simplified());

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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}
void rmdSettingForm::slotRecvRmdData(UINT id, BYTE *data)
{
    if(QString::number(id,16)==ui->comboBox_id->currentText()){
        ui->textEdit_rmd_data->append(QString("[ID: %1]").arg(QString::number(id,16).toUpper())+ publicClass::getInstance()->Byte_16(data,8).simplified());

        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(0);
        //        QString valuestr = datastr.split(" ").at(4) +" "+ datastr.split(" ").at(5)+" "+ datastr.split(" ").at(6)+" "+ datastr.split(" ").at(7);
        //        QByteArray array = datastr.toLatin1();
        uint8_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        memcpy(&index,byte.data(),byte.size());
        switch (index) {
        case 0x30:{//读取PID
            uint8_t value;
            QByteArray byte = QByteArray::fromHex(datastr.split(" ").at(2).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_weizhi_p->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(3).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_weizhi_i->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_sudu_p->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(5).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_sudu_i->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(6).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_zhuanju_p->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(7).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_zhuanju_i->setText(QString("%1").arg(value));

            break;
        }
        case 0x33:{ //读取加速度
            int32_t value;
            QByteArray byte ;
            QString str ="";
            for(int i = 4;i<datastr.split(" ").size();i++){
                str+=datastr.split(" ").at(i)+" ";
            }
            byte = QByteArray::fromHex(str.toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_jiasudu->setText(QString("%1").arg(value));
            break;
        }
        case 0x90:{//读取编码器数据
            uint16_t value;
            QByteArray byte ;
            byte = QByteArray::fromHex(datastr.split(" ").at(2).toLatin1()+" "+datastr.split(" ").at(3).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_bmq_weizhi->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1()+" "+datastr.split(" ").at(5).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_bmq_yuanshiweizhi->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(6).toLatin1()+" "+datastr.split(" ").at(7).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_bmq_0pian->setText(QString("%1").arg(value));
            break;
        }
        case 0x92:{//读取多圈角度命令
            int64_t value;

            QByteArray byte ;
            QString str ="";
            for(int i = 1;i<datastr.split(" ").size();i++){
                str+=datastr.split(" ").at(i)+" ";
            }
            unsigned char s ;
            byte= QByteArray::fromHex(datastr.split(" ").at(6).toLatin1());
            memcpy(&s,byte.data(),byte.size());
            if(s^0xff==0){
                str=str.simplified()+" "+"FF";
            }

            byte = QByteArray::fromHex(str.toLatin1());

            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_duoquanjiaodu->setText(QString("%1").arg((value)*0.01));
            break;
        }
        case 0x94:{//读取单圈角度
            uint16_t value;

            QByteArray byte ;
            QString str ="";
            for(int i = 6;i<datastr.split(" ").size();i++){
                str+=datastr.split(" ").at(i)+" ";
            }
            byte = QByteArray::fromHex(str.toLatin1());

            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_danquanjiaodu->setText(QString("%1").arg(value*0.01));
            break;
        }
        case 0x9a:{//读取电机状态1与错误标致
            int8_t value1;
            QByteArray byte ;
            byte = QByteArray::fromHex(datastr.split(" ").at(1).toLatin1());
            memcpy(&value1,byte.data(),byte.size());
            ui->lineEdit_wendu->setText(QString("%1").arg(value1));//电机温度

            uint16_t value2;//电压
            byte = QByteArray::fromHex(datastr.split(" ").at(3).toLatin1()+" "+datastr.split(" ").at(4).toLatin1());
            memcpy(&value2,byte.data(),byte.size());
            ui->lineEdit_dianya->setText(QString("%1").arg(value2*0.1));

            uint8_t value3;
            byte = QByteArray::fromHex(datastr.split(" ").at(7).toLatin1());
            memcpy(&value3,byte.data(),byte.size());
            //            ui->lineEdit_bmq_0pian->setText(QString("%1").arg(value3));
            ui->label_errorCode->setText(QStringLiteral("     错误码:%1").arg(value3));
            break;
        }
        case 0x9c:{//读取电机状态2
            int8_t value1;
            QByteArray byte ;
            byte = QByteArray::fromHex(datastr.split(" ").at(1).toLatin1());
            memcpy(&value1,byte.data(),byte.size());
            ui->lineEdit_wendu->setText(QString("%1").arg(value1));//电机温度

            int16_t value2;
            byte = QByteArray::fromHex(datastr.split(" ").at(2).toLatin1()+" "+datastr.split(" ").at(3).toLatin1());
            memcpy(&value2,byte.data(),byte.size());
            ui->lineEdit_zhuanju_dianliu->setText(QString("%1").arg(value2));//转矩电流

            int16_t value3;
            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1()+" "+datastr.split(" ").at(5).toLatin1());
            memcpy(&value3,byte.data(),byte.size());
            ui->lineEdit_dianji_sudu->setText(QString("%1").arg(value3));//电机转速

            uint16_t value4;
            byte = QByteArray::fromHex(datastr.split(" ").at(6).toLatin1()+" "+datastr.split(" ").at(7).toLatin1());
            memcpy(&value4,byte.data(),byte.size());
            ui->lineEdit_bmq->setText(QString("%1").arg(value4));//编码器值
            break;
        }
        case 0x9d:{//读取电机状态3
            int16_t value;
            QByteArray byte ;
            byte = QByteArray::fromHex(datastr.split(" ").at(2).toLatin1()+" "+datastr.split(" ").at(3).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_dianliu_A->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(4).toLatin1()+" "+datastr.split(" ").at(5).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_dianliu_B->setText(QString("%1").arg(value));

            byte = QByteArray::fromHex(datastr.split(" ").at(6).toLatin1()+" "+datastr.split(" ").at(7).toLatin1());
            memcpy(&value,byte.data(),byte.size());
            ui->lineEdit_dianliu_C->setText(QString("%1").arg(value));
            break;
        }
        default:
            break;
        }
    }
}

void rmdSettingForm::on_checkBox_read_stateChanged(int arg1)
{

    emit signalDisConnect(arg1);

}

void rmdSettingForm::on_pushButton_write_jiasudu_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "34 00 00 00";
    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit->text().toInt();
    memmove(s,&value,4);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4) ;

    sendMsg.append(datastr.simplified());
    qDebug()<<datastr<<publicClass::getInstance()->Byte_16(s,4);
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_0pian_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "91 00 00 00 00 00";
    unsigned char s[2]={0,0} ;
    uint16_t value = ui->lineEdit_2->text().toUShort();
    memmove(s,&value,2);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2) ;

    sendMsg.append(datastr.simplified());
    qDebug()<<datastr<<publicClass::getInstance()->Byte_16(s,2);
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_clean_err_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "9B 00 00 00 00 00 00 00";
    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_close_dianji_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "80 00 00 00 00 00 00 00";
    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_stop_dianji_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "81 00 00 00 00 00 00 00";
    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_start_dianji_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "88 00 00 00 00 00 00 00";
    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}
void rmdSettingForm::on_pushButton_zhuanjubihuan_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A1 00 00 00";
    unsigned char s[2]={0,0} ;
    int16_t value = ui->lineEdit_4->text().toShort();
    memmove(s,&value,2);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+"00 00" ;

    sendMsg.append(datastr.simplified());
    qDebug()<<datastr<<publicClass::getInstance()->Byte_16(s,2);
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_sudubihuan_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A2 00 00 00";
    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_5->text().toInt()*100;
    memmove(s,&value,4);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}
void rmdSettingForm::on_pushButton_write_1_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A3 00 00 00";
    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_6->text().toInt()*100;
    memmove(s,&value,4);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_2_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A4 00 00 00";
    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_7->text().toInt()*100;
    memmove(s,&value,4);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_3_shun_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A5 00 00 00";
    unsigned char s[2]={0,0} ;
    uint16_t value = ui->lineEdit_8->text().toUShort()*100;
    memmove(s,&value,2);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+"00 00" ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_3_ni_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A5 01 00 00";
    unsigned char s[2]={0,0} ;
    uint16_t value = ui->lineEdit_9->text().toUShort()*100;
    memmove(s,&value,2);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+"00 00" ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_4_shun_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A6 00";
    unsigned char s[2]={0,0} ;
    unsigned char s1[2]={0,0} ;

    uint16_t valueMaxSpeed = ui->lineEdit_maxSpeed->text().toUShort();
    uint16_t valueAngle = ui->lineEdit_10->text().toUShort()*100;
    memmove(s,&valueMaxSpeed,2);
    memmove(s1,&valueAngle,2);
    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+publicClass::getInstance()->Byte_16(s1,2).simplified()+" "+"00 00" ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_4_ni_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A6 01";
    unsigned char s[2]={0,0} ;
    unsigned char s1[2]={0,0} ;

    uint16_t valueMaxSpeed = ui->lineEdit_maxSpeed->text().toUShort();
    uint16_t valueAngle = ui->lineEdit_11->text().toUShort()*100;
    memmove(s,&valueMaxSpeed,2);
    memmove(s1,&valueAngle,2);
    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+publicClass::getInstance()->Byte_16(s1,2).simplified()+" "+"00 00" ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_5_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A7 00 00 00";
    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_12->text().toInt()*100;
    memmove(s,&value,4);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_write_6_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ui->comboBox_id->currentText();
    QStringList sendMsg;
    bool ok;
    QString datastr = "A8 00";
    unsigned char s[2]={0,0} ;
    uint16_t valueMaxSpeed = ui->lineEdit_maxSpeed->text().toUShort();//最大加速度

    unsigned char s1[4]={0,0,0,0} ;
    int32_t valueAngle = ui->lineEdit_13->text().toInt()*100;

    memmove(s,&valueMaxSpeed,2);
    memmove(s1,&valueAngle,4);
    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,2).simplified()+" "+publicClass::getInstance()->Byte_16(s1,4).simplified() ;

    sendMsg.append(datastr.simplified());
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

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[0].Data,8)
                    <<QString::number(sendbuf->ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}

void rmdSettingForm::on_pushButton_2_clicked()
{
    VCI_CAN_OBJ sendbuf[2];
    QString id = "141:143";
    QStringList sendMsg;
    bool ok;
    QString datastr = "A3 00 00 00";
    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_6->text().toInt()*100;
    memmove(s,&value,4);

    datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

    sendMsg.append(datastr.simplified());
    sendMsg.append(datastr.simplified());
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(id.split(":").at(i).toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);

        ULONG flag =VCI_Transmit(publicClass::getInstance()->readValueIni("index/devtype").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/DevIndex").toUInt(),
                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");

        }
        else {
            qDebug()<<QStringLiteral("写入成功")<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,8)
                    <<QString::number(sendbuf[i].ID,16).toUpper()
                   <<sendbuf[i].DataLen;
        }
    }
}
