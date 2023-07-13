#include "yankongDataForm.h"
#include "ui_yankongDataForm.h"
#include <QtDebug>
#include "publicclass.h"



yankongDataForm::yankongDataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yankongDataForm)
{
    ui->setupUi(this);
    p_func=  static_cast<func*>(initchassis());
    _groupBtn.addButton(ui->radioButton_up);
    _groupBtn.addButton(ui->radioButton_back);
    ui->radioButton_up->setChecked(true);
    //    p_func->control("AA B0 03 01 01 00 00 0D 0A");
}

yankongDataForm::~yankongDataForm()
{
    delete ui;
}

void yankongDataForm::on_pushButton_zhengzhuan_clicked()
{
#if CANDEV_CX
    VCI_CAN_OBJ sendbuf[8];
#endif
#if CANDEV_GC
    CAN_OBJ sendbuf[8];
#endif
    bool ok;
    QString id = "602";
    QStringList sendMsg;
    sendMsg.clear();

    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_value->text().toInt();
    memmove(s,&value,4);
    //    sendMsg.append("2B 40 60 00 01 00 00 00");
    //    sendMsg.append("2B 40 60 00 00 00 00 00");
    //    sendMsg.append("2B 40 60 00 06 00 00 00");
    //    sendMsg.append("60 40 60 00 00 00 00 00");
    sendMsg.append(QString("23 7A 60 00 %1").arg(publicClass::getInstance()->Byte_16(s,4).simplified()));
    //    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));
    sendMsg.append(QString("40 41 60 00 01 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2f 60 60 00 01 00 00 00"));

    sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));
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
        _sleep(10);
#if CANDEV_CX
        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
#if CANDEV_GC
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
        if(flag<1)  //发送不正常
        {

            qDebug()<<"[ID:602]"<<"[SEND ERROR:"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified()<<"]";

        }
        else {
            //            qDebug()<<  publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified();
            ui->textEdit->append("send"+publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified());
        }
    }

}

void yankongDataForm::on_pushButton_fanzhuan_clicked()
{    

#if CANDEV_CX
    VCI_CAN_OBJ sendbuf[7];
#endif
#if CANDEV_GC
    CAN_OBJ sendbuf[7];
#endif
    bool ok;
    QString id = "602";
    QStringList sendMsg;
    sendMsg.clear();

    unsigned char s[4]={0,0,0,0} ;
    int32_t value = - ui->lineEdit_value->text().toInt();
    memmove(s,&value,4);

    sendMsg.append(QString("23 7A 60 00 %1").arg(publicClass::getInstance()->Byte_16(s,4).simplified()));

    //sendMsg.append() 40 41 60 00 01 00 00 00
    //[Write]No: P1901 Addr: 0x6040 Value: 128 控制字
    //Send:00 00 00 06 02 08 2b 40 60 00 80 00 00 00
    //[Write]No: P1901 Addr: 0x6040 Value: 6 控制字
    //Send:00 00 00 06 02 08 2b 40 60 00 06 00 00 00
    //[Write]No: P1902 Addr: 0x6060 Value: 1 电机启动
    //Send:00 00 00 06 02 08 2f 60 60 00 01 00 00 00
    //[Write]No: P1901 Addr: 0x6040 Value: 79 控制字
    //Send:00 00 00 06 02 08 2b 40 60 00 4f 00 00 00
    //[Write]No: P1901 Addr: 0x6040 Value: 95 控制字
    //Send:00 00 00 06 02 08 2b 40 60 00 5f 00 00 00

    sendMsg.append(QString("40 41 60 00 01 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2f 60 60 00 01 00 00 00"));

    sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));
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
        _sleep(10);
#if CANDEV_CX
        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
#if CANDEV_GC
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");
            //                qDebug()<<"error"<<id<<_CanId;

        }
        else {
            //            qDebug()<<  publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified();
            ui->textEdit->append("send"+publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified());
        }
    }

}
void yankongDataForm::slotRecvData(UINT id, BYTE *data)
{
    //    qDebug()<< QString("[ID: %1]").arg(QString::number(id,16).toUpper())+ publicClass::getInstance()->Byte_16(data,8).simplified();

    if(id == 0x582){
        QString dataStr = publicClass::getInstance()->Byte_16(data,8).simplified().simplified();
        dataStr = dataStr.split(" ").at(4)+" "+dataStr.split(" ").at(5)+" "+dataStr.split(" ").at(6)+" "+dataStr.split(" ").at(7);
        QByteArray data = QByteArray::fromHex(dataStr.toLatin1());
        //        qDebug()<<dataStr<<"XXXXXXXXXXXXXXXXXXXXXX";
        int32_t value;
        memmove(&value,data.data(),data.size());
        ui->label_bmq->setText(QString::number(value));
    }
}

void yankongDataForm::on_pushButton_stop_clicked()
{
#if CANDEV_CX
    VCI_CAN_OBJ sendbuf[5];
#endif
#if CANDEV_GC
    CAN_OBJ sendbuf[5];
#endif
    bool ok;
    QString id = "602";
    QStringList sendMsg;
    sendMsg.clear();

    unsigned char s[4]={0,0,0,0} ;
    int32_t value = ui->lineEdit_value->text().toInt();
    memmove(s,&value,4);

    sendMsg.append("2B 40 60 00 01 00 00 00");
    sendMsg.append("2B 40 60 00 00 00 00 00");
    sendMsg.append("2B 40 60 00 06 00 00 00");
    sendMsg.append("2B 40 60 00 07 00 00 00");
    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));
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
        _sleep(10);
#if CANDEV_CX
        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
#if CANDEV_GC
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
#endif
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");
            //                qDebug()<<"error"<<id<<_CanId;

        }
        else {
            //            qDebug()<<  publicClass::getInstance()->Byte_16(sendbuf[i].Data,8).simplified();
        }
    }

}

void yankongDataForm::on_pushButton_start_clicked()
{
    //    p_func->control(ui->lineEdit->text().simplified());
}

void yankongDataForm::on_pushButton_stop_2_clicked()
{
        p_func->control("AA AB 02 00 00 00 0D 0A");
}
void int32Arr2Bytes(int32_t* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 4; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void yankongDataForm::on_horizontalSlider_sliderMoved(int position)
{
    //    //    int32_t ss = arr.toInt();
    ui->label_value->setText(QString::number(position));
    unsigned char out[4] ={};
    int32Arr2Bytes(&position,4,out);
    QByteArray byArr((const char*)out,4);

    QStringList ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4).split(" ");
    //    //    ui->textEdit_sum->append(QString("[result:11111111111]:%1").arg(ssss));



    //    canBufstruct bjs;
    //    memmove(&bjs,&vc,sizeof (canBufstruct));
    //    _canbuf.enqueue(vc);


    QString send =QString("AA AB 02 ")+ssss[1]+" "+ssss[0]+ " 00 0D 0A";

    _data485.enqueue(send);
    std::lock_guard<std::mutex> lgd(_mutex);
    QString str = _data485.dequeue();
    ui->lineEdit->setText(str);
    p_func->control(str);

}

//void yankongDataForm::on_horizontalSlider_actionTriggered(int action)
//{
//    qDebug()<<action<<"XXXXXXXXXXXXXXXXXXXXXXX";
//    //    //    int32_t ss = arr.toInt();
//    ui->label_value->setText(QString::number(action));
//    unsigned char out[4] ={};
//    int32Arr2Bytes(&action,4,out);
//    QByteArray byArr((const char*)out,4);

//    QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
//    //    //    ui->textEdit_sum->append(QString("[result:11111111111]:%1").arg(ssss));
//    qDebug()<<ssss<<"XXXXXXXXXXXXXXXXXX";

//    QString str;
//    memmove(&str,&ssss,sizeof (ssss));
//}

//前进
void yankongDataForm::on_radioButton_up_clicked()
{
    p_func->control("AA B0 03 01 01 00 00 0D 0A");
}
//后退
void yankongDataForm::on_radioButton_back_clicked()
{
    p_func->control("AA B0 03 01 01 01 00 0D 0A");

}
void yankongDataForm::setValue(int32_t value)
{
    ui->label_bmq->setText(QString::number(value));
}
