#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addWidget(&_labelStatus);
    connect(ui->widget_datashow,&dataShowForm::signalStatus,this,&MainWindow::slotStatus);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotStatus(QString str)
{
    _labelStatus.setText(str);
}
