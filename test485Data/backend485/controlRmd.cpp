#include "controlRmd.h"
#include <QtDebug>
#include <QStringList>
controlRmd::controlRmd(QObject *parent) : QObject(parent)
{
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        qDebug()<<"[在线端口:]"<<info.portName();
    }

    P_Serial= new serialWork;
    _com = publicClass::getInstance()->readValueIni("COM/portrmd").toLatin1();
    P_port= P_Serial->InitSerialPort();
    P_Serial->OpenPort(_com,(QSerialPort::BaudRate)115200,(QSerialPort::DataBits)(8));
    connect(P_Serial,&serialWork::State,this,&controlRmd::slotState);
    connect(P_Serial,&serialWork::NewData,this,&controlRmd::slotNewData);
    connect(&_timerRMD,&QTimer::timeout,this,&controlRmd::slotUpdateData);
    _timerRMD.start(10);
}
controlRmd::~controlRmd()
{
    if(P_Serial){
        P_Serial->ClosePort();
    }
}
void controlRmd::slotState(int err)
{
    switch (err) {
    case 1:{
        qDebug()<<QString("[connect %1 success!!!]").arg(_com);
        break;
    }
    case 2:{
        qDebug()<<QString("[connect %1 failed!!!]").arg(_com);
        break;
    }
    default:
        break;
    }
}
void controlRmd::slotNewData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");
    qDebug()<<("DATA LEN:"+QString::number(list.size())+" DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );
}
void controlRmd::slotUpdateData()
{

    static int num = 0;
    if(num%2==0){
        QString  RMD = "3E 9C 01 00 DB";
        QByteArray byte = QByteArray::fromHex(RMD.toLatin1());
        P_Serial->WriteData(byte,byte.size());
    }
    else if (num%3==0) {
        QString  RMD = "3E 9C 02 00 DC";
        QByteArray byte = QByteArray::fromHex(RMD.toLatin1());
        P_Serial->WriteData(byte,byte.size());
    }
    num++;

}
