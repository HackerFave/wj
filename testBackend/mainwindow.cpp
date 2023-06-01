#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <functional>
#include "sdk/methord/funcCan.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    funcCan *FUN =  static_cast<funcCan*>(init()) ;
    auto Fun = std::bind(call,placeholders::_1,placeholders::_2);

    FUN->regeditCallBack(Fun);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotRecv(UINT id, BYTE *data)
{

}
void  MainWindow:: call(UINT id, BYTE * data)
{
   qDebug()<<id<<data<<"XXXXXXXXXXXXXXXXX";
}
