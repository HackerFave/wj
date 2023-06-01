#include "qserialwork.h"
#include <QCoreApplication>
#include <QDataStream>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QtDebug>
#define MT 0
QSerialWork::QSerialWork(QObject *parent) : QObject(parent)
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();

    m_isOpen = false;
}

QSerialWork::~QSerialWork()
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
}

QSerialPort * QSerialWork::InitSerialPort()
{
    m_serialPort = new QSerialPort(this);
    connect(m_serialPort, &QSerialPort::readyRead/*waitForReadyRead*/, this, &QSerialWork::DataArrived,Qt::DirectConnection);
    connect(&_timer, &QTimer::timeout, this, &QSerialWork::timeUpdate);
    connect(&_timerTest, &QTimer::timeout, this, &QSerialWork::slotWriteData);

    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
    return m_serialPort;
}

bool QSerialWork::isOpen()
{
    return m_isOpen;
}

void QSerialWork::OpenPort(QString portName,QSerialPort::BaudRate flag,QSerialPort::DataBits bit )
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();

    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate((QSerialPort::BaudRate)flag,QSerialPort::AllDirections);//波特率
    m_serialPort->setDataBits((QSerialPort::DataBits)bit);//数据位
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    m_isOpen = m_serialPort->open(QSerialPort::ReadWrite);

    if(m_isOpen)
    {
        _timerTest.start(50);
        emit State(QSERIALWORK_ERR_OPEN_SUCCESS);
        //        setState(QSERIALWORK_ERR_OPEN_SUCCESS);
    }else
    {
        emit State(QSERIALWORK_ERR_OPEN_FAILED);
        //        setState(QSERIALWORK_ERR_OPEN_FAILED);
    }
}
void QSerialWork::setState(int error)
{
    _errorState = error;
}
int QSerialWork::getState() const
{
    return  _errorState;
}
void QSerialWork::ClosePort()
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
    _timerTest.stop();
    m_serialPort->close();
}

void QSerialWork::WriteData(const QByteArray& buf, qint64 len)
{
    //    std::lock_guard<std::mutex> lgd(_mutex);
    qDebug() << __FUNCTION__ << "Thread ID:" <<buf<< QThread::currentThreadId();
    m_serialPort->write(buf, len);
}

void QSerialWork::DataArrived()
{
    //    std::lock_guard<std::mutex> lgd(_mutex);
    //    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
    _buffer.append(m_serialPort->readAll());
    QString ret(_buffer.toHex().toUpper());
    qDebug()<<"[RECV:]"<<ret;
#if MT
    _timer.start(10);
    if(_buffer.size()-5-1 ==  int(_buffer[3])){
        emit NewData(_buffer);
    }
#else
    emit NewData(_buffer);
#endif
    _buffer.clear();
}
void QSerialWork::timeUpdate()
{

    _timer.stop();
    _buffer.clear();
}
void QSerialWork::slotWriteData()
{
    //    qDebug() << __FUNCTION__ << "Thread ID:" ;
    QString STR1 = "1A";
    //    QString STR2 = "02";
    //    QString STR3 = "92";
    //    QString STR4 = "8A";
    //    static int num =0;
    //    if(num%2==0){
    QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
    WriteData(byte,byte.size());
    //    }
    //    else if (num%3==0) {
    //        QByteArray byte = QByteArray::fromHex(STR2.toLatin1());
    //        WriteData(byte,byte.size());
    //    }
    //    else if (num%5==0) {
    //        QByteArray byte = QByteArray::fromHex(STR3.toLatin1());
    //        WriteData(byte,byte.size());
    //    }
    //    else if (num%7==0) {
    //        QByteArray  byte = QByteArray::fromHex(STR4.toLatin1());
    //        WriteData(byte,byte.size());
    //    }
    //    num++;
}
QByteArray QSerialWork::SendData_Syn(const char* sendData, uint ulen, uint expectReceiveLen)
{
    int len = m_serialPort->write(sendData,ulen);
    //打印日志
    QByteArray basend;
    basend.append(sendData, ulen);
    //    qInfo()<<m_serialPort->portName() << " send data" <<basend.toHex() <<" send bytes: "<<len;

    if(!m_serialPort->waitForBytesWritten(2000)){
        QString data = QStringLiteral("cmd error")+m_serialPort->errorString();
        m_serialPort->clearError();
        emit NewData(data.toLocal8Bit());
        return "";
    }
    QEventLoop eventLoop;//局部事件循环，不卡界面
    QTimer::singleShot(2000, &eventLoop, &QEventLoop::quit);
    QObject::connect(m_serialPort, SIGNAL(readyRead()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    if(m_serialPort->bytesAvailable() > 0)
    {
        QByteArray ba;
        while (m_serialPort->waitForReadyRead(5))
        {
            ba += m_serialPort->readAll();
            //            if(/*expectReceiveUlen > 0 &&*/ ba.length() > (3*expectReceiveLen))
            //                break;//串口有时候也会异常，猛发数据上来，导致循环一直没法结束。
        }

        qInfo()<<m_serialPort->portName()<<" receive bytes: "<<ba.toHex();
        emit NewData(ba);
        return ba;
    }
    else
    {
        qInfo()<<m_serialPort->portName()<<" no answer ";
        QObject::disconnect(m_serialPort, SIGNAL(readyRead()), &eventLoop, SLOT(quit()));
        emit NewData("");
        return "";
    }
}
