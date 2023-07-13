#include "func.h"
#include <QtDebug>
#include "publicclass.h"
func::func(QObject *parent) : QObject(parent)
{

    init();
    initClient();
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
    _serialPort->setBaudRate((QSerialPort::BaudRate)2560000,QSerialPort::AllDirections);//波特率
    _serialPort->setDataBits((QSerialPort::DataBits)8);//数据位
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);
    _serialPort->setFlowControl(QSerialPort::NoFlowControl);
    if(_serialPort->open(QSerialPort::ReadWrite))
    {
        //        initThread();
        connect(&_timerTest, &QTimer::timeout, this, &func::slotWriteData);
        connect(_serialPort, &QSerialPort::readyRead, this, &func::slotDataArrived);
        _timerTest.start(30);
        emit signalStatus(QSERIALWORK_ERR_OPEN_SUCCESS);
        //        _shareMemory.setKey(publicClass::getInstance()->readValueIni("COM/port"));//创建共享内存
        qDebug()<<"OPEN SUCCESS:"<<"[端口"<<publicClass::getInstance()->readValueIni("COM/port")<<"]";
    }else
    {
        qDebug() << __FUNCTION__ << "open fail，error info: " << this->_serialPort->errorString();
        emit signalStatus(QSERIALWORK_ERR_OPEN_FAILED);
        qDebug()<<"OPEN ERROR:"<<"[端口"<<publicClass::getInstance()->readValueIni("COM/port")<<"不在线]";
    }
    return _serialPort;
}
func::~func()
{
    if(!_threadMap.isEmpty()){
        _threadMap.clear();
    }
}
void func::initThread()
{
    _threadMap.clear();
    _pool.setMaxThreadCount(2);
    _threadMap[0] = new serialWorkThreadPool_send(_serialPort);
    _threadMap[0]->startWork();
    _threadMap[0]->setAutoDelete(true);

    _threadMap[1] = new serialWorkThreadPool_recv(_serialPort);
    _threadMap[1]->startWork();
    _threadMap[1]->setAutoDelete(true);

    _pool.start(_threadMap[0]);
    _pool.start(_threadMap[1]);
}
void func::initClient()
{
    _reconnect_timer = new QTimer(this);
    connect(_reconnect_timer,SIGNAL(timeout()),this,SLOT(slotReconect_to_server()));

    m_socket = new QLocalSocket(this);

    connect(m_socket,SIGNAL(error(QLocalSocket::LocalSocketError)),this,SLOT(slot_error_proc(QLocalSocket::LocalSocketError))); //数据接收
    connect(m_socket,SIGNAL(connected()),this,SLOT(slot_connect_success()));  //数据接收
    connect(m_socket,SIGNAL(disconnected()),this,SLOT(slotDisconnect_from_server()));  //连接断开
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(slot_rcv_data()));  //数据接收
    m_socket->connectToServer(publicClass::getInstance()->readValueIni("COM/IP"));  //连接到服务器

}
void func::slotDataArrived()
{
    //    //    std::lock_guard<std::mutex> lgd(_mutex);
    _buffer.append(_com);
    _buffer.append(_serialPort->readAll());
    QString ret(_buffer.toHex().toUpper());
    //    slotWriteShareMemory(ret);
    if(ret.simplified().isEmpty()){
        QByteArray err = "error";
        m_socket->write(err);
    }else {
        m_socket->write(_buffer);
    }

    qDebug() << "RECV BMQ:"<<ret;
    _buffer.clear();
}
void func::slotWriteData()
{
    QString STR1 = "1A";
    QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
    _serialPort->write(byte,byte.size());


}
void func::slotWriteShareMemory(QString &data)
{
    //    if(_shareMemory.isAttached())
    //    {
    //        _shareMemory.detach();
    //    }

    //    QBuffer buffer;
    //    QDataStream out(&buffer);
    //    buffer.open(QBuffer::ReadWrite);
    //    buffer.write(data.toLatin1());
    //    int size = buffer.size();
    //    if(!_shareMemory.create(size))
    //    {
    //        qDebug() << _shareMemory.errorString();

    //        return ;
    //    }

    //    _shareMemory.lock();
    //    char *dest = reinterpret_cast<char *>(_shareMemory.data());
    //    const char *source = reinterpret_cast<const char *>(buffer.data().data());
    //    memcpy(dest, source, qMin(size, _shareMemory.size()));
    //    _shareMemory.unlock();
}



void func::slot_rcv_data() //收到数据
{
    QByteArray data = m_socket->readAll();

//    qDebug()<<"data:"<<data;
}

void func::slot_connect_success()
{
    qDebug()<<("连接服务端成功!");
}

void func::slotDisconnect_from_server()
{
    qDebug()<<"[连接断开]";
}

void func::slotReconect_to_server()
{
    _reconnect_timer->stop();
    qDebug()<<("重连...");
    if(m_socket)
        m_socket->connectToServer(publicClass::getInstance()->readValueIni("COM/IP"));
}

void func::slot_error_proc(QLocalSocket::LocalSocketError state)
{
    qDebug()<<("连接服务器失败!");
    qDebug()<<(QString("错误码:%1").arg(QString::number(state)));
    m_socket->close();
    _reconnect_timer->start(1000);  //1s后重连
}
