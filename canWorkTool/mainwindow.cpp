#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ControlCAN.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_nDevType = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    /*int deviceTye,device,chanel;
    if(0==ui->comboBox->currentIndex())
    {
        deviceTye = 4;
    }
    else if(1==ui->comboBox->currentIndex())
    {
        deviceTye = 21;
    }
    else
    {
       QMessageBox::warning(this,QStringLiteral("失败"),QStringLiteral("错误的设备类型"));
       return;
    }
    device = ui->lineEdit->text().toInt();
    if(0==ui->comboBox_2->currentIndex())
    {
         chanel = 0;
    }
    else if(1==ui->comboBox_2->currentIndex())
    {
        chanel = 1;
    }
    else if(2==ui->comboBox_2->currentIndex())
    {
        chanel = 2;
    }
    else
    {
        QMessageBox::warning(this,"失败","错误的通道号");
        return;
    }*/
//        if(RET_ERR == CanManager::GetInstance()->openCan(/*deviceTye*/3,/*device*/0,/*chanel*/0))
//        {
//            QMessageBox::warning(this,"失败","打开can失败");
//            return;
//        }
//        QPalette palette;palette.setColor(QPalette::WindowText,Qt::red);
//        ui->label_7->setPalette(palette);
//        ui->label_7->setText("已连接");



}

void MainWindow::on_pushButton_open_clicked()
{
    m_DevIndex=0;
    m_DevType= m_nDevType == 1 ?  VCI_USBCAN2 :  VCI_USBCAN1;
    DWORD Reserved=0;
    qDebug()<<m_DevType<<m_DevIndex<<Reserved<<"*********************";
    //打开设备
    if(VCI_OpenDevice(m_DevType,m_DevIndex,Reserved)!=1)
    {
       ui->label_status->setText(QStringLiteral("打开can失败"));

                return;
    }
    VCI_INIT_CONFIG InitInfo[1];
    InitInfo->Timing0=0x00;
    InitInfo->Timing1=0x14;
    InitInfo->Filter=0;
    InitInfo->AccCode=0x80000008;
    InitInfo->AccMask=0xFFFFFFFF;
    InitInfo->Mode=2;
    //初始化通道0
    if(VCI_InitCAN(m_DevType,m_DevIndex, 0,InitInfo)!=1)	//can-0
    {
       ui->label_status->setText(QStringLiteral("打开can失败"));

        return;
    }


    Sleep(100);

    //初始化通道0
    if(VCI_StartCAN(m_DevType,m_DevIndex, 0)!=1)	//can-0
    {
        ui->label_status->setText("Start-CAN failed!");
        return;
    }
    //初始化通道1
    if(m_nDevType == 1)
    {
        if(VCI_InitCAN(m_DevType,m_DevIndex, 1,InitInfo)!=1)	//can-1
        {
            ui->label_status->setText("Init-CAN failed!");
            return;
        }
    }
    Sleep(100);
    //初始化通道1
    if(VCI_StartCAN(m_DevType,m_DevIndex, 1)!=1)	//can-0
    {
        ui->label_status->setText("Start-CAN failed!");
        return;
    }

    ui->label_status->setText("Open successfule! Start CAN OK!");
}

void MainWindow::on_pushButton_close_clicked()
{
    if(VCI_CloseDevice(m_DevType,m_DevIndex)!=1)
    {
        ui->label_status->setText("Close failed!");
        return;

    }

    ui->label_status->setText("Close successful!");
}

void MainWindow::on_pushButton_send_clicked()
{

}
