#include "serialWork.h"
#include <QCoreApplication>
#include <QDataStream>
#include <QDateTime>
#include <QDir>
#include <QThread>
#include <QtDebug>
#define MT 1
serialWork::serialWork(QObject *parent) : QObject(parent)
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();

    m_isOpen = false;
}

serialWork::~serialWork()
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
}

QSerialPort * serialWork::InitSerialPort()
{
    m_serialPort = new QSerialPort(this);
    connect(m_serialPort, &QSerialPort::readyRead/*waitForReadyRead*/, this, &serialWork::DataArrived,Qt::DirectConnection);
    connect(&_timer, &QTimer::timeout, this, &serialWork::timeUpdate);

    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
    return m_serialPort;
}

bool serialWork::isOpen()
{
    return m_isOpen;
}

void serialWork::OpenPort(QString portName,QSerialPort::BaudRate flag,QSerialPort::DataBits bit )
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
        emit State(SERIALWORK_ERR_OPEN_SUCCESS);
    }else
    {
        emit State(SERIALWORK_ERR_OPEN_FAILED);
    }
}
void serialWork::setState(int error)
{
    _errorState = error;
}
int serialWork::getState() const
{
    return  _errorState;
}
void serialWork::ClosePort()
{
    qDebug() << __FUNCTION__ << "Thread ID:" << QThread::currentThreadId();
    m_serialPort->close();
}

void serialWork::WriteData(const QByteArray& buf, qint64 len)
{
//    std::lock_guard<std::mutex> lgd(_mutex);
//    qDebug() << __FUNCTION__ << "Thread ID:" <<"[SEND:]"<< QString(buf.toHex().toUpper())<< QThread::currentThreadId();
    m_serialPort->write(buf, len);
}

void serialWork::DataArrived()
{
//    std::lock_guard<std::mutex> lgd(_mutex);
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
void serialWork::timeUpdate()
{

    _timer.stop();
    _buffer.clear();
}
QByteArray serialWork::SendData_Syn(const char* sendData, uint ulen, uint expectReceiveLen)
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


////SerialPort3的反馈
//void serialWork::readMotorControl() {

//    QByteArray data;
//    data = m_serialPort->readAll();//取串口中的数据
//    _buffer.append(data);
//    if (_buffer.contains('\r'))//只有等到\n的时候才能进入
//    {
//    _buffer = _buffer.simplified();//去除空白字符
////    emit UpdateStatus(Port_str);
//    _buffer.remove(0, 1);

//    bool ok;
//    double val;
//    val = Port_str.toDouble(&ok); //ok=true;val;12.3456.
//    if (ok)
//    {
//    val = val*SettingIni::GetInstance()->readMulriple();
//    ui.lineEdit_EA_Read->setText(QString::number(val, 'f', 4));
//    }
//    else
//    {
//    ui.lineEdit_EA_Read->setText(Port_str);
//    }
//    Port_str.clear();
//    }
//}


//void serialWork::do_DataHandler(QByteArray BufferData)
//{
//	 //异常类：无头且变量为空，已丢失头部，数据不可靠，直接返回
//	if ((!BufferData.contains("{"))&(PasteData.isNull()))
//	{
//		return;
//	}
//	//第一种：有头无尾，先清空原有内容，再附加
//	if ((BufferData.contains("{"))&(!BufferData.contains("}")))
//	{
//		PasteData.clear();
//		PasteData.append(BufferData);
//	}
//	//第二种：无头无尾且变量已有内容，数据中段部分，继续附加即可
//	if ((!BufferData.contains("{"))&(!BufferData.contains("}"))&(!PasteData.isNull()))
//	{
//		PasteData.append(BufferData);
//	}
//	//第三种：无头有尾且变量已有内容，已完整读取，附加后输出数据，并清空变量
//	if ((!BufferData.contains("{"))&(BufferData.contains("}"))&(!PasteData.isNull()))
//	{
//		PasteData.append(BufferData);
//		ReadData = PasteData;
//		PasteData.clear();
//	}
//	//第四种：有头有尾（一段完整的内容），先清空原有内容，再附加，然后输出，最后清空变量
//	if ((BufferData.contains("{"))&(BufferData.contains("}")))
//	{
//		PasteData.clear();
//		PasteData.append(BufferData);
//		ReadData = PasteData;
//		PasteData.clear();
//	}
//	if (ReadData.length()>0)
//	{
//		qDebug() << "ReadData:" << ReadData.data();
//		qDebug() << ReadData.mid(10, 6);

//	}

//	ReadData.clear();
//}
