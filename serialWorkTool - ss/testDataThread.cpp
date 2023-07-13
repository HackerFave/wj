#include "testDataThread.h"
#include <QtDebug>
testDataThread::testDataThread(QSerialWork *port):_port(port)
{

}

Q_INVOKABLE void testDataThread::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void testDataThread::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void testDataThread::slotWork()
{
    while (_isStart) {

        QString datahead ="3e 9a 01 00";
        QByteArray byteHead = QByteArray::fromHex(datahead.toLatin1());
        unsigned char p = publicClass::getInstance()-> cllc_checkSum((unsigned char *)byteHead.data(),byteHead.size());
        QString src =  publicClass::getInstance()-> Byte_16(&p,sizeof (char));
        QString send = datahead;
        datahead = QString(datahead+" "+src);
        QString  data = QString(datahead);
        QByteArray byte = QByteArray::fromHex(data.toLatin1());
        _port->WriteData(byte,byte.size());
        qDebug()<<"***************************************************";
        _sleep(3000);

    }
}
