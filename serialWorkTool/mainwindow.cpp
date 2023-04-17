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
    connect(ui->widget_canDataShow,&canDataShowForm::signalDataToView,ui->widget_viewShowForm,&viewShowForm::slotPlotViewUpdate);
    connect(ui->widget_canDataShow,&canDataShowForm::signalDataToRmdForm,ui->widget_rmd,&rmdSettingForm::slotRecvRmdData);
    connect(ui->widget_rmd,&rmdSettingForm::signalDisConnect,this,&MainWindow::slotDisConnect);


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
        connect(ui->widget_canDataShow,&canDataShowForm::signalDataToRmdForm,ui->widget_rmd,&rmdSettingForm::slotRecvRmdData);
        break;
    case 2:
        disconnect(ui->widget_canDataShow,&canDataShowForm::signalDataToRmdForm,ui->widget_rmd,&rmdSettingForm::slotRecvRmdData);
        break;
    default:
        break;
    }

}
