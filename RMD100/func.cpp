#include "func.h"
#include <QtDebug>
#include "publicclass.h"
#include <QDir>
func::func(QObject *parent) : QObject(parent)
{
    //左 0 509958
    //右 423766 9
    init();
    //    exitProcess();//退出编码器进程
    //    _process = new QProcess(0);

    //    _bmqcom = publicClass::getInstance()->readValueIni("COM/A0").simplified();
    //    QString str = QDir::currentPath()+ "/start.bat";//加可执行文件路径

    //    _process->setProcessChannelMode(QProcess::MergedChannels);
    //    _process->start(str);

    //    if (!_process->waitForStarted()) {
    //        qDebug() << "start failed:" << _process->errorString();
    //    } else {
    //        qDebug()  << "[bat]"<< "start success:";
    //    }

    //    connect(&_timerBmqRead,SIGNAL(timeout()),this,SLOT(slotUpdateBmq()));
    //    _timerBmqRead.start(3000);
    //    initServer();
    connect(&_timerEncoder,&QTimer::timeout,this,&func::slotEncoder);
    _timerEncoder.start(10);
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
        //        connect(&_timerTest, &QTimer::timeout, this, &func::slotWriteData);
        connect(_serialPort, &QSerialPort::readyRead, this, &func::slotDataArrived);
        //        _timerTest.start(1000);
        emit signalStatus(QSERIALWORK_ERR_OPEN_SUCCESS);
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

}

void func::slotDataArrived()
{

    _buffer.append(_serialPort->readAll());


    QString ret(_buffer.toHex().toUpper());
    //    if(ret.size()>=8){
    //        QString st;
    //        st.append(ret[6]);
    //        st.append(ret[7]);
    //        int le =  st.toInt(nullptr,16);
    //        if(ret.size()>=len)
    //    }

    //    if(ret.contains(_checkStr)){
    // qDebug() <<"[recv:]"<<ret;
    //        ret.split(_checkStr);
    //        _queRecv.clear();
    //        _queRecv.enqueue(ret.split(_checkStr).at(0));
    qDebug()<<ret<<"NNNNNNNNNNNNNNNNNNNN"<<publicClass::getInstance()->Byte_16(ret,ret.size());
    _buffer.clear();
    //    }

}
void func::slotWriteData()
{
    QString STR1 = "3e 30 01 00 6F";
    qDebug() << "3e 30 01 00 6F" ;
    QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
    _serialPort->write(byte,byte.size());

}
void func::writeData(uint8_t  data[],int len,QString &checkstr)
{
    _checkStr = checkstr;
    _serialPort->write((const char*)data,len);
}

void func::initServer()
{
    m_server = new QLocalServer(this);
    //myserver为服务端名称,类似于IP+PORT,客户端连接需要与其保持一致
    if( m_server->listen("SERVER") ) //监听
    {
        connect(m_server,SIGNAL(newConnection()),this,SLOT(slot_new_connection()));
        qDebug("listen success!!\n");
    }
    else
        qDebug("listen fail\n");
    //m_server->removeServer("myserver");   //如果SERVER已经存在，则需删除
}
void func::slot_new_connection()
{
    QLocalSocket *newsocket = m_server->nextPendingConnection();  //获取连接上的客户端句柄
    connect(newsocket, SIGNAL(readyRead()), this, SLOT(slot_recv_data())); //关联数据接收槽函数
}
void func::slot_recv_data()
{

    // 取得是哪个localsocket可以读数据了l
    QLocalSocket *local = static_cast<QLocalSocket *>(sender());
    if (!local)
        return;

    QByteArray rcv_data = local->readAll();
    QString rcvstr = rcv_data.toHex().toUpper();
    if(rcvstr>8){
        QString head = rcvstr.split("1A").at(0);
        QByteArray byte = QByteArray::fromHex(/*rcvstr.left(10).toUtf8()*/head.toUtf8());
        QString str;
        for(int i = 0; i < byte.count(); ++i)
        {
            str.append(QChar(byte .at(i)));
        }
        if(str==_bmqcom){
            _isOnlineBmq = true;
            QStringList st = publicClass::getInstance()->Byte_16(rcvstr.mid(head.size()),rcvstr.mid(head.size()).size()).split(" ");
            if(st.size()==11){
                QString dataDanquan = st.at(2)+" "+st.at(3)+" "+st.at(4)+" "+"00";
                QString dataFBL = st.at(5);
                QString dataDuoquan = st.at(6)+" "+st.at(7)+" "+st.at(8)+" "+"00";
                int32_t valueDanquan,valueDuoquan ;
                int8_t valueFBL;
                QByteArray byte = QByteArray::fromHex(dataDanquan.toLatin1());
                memcpy(&valueDanquan,byte.data(),byte.size());

                byte =  QByteArray::fromHex(dataFBL.toLatin1());
                memcpy(&valueFBL,byte.data(),byte.size());

                byte =  QByteArray::fromHex(dataDuoquan.toLatin1());
                memcpy(&valueDuoquan,byte.data(),byte.size());
                qDebug()<<"单圈:"<<valueDanquan<<"分辨率:"<<valueFBL<<"多圈"<<valueDuoquan;
                emit signalBmq(valueDanquan,valueFBL,valueDuoquan);
            }

        }

    }
}
void func::exitProcess()
{
    QSharedPointer<QProcess> process(new QProcess(0));
    QString exe ="encoder.exe";
    QString c = "taskkill /f /t /im encoder.exe";    //exeFileName为要杀死的进程名
    process.data()->execute(c);
    process.data()->close();

}
void func::slotUpdateBmq()
{

    if(_isOnlineBmq==true){
        _timerBmqRead.stop();
        qDebug()<<"running";
        return;
    }
    exitProcess();
    QString str = QDir::currentPath()+ "/start.bat";//加可执行文件路径

    _process->setProcessChannelMode(QProcess::MergedChannels);
    _process->start(str);

    if (!_process->waitForStarted()) {
        qDebug() << "start failed:" << _process->errorString();
    } else {
        qDebug()  << "[BMQ]"<< "start success:";
    }
}
void func::slotEncoder()
{

    QString STR1 = "3e 9c 01 00 DB";
    QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
    _serialPort->write(byte,byte.size());
}
