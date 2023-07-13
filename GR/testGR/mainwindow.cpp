#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <functional>
using namespace std;

MainWindow * MainWindow::P_stac = nullptr;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    P_HeadGR = new HeadGR;
    auto Fun = std::bind(call,placeholders::_1,placeholders::_2);
    P_HeadGR->regeditCallBack(Fun);
    initPoint();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//初始化指针
void MainWindow::initPoint()
{
    P_stac = this;
}
void MainWindow::call(TYPE_ID id, int32_t value)
{
    P_stac->setCurrentAngle(id,value);
}
void MainWindow::setCurrentAngle(TYPE_ID id, int32_t value)
{
    switch (id) {
    case TYPE_ID::accel_x1:{
        ui->label_acc_x1->setText(QString::number(value));
        break;
    }
    case TYPE_ID::accel_x2:{
        ui->label_acc_x2->setText(QString::number(value));
        break;
    }
    case TYPE_ID::encoder_x1:{
        ui->label_angle_1->setText(QString::number(value));
        break;
    }
    case TYPE_ID::encoder_x2:{
        ui->label_angle_2->setText(QString::number(value));
        break;
    }
    default:
        break;
    }

}

//水平转动
void MainWindow::on_pushButton_run_clicked()
{
    P_HeadGR->setTurnAngle(0x01,ui->lineEdit_angle->text().toInt(),180);
}
//水平
void MainWindow::on_pushButton_read_encoder_clicked()
{
    P_HeadGR->getEncoder(0x01);
}
//垂直
void MainWindow::on_pushButton_read_encoder_2_clicked()
{
    P_HeadGR->getEncoder(0x02);
}
//垂直转动
void MainWindow::on_pushButton_run_2_clicked()
{
    P_HeadGR->setTurnAngle(0x02,ui->lineEdit_angle_2->text().toInt(),1200);
}

void MainWindow::on_pushButton_readacc_chuizhi_clicked()
{
    P_HeadGR->getAccel(0X02);
}

void MainWindow::on_pushButton_readacc_shuiping_clicked()
{
    P_HeadGR->getAccel(0X01);
}

void MainWindow::on_pushButton_write_clicked()
{
    if(ui->radioButton->isChecked()){
        ui->lineEdit_0pian->text().toInt();
        P_HeadGR->setOffsetAngle(0x01,ui->lineEdit_0pian->text().toInt());
    }
    else if (ui->radioButton_2->isChecked()) {
        ui->lineEdit_0pian->text().toInt();
        P_HeadGR->setOffsetAngle(0x02,ui->lineEdit_0pian->text().toInt());
    }
}

void MainWindow::on_pushButton_clear_angle_clicked()
{
    if(ui->radioButton->isChecked()){
        P_HeadGR->clearAngle(0x01);
    }
    else if (ui->radioButton_2->isChecked()) {
        P_HeadGR->clearAngle(0x02);
    }
}

void MainWindow::on_pushButton_clear_error_clicked()
{
    if(ui->radioButton->isChecked()){
        P_HeadGR->clearError(0x01);
    }
    else if (ui->radioButton_2->isChecked()) {
        P_HeadGR->clearError(0x02);
    }
}
