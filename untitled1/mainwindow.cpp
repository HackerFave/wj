#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ControlCAN.h"
#include <QtDebug>
const UCHAR Bsp[17][2]={{0x31,0x1C},{0x18,0x1C},{0x87,0xFF},{0x09,0x1C},{0x83,0xFF},
                        {0x04,0x1C},{0x03,0x1C},{0x81,0xFA},{0x01,0x1C},{0x80,0xFA},
                        {0x00,0x1C},{0x80,0xB6},{0x00,0x16},{0x00,0x14},{0x09,0x6F},
                        {0x04,0x6F},{0x03,0x6F}};
void Str2CharSplitBlank(QString s, uchar *c,uchar *len)
{
    bool ok;
    QStringList lstr=s.split(" ");
    *len =static_cast<uchar>(lstr.length());
    if(*len!=0){
        for(int i=0;i<*len;i++)
        {
            c[i]=static_cast<unsigned char>(lstr[i].toInt(&ok,16));
        }
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    VCI_CAN_OBJ sendbuf[6];
    QStringList listData;
//    listData.append("142:A2 00 00 00 70 17 00 00");
//    listData.append("143:A2 00 00 00 70 17 00 00");
    //    listData.append("01:01 80 00 00 00 01");
    //    listData.append("01:01 86 00 00 03 e8");
    //    listData.append("02:02 80 00 00 00 01");
    //    listData.append("02:01 86 00 00 03 e8");

    listData.append("00:ff 80 00 00 00 01");
    listData.append("00:ff 86 00 00 03 e8");

    bool ok;
    for (int i=0;i<listData.size();i++)
    {
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(listData.at(i).split(":").at(0).simplified().toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(listData.at(i).split(":").at(0).simplified().toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=0;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        Str2CharSplitBlank(listData.at(i).split(":").at(1).simplified(),sendbuf[i].Data,&sendbuf[i].DataLen);

        ULONG flag =VCI_Transmit(4,
                                 0,
                                 0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(50);
        if(flag<1)  //发送不正常
        {
            //             emit signalError("error");
            qDebug()<<"[error]"<<flag;

        }
        else {
        }
    }
}
