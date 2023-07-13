#include "func.h"
#include <QtDebug>
func::func(QString com,QObject *parent) : QObject(parent),_com(com)
{
    init();
}
QSerialPort* func::init()
{
    _serialPort = new QSerialPort(this);
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        qDebug()<<"[在线端口:]"<<info.portName();

    }
    _com = publicClass::getInstance()->readValueIni("COM/port").toLatin1();
    _serialPort->setPortName(_com);
    _serialPort->setBaudRate((QSerialPort::BaudRate)115200,QSerialPort::AllDirections);//波特率
    _serialPort->setDataBits((QSerialPort::DataBits)8);//数据位
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);
    _serialPort->setFlowControl(QSerialPort::NoFlowControl);
    if(_serialPort->open(QSerialPort::ReadWrite))
    {
        connect(_serialPort, &QSerialPort::readyRead, this, &func::slotDataArrived);
        emit signalStatus(QSERIALWORK_ERR_OPEN_SUCCESS);
        qDebug()<<"OPEN SUCCESS:"<<"[端口"<<_com<<"]"<<publicClass::getInstance()->readValueIni("COM/port").toLatin1();
    }else
    {
        qDebug() << __FUNCTION__ << "open fail，error info: " << this->_serialPort->errorString();
        emit signalStatus(QSERIALWORK_ERR_OPEN_FAILED);
        qDebug()<<"OPEN ERROR:"<<"[端口"<<_com<<"不在线]"<<publicClass::getInstance()->readValueIni("COM/port").toLatin1();
    }
    return _serialPort;
}
func::~func()
{

}
void func::initThread()
{

}
void func::slotDataArrived()
{
    _buffer.append(_com);
    _buffer.append(_serialPort->readAll());
    QString ret(_buffer.toHex().toUpper());
    qDebug() <<"[recv:]"<<ret;
    _buffer.clear();
}

void func::control(QString value)//向前
{
    QByteArray byte = QByteArray::fromHex(value.toLatin1());
     qDebug()<<"[byte:]"<<byte<<""<<QString(byte.toUpper())<<"size:"<<byte.size();
    _serialPort->write(byte,byte.size());
}

//油门
void func::throttleMoved(int position)
{
    unsigned char out[4] ={};
    memmove(out,&position,4);
    QByteArray byArr((const char*)out,4);

    QStringList ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4).split(" ");

    QString send =QString("AA AB 02 ")+ssss[1]+" "+ssss[0]+ " 00 0D 0A";

    _data485.enqueue(send);
    std::lock_guard<std::mutex> lgd(_mutex);
    QString str = _data485.dequeue();
     qDebug()<<"[position]"<<position<<"[RECV:]"<< send<<"[QUEUE:]"<<str;
    control(str);

}
//前进
void func::frontMove()
{
    control("AA B0 03 01 01 00 00 0D 0A");
}
//后退
void func::backMove()
{
    control("AA B0 03 01 01 01 00 0D 0A");
}
void func::stopMove()
{
    control("AA AB 02 00 00 00 0D 0A");
}
