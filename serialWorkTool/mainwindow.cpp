#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("伟景"));
    ui->statusbar->addWidget(&_labelStatus);
    connect(ui->widget_datashow,&dataShowForm::signalStatus,this,&MainWindow::slotStatus);
    connect(ui->widget_datashow,&dataShowForm::signalBmqDataToForm,ui->widget_test,&multipleMotorTestForm::slotDataTest);
    //    connect(ui->widget_datashow,&dataShowForm::signalBmqDataToForm,ui->widget_rmd,&rmdSettingForm::slotDataTest);
    connect(ui->widget_datashow,&dataShowForm::signalBmqDataToForm_A2,ui->widget_rmd,&rmdSettingForm::slotDataTest_A2);//A2编码器

    connect(ui->widget_datashow,&dataShowForm::signalBmqDataToForm01,ui->widget_xintuo,&xintuoCanForm::slotWorkDataBMQ01);//01编码器
    connect(ui->widget_datashow,&dataShowForm::signalBmqDataToForm02,ui->widget_xintuo,&xintuoCanForm::slotWorkDataBMQ02);//02编码器
    connect(ui->widget_datashow,&dataShowForm::signalBmqDataToForm_A8,ui->widget_rmd,&rmdSettingForm::slotWorkDataBMQA8);//A8编码器


    //    connect(ui->widget_test,&multipleMotorTestForm::signalValue_A8,ui->widget_rmd,&rmdSettingForm::slotDataTest_A8);
    connect(ui->widget_canDataShow,&canDataShowForm::/*signalDataToView*/signalDataToForm,ui->widget_viewShowForm,&viewShowForm::slotPlotViewUpdate);
    connect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_rmd,&rmdSettingForm::slotRecvRmdData);//迈塔智能
    connect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_datashow,&dataShowForm::slotRecvMachineData);//通知编码器线程需要停止了
    connect(ui->widget_rmd,&rmdSettingForm::signalDisConnect,this,&MainWindow::slotDisConnect);
    connect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_lingcha,&lingChaCanform::slotRecvLingChaData);
    connect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_xintuo,&xintuoCanForm::slotRecvxintuoData);
     connect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_yankong,&yankongDataForm::slotRecvData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotStatus(QString str)
{
    _labelStatus.setText(str);
}
void  MainWindow::slotDisConnect(int index)
{
    switch (index) {
    case 0:
        connect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_rmd,&rmdSettingForm::slotRecvRmdData);
        break;
    case 2:
        disconnect(ui->widget_canDataShow,&canDataShowForm::signalDataToForm,ui->widget_rmd,&rmdSettingForm::slotRecvRmdData);
        break;
    default:
        break;
    }

}
