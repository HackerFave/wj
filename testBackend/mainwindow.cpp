#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <functional>
#include "funcCan.h"
#include "publicclass.h"

std::mutex MainWindow::_mutex ;
MainWindow* MainWindow::P_stac = nullptr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _FUN =  static_cast<funcCan*>(init()) ;
    auto Fun = std::bind(call,placeholders::_1);
    //    auto Funbmq = std::bind(callbmq,placeholders::_1,placeholders::_2,placeholders::_3,placeholders::_4);
    _FUN->regeditCallBack(Fun);
    _FUN->regeditCallBack(callbmq);
    initPoint();
    connect(this,&MainWindow::signalDataToForm_LX,ui->widget_LX,&lingChaCanform::slotRecvLingChaData);
//    connect(this,&MainWindow::signalDataToForm_rmd_141,ui->widget_RMD,&rmdSettingForm::slotRecvRmdData_141);//迈塔智能
//    connect(this,&MainWindow::signalDataToForm_rmd_145,ui->widget_RMD,&rmdSettingForm::slotRecvRmdData_141);//迈塔智能
//    connect(this,&MainWindow::signalDataToForm_TT,ui->widget_TT,&viewShowForm::slotPlotViewUpdate);
//    connect(this,&MainWindow::signalDataToForm_YK,ui->widget_YK,&yankongDataForm::slotRecvData);

    _FUN->setRmdAcceleration(funcCan::RMD_A2,5000);
    _FUN->setRmdAcceleration(funcCan::RMD_A4,5000);
}

MainWindow::~MainWindow()
{
    Release(_FUN);
    delete ui;
}
//初始化指针
void MainWindow::initPoint()
{

    //    if(P_stac){
    //        delete P_stac;
    //        P_stac = this;
    //    }
    P_stac = this;
}

void MainWindow::slotRecv(UINT id, BYTE *data)
{

}
void  MainWindow::callbmq(std::string com,int8_t valueFBL, int32_t valueDanquan,int32_t valueDuoquan )
{
    //    qDebug()<<com.c_str()<<valueFBL<<valueDanquan<<valueDuoquan<<"XXXXXXXXXXXXXXXXXX";
    P_stac->setValue_bmq(com, valueFBL,  valueDanquan, valueDuoquan);

}
void  MainWindow:: call(CAN_OBJ *data)
{
    std::lock_guard<std::mutex> lgd(_mutex);
    CAN_OBJ obj;
    memmove(&obj,data,sizeof (CAN_OBJ));
    int id = obj.ID;
    switch (id) {
    case 0x581:{
        int32_t index;
        memmove(&index,&data->Data[1],2);

        //        if(index == 0x6064){//编码器绝对位置
        int32_t value;
        memmove(&value,&data->Data[4],4);
        //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())<<" "<<
        //                      QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //                   <<"[DATA:]"<<value;
        P_stac->setValue_TT(index,value);
        //        }
        //        else if(index == 0x300F) {//第二位置编码器
        //            int32_t value;
        //            memmove(&value,&data->Data[4],4);
        //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //                   <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //                  <<"DATA:"<<value;
        //        }
        //        else if(index == 0x6063) {//当前电机位置
        //            int32_t value;
        //            memmove(&value,&data->Data[4],4);
        //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //                   <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //                  <<"DATA:"<<value;
        //        }
        //        else if(index == 0x607A) {//目标位置
        //            int32_t value;
        //            memmove(&value,&data->Data[4],4);
        //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //                   <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //                  <<"DATA:"<<value;
        //        }
        //        else if(index == 0x3008) {//第一位置编码器
        //            int32_t value;
        //            memmove(&value,&data->Data[4],4);
        //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //                   <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //                  <<"DATA:"<<value;
        //        }

        break;
    }
    case 0x582:{
        int32_t value;
        int16_t index;
        memmove(&index,&data->Data[1],2);
        memmove(&value,&data->Data[4],4);
        //        qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //               <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //              <<"DATA:"<<value;
        //        P_stac->setValue_YK(value);
        break;
    }
    case 0x583:{
        int32_t value;
        int16_t index;
        memmove(&index,&data->Data[1],2);
        if(index == 0x6064){
            memmove(&value,&data->Data[4],4);
            P_stac->setValue_LX(value);
            //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
            //                   <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
            //                  <<"DATA:"<<value;
        }
        else if (index == 0x6041) {
            memmove(&value,&data->Data[4],4);
            //            qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
            //                   <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
            //                  <<"DATA:"<<value;
        }
        break;
    }
    case 0x141:{
        int8_t valuetem;
        int16_t valueiq;
        int16_t valuespeed;
        uint16_t valueencoder;
        memmove(&valuetem,&data->Data[1],1);
        memmove(&valueiq,&data->Data[2],2);
        memmove(&valuespeed,&data->Data[4],2);
        memmove(&valueencoder,&data->Data[6],2);
        //        qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //               <<"DATA:"<<valueencoder;
        P_stac->setValue_RMD_141(valueencoder,valuespeed);
        break;
    }
    case 0x145:{
        int8_t valuetem;
        int16_t valueiq;
        int16_t valuespeed;
        uint16_t valueencoder;
        memmove(&valuetem,&data->Data[1],1);
        memmove(&valueiq,&data->Data[2],2);
        memmove(&valuespeed,&data->Data[4],2);
        memmove(&valueencoder,&data->Data[6],2);
        //        qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //               <<"DATA:"<<valueencoder;
        P_stac->setValue_RMD_145(valueencoder,valuespeed);
        break;
    }
    default:
        break;
    }

}
void MainWindow::setValue_LX(int32_t value)
{
    ui->widget_LX->setValue(value);


}
void MainWindow::setValue_YK(int32_t value)
{
//    ui->widget_YK->setValue(value);
}
void MainWindow::setValue_TT(uint32_t id, int32_t value)
{
//    ui->widget_TT->setValue(id,value);
}

void MainWindow::setValue_RMD_141(int32_t valueencoder,int32_t valuespeed)
{
//    ui->widget_RMD->setValue_141(valueencoder,valuespeed);
}
void MainWindow::setValue_RMD_145(int32_t valueencoder,int32_t valuespeed)
{
//    ui->widget_RMD->setValue_145(valueencoder,valuespeed);
}

//void MainWindow::on_pushButton_A1_clicked()
//{
//    uint32_t value = ui->lineEdit_A1->text().toInt();
//    _FUN->controlMachine(funcCan::LX,value);
//}
void MainWindow::setValue_bmq(std::string com, int8_t fbl,int32_t dan,int32_t duo)
{
    ui->widget_BMQ->setValue(com.c_str(),fbl,dan,duo);
}

//void MainWindow::on_pushButton_A3_clicked()
//{
//    uint32_t value = ui->lineEdit_A1->text().toInt();
//    _FUN->controlMachine(funcCan::TT,value);
//}

//void MainWindow::on_pushButton_A2_clicked()
//{
//    uint32_t value = ui->lineEdit_A1->text().toInt();
//    _FUN->controlMachine(funcCan::RMD_A2,value);
//}

void MainWindow::on_pushButton_A4_clicked()
{
//    uint32_t value = ui->lineEdit_A1->text().toInt();
//    _FUN->controlMachine(funcCan::RMD_A4,value);
}

void MainWindow::on_pushButton_A1_up_pressed()
{
    qDebug()<<"A1 UP PRESS";
    //    static int32_t angle = 100;
    //    angle = angle-10;

    _FUN->controlMachine(funcCan::LX,-ui->spinBox_A1->value());
//    _FUN->controlMachine(funcCan::RMD_A4,3089);

}

void MainWindow::on_pushButton_A1_up_released()
{
    qDebug()<<"A1 UP RELEASE";
    _FUN->stopLX();
//    _FUN->stopRmd(0x145);


}

void MainWindow::on_pushButton_A1_down_pressed()
{
    //    qDebug()<<"A1 UP PRESS";
    //    static int32_t angle = 0;
    //    angle = angle+10;

    _FUN->controlMachine(funcCan::LX,/*30000*/ui->spinBox_A1->value());
//    _sleep(10);
//    _FUN->controlMachine(funcCan::RMD_A4,-3089);
    qDebug()<<"A1 DOWN PRESS";
}

void MainWindow::on_pushButton_A1_down_released()
{
    qDebug()<<"A1 DOWN RELEASE";
    _FUN->stopLX();
//     _sleep(10);
//    _FUN->stopRmd(0x145);
}

void MainWindow::on_pushButton_A2_left_pressed()
{
    _FUN->controlMachine(funcCan::RMD_A2,-ui->spinBox_A2->value());
}

void MainWindow::on_pushButton_A2_left_released()
{
    _FUN->stopRmd(funcCan::RMD_A2);
}

void MainWindow::on_pushButton_A2_right_pressed()
{
    _FUN->controlMachine(funcCan::RMD_A2,ui->spinBox_A2->value());
}

void MainWindow::on_pushButton_A2_right_released()
{
    _FUN->stopRmd(funcCan::RMD_A2);
}

void MainWindow::on_pushButton_A3_front_pressed()
{
    _FUN->controlMachine(funcCan::TT,-ui->spinBox_A3->value());
}

void MainWindow::on_pushButton_A3_front_released()
{
    _FUN->stopTT();
}

void MainWindow::on_pushButton_A3_back_pressed()
{
    _FUN->controlMachine(funcCan::TT,ui->spinBox_A3->value());
}

void MainWindow::on_pushButton_A3_back_released()
{
    _FUN->stopTT();
}

void MainWindow::on_pushButton_A4_UP_pressed()
{
    _FUN->controlMachine(funcCan::RMD_A4,-ui->spinBox_A4->value());
}

void MainWindow::on_pushButton_A4_UP_released()
{
     _FUN->stopRmd(0x145);
}

void MainWindow::on_pushButton_DOWN_pressed()
{
    _FUN->controlMachine(funcCan::RMD_A4,ui->spinBox_A4->value());
}

void MainWindow::on_pushButton_DOWN_released()
{
     _FUN->stopRmd(0x145);
}
