#include "multipleMotorTestForm.h"
#include "ui_multipleMotorTestForm.h"
#include <QtDebug>
multipleMotorTestForm::multipleMotorTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::multipleMotorTestForm)
{
    ui->setupUi(this);
}

multipleMotorTestForm::~multipleMotorTestForm()
{
    delete ui;
}

//void multipleMotorTestForm::on_pushButton_start_clicked()
//{
//    VCI_CAN_OBJ sendbuf[6];
//    QStringList listData;
//    listData.append("142:A2 00 00 00 70 17 00 00");
//    listData.append("143:A2 00 00 00 70 17 00 00");
//    //    listData.append("01:01 80 00 00 00 01");
//    //    listData.append("01:01 86 00 00 03 e8");
//    //    listData.append("02:02 80 00 00 00 01");
//    //    listData.append("02:01 86 00 00 03 e8");

//    listData.append("00:ff 80 00 00 00 01");
//    listData.append("00:ff 86 00 00 03 e8");

//    bool ok;
//    for (int i=0;i<listData.size();i++)
//    {
//        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
//        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

//        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
//        {
//            sendbuf[i].ID =(listData.at(i).split(":").at(0).simplified().toUInt(&ok,16)); //&0x1FFFFFFF;
//        }
//        else//标准帧格式
//        {
//            sendbuf[i].ID=(listData.at(i).split(":").at(0).simplified().toUInt(&ok,16))&0x7FF;
//        }

//        sendbuf[i].SendType=1;
//        sendbuf[i].TimeFlag=0;
//        sendbuf[i].TimeStamp=0;
//        publicClass::getInstance()->Str2CharSplitBlank(listData.at(i).split(":").at(1).simplified(),sendbuf[i].Data,&sendbuf[i].DataLen);

//        ULONG flag =VCI_Transmit(4,
//                                 0,
//                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
//        _sleep(50);
//        if(flag<1)  //发送不正常
//        {
//            //             emit signalError("error");
//            qDebug()<<"[error]"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sizeof (sendbuf[i].Data));

//        }
//        else {
//        }
//    }
//    listData.clear();

//}

//void multipleMotorTestForm::on_pushButton_stop_clicked()
//{
//    VCI_CAN_OBJ sendbuf[6];
//    QStringList listData;
//    listData.append("142:81 00 00 00 00 00 00 00");
//    listData.append("143:81 00 00 00 00 00 00 00");
//    listData.append("01:01 87 00 00 00 01");
//    listData.append("02:02 87 00 00 00 01");
//    bool ok;
//    for (int i=0;i<listData.size();i++)
//    {
//        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
//        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

//        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
//        {
//            sendbuf[i].ID =(listData.at(i).split(":").at(0).simplified().toUInt(&ok,16)); //&0x1FFFFFFF;
//        }
//        else//标准帧格式
//        {
//            sendbuf[i].ID=(listData.at(i).split(":").at(0).simplified().toUInt(&ok,16))&0x7FF;
//        }

//        sendbuf[i].SendType=1;
//        sendbuf[i].TimeFlag=0;
//        sendbuf[i].TimeStamp=0;
//        publicClass::getInstance()->Str2CharSplitBlank(listData.at(i).split(":").at(1).simplified(),sendbuf[i].Data,&sendbuf[i].DataLen);
//        qDebug()<<sendbuf[i].DataLen<<"***"<<listData;
//        ULONG flag =VCI_Transmit(4,
//                                 0,
//                                 publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
//        _sleep(50);
//        if(flag<1)  //发送不正常
//        {
//            //             emit signalError("error");
//            qDebug()<<"[error]"<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sizeof (sendbuf[i].Data));
//            while (1) {
//                flag=  VCI_Transmit(4,
//                                    0,
//                                    publicClass::getInstance()->readValueIni("index/CanIndex").toUInt(),&sendbuf[i],1); //调用动态链接库发送函数
//                _sleep(5);
//                if(flag>1){
//                    break;
//                }
//            }

//        }
//        else {
//        }
//    }
//}
void multipleMotorTestForm::setValue(QString com,int8_t fbl,int32_t dan,int32_t duo)
{
    QString  A2 = publicClass::getInstance()->readValueIni("COM/A2").simplified();
    QString  A3 = publicClass::getInstance()->readValueIni("COM/A3").simplified();
    QString  A4 = publicClass::getInstance()->readValueIni("COM/A4").simplified();
    if(com ==A2){
        ui->label_danquan_A2->setText(QString::number(dan));
        ui->label_duoquan_A2->setText(QString::number(duo));
        ui->label_fbl_A2->setText(QString::number(fbl));
        float value = 360*dan/524287;
        ui->label_angle_A2->setText(QString::number(value,'f', 2));


    }
    if(com ==A3){
        ui->label_danquan_A3->setText(QString::number(dan));
        ui->label_duoquan_A3->setText(QString::number(duo));
        ui->label_fbl_A3->setText(QString::number(fbl));
        float value = 360*dan/524287;
        ui->label_angle_A3->setText(QString::number(value,'f', 2));

    }
    if(com ==A4){

        ui->label_danquan_A4->setText(QString::number(dan));
        ui->label_duoquan_A4->setText(QString::number(duo));
        ui->label_fbl_A4->setText(QString::number(fbl));
        float value = 360*dan/524287;
        ui->label_angle_A4->setText(QString::number(value,'f', 2));

    }

}
void multipleMotorTestForm::slotDataTest(QString str,QString com)
{

    COM_ID id = static_cast<COM_ID>(com.right(1).toUInt());
    //        qDebug()<<str<<"UUUUUUUUUUUUUUUUUUUUUU"<<com;
    switch (id) {
    case A2:{

        if(ui->checkBox_max->isChecked()||ui->checkBox_min->isChecked()) return;
        QStringList st = publicClass::getInstance()->Byte_16(str,str.size()).split(" ");
        if(st.size()!=11) return;
        if(st.at(0)=="1A"){
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

            signalValue_A2(valueDuoquan,valueDanquan);
            ui->label_danquan_A2->setText(QString::number(valueDanquan));
            ui->label_duoquan_A2->setText(QString::number(valueDuoquan));
            ui->label_fbl_A2->setText(QString::number(valueFBL));
            float value = 360*valueDanquan/524287;
            ui->label_angle_A2->setText(QString::number(value,'f', 2));
            break;
        }
    }
    case A3:{
        if(ui->checkBox_max->isChecked()||ui->checkBox_min->isChecked()) return;
        QStringList st = publicClass::getInstance()->Byte_16(str,str.size()).split(" ");
        if(st.size()!=11) return;
        if(st.at(0)=="1A"){
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

            signalValue_A3(valueDuoquan,valueDanquan);
            ui->label_danquan_A3->setText(QString::number(valueDanquan));
            ui->label_duoquan_A3->setText(QString::number(valueDuoquan));
            ui->label_fbl_A3->setText(QString::number(valueFBL));
            float value = 360*valueDanquan/524287;
            ui->label_angle_A3->setText(QString::number(value,'f', 2));
            break;
        }
    }
    case A4:{
        if(ui->checkBox_max->isChecked()||ui->checkBox_min->isChecked()) return;
        QStringList st = publicClass::getInstance()->Byte_16(str,str.size()).split(" ");
        if(st.size()!=11) return;
        if(st.at(0)=="1A"){
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

            signalValue_A4(valueDuoquan,valueDanquan);
            ui->label_danquan_A4->setText(QString::number(valueDanquan));
            ui->label_duoquan_A4->setText(QString::number(valueDuoquan));
            ui->label_fbl_A4->setText(QString::number(valueFBL));
            float value = 360*valueDanquan/524287;
            ui->label_angle_A4->setText(QString::number(value,'f', 2));
            break;
        }
    }
    case A8:{
        if(ui->checkBox_max->isChecked()||ui->checkBox_min->isChecked()) return;
        QStringList st = publicClass::getInstance()->Byte_16(str,str.size()).split(" ");
        if(st.size()!=11) return;
        if(st.at(0)=="1A"){
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

            signalValue_A8(valueDuoquan,valueDanquan);
            ui->label_danquan_A8->setText(QString::number(valueDanquan));
            ui->label_duoquan_A8->setText(QString::number(valueDuoquan));
            ui->label_fbl_A8->setText(QString::number(valueFBL));
            float value = 360*valueDanquan/524287;
            ui->label_angle_A8->setText(QString::number(value,'f', 2));
            break;
        }
    }
    default:
        break;
    }
}
/*
 * 单圈 316692
 * 多圈 63491  右侧 V负 编码器值递增
 *
 * 单圈 203374
 *
 *  多圈 63486  左侧 V正 编码器值递减
 *
 */
void multipleMotorTestForm::on_pushButton_writeConfig_max_clicked()
{
    //    publicClass::getInstance()->setValueIni("A2-max/danquan",QString::number(ui->label_danquan->text().toInt()));
    //    publicClass::getInstance()->setValueIni("A2-max/duoquan",QString::number(ui->label_duoquan->text().toInt()));
    //    qDebug()<<
    //    uint64_t num =  publicClass::getInstance()->readValueIni("A2-max/danquan").toLong() *publicClass::getInstance()->readValueIni("A2-max/duoquan").toLong();
    //    publicClass::getInstance()->setValueIni("A2-max/output",QString::number(num));
}

void multipleMotorTestForm::on_pushButton_writeConfig_min_clicked()
{
    //    publicClass::getInstance()->setValueIni("A2-min/danquan",QString::number(ui->label_danquan->text().toInt()));
    //    publicClass::getInstance()->setValueIni("A2-min/duoquan",QString::number(ui->label_duoquan->text().toInt()));
    //    int64_t num =  publicClass::getInstance()->readValueIni("A2-min/danquan").toInt()*publicClass::getInstance()->readValueIni("A2-min/duoquan").toInt();
    //    publicClass::getInstance()->setValueIni("A2-min/output",QString::number(num));
}
