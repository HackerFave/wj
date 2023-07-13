#ifndef SERIALWORKTHREADPOOL_H
#define SERIALWORKTHREADPOOL_H

#include "thread/basethreadpool.h"
#include "methord/qserialwork.h"
#include "public/publicclass.h"
enum ID{
    ID_1 = 0X01,
    ID_2,
    ID_3,
    ID_4,
    ID_5
};

class serialWorkThreadPool : public baseThreadPool/*, public QSerialWork*/
{
public:
    serialWorkThreadPool(int id,QSerialWork *QSerialWork =nullptr);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override{
        while (_isStart) {
            qDebug()<<"线程ID----------->0"<<QThread::currentThreadId();
//            QString datahead ="3e 9a 01 00";
//            QByteArray byteHead = QByteArray::fromHex(datahead.toLatin1());
//            unsigned char p = publicClass::getInstance()-> cllc_checkSum((unsigned char *)byteHead.data(),byteHead.size());
//            QString src =  publicClass::getInstance()-> Byte_16(&p,sizeof (char));
//            QString send = datahead;
//            datahead = QString(datahead+" "+src);
//            QString  data = QString(datahead);
//            QByteArray byte = QByteArray::fromHex(data.toLatin1());
//            P_QSerialWork->WriteData(byte,byte.size());
            _sleep(3000);
        }
    };
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
};

class serialWorkThreadPool_1 : public baseThreadPool/*, public QSerialWork*/
{
public:
    serialWorkThreadPool_1(int id, QSerialWork *QSerialWork =nullptr);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override{
        while (_isStart) {
            qDebug()<<"线程ID----------->1"<<QThread::currentThreadId();
//            QString datahead ="3e 9c 03 00";
//            QByteArray byteHead = QByteArray::fromHex(datahead.toLatin1());
//            unsigned char p = publicClass::getInstance()-> cllc_checkSum((unsigned char *)byteHead.data(),byteHead.size());
//            QString src =  publicClass::getInstance()-> Byte_16(&p,sizeof (char));
//            QString send = datahead;
//            datahead = QString(datahead+" "+src);
//            QString  data = QString(datahead);
//            QByteArray byte = QByteArray::fromHex(data.toLatin1());
//            P_QSerialWork->WriteData(byte,byte.size());
            _sleep(3000);
        }
    };
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
};
class serialWorkThreadPool_2 : public baseThreadPool/*, public QSerialWork*/
{
public:
    serialWorkThreadPool_2(int id, QSerialWork *QSerialWork =nullptr);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override{
        while (_isStart) {
            qDebug()<<"线程ID----------->2"<<QThread::currentThreadId();
//            QString datahead ="3e 9a 03 00";
//            QByteArray byteHead = QByteArray::fromHex(datahead.toLatin1());
//            unsigned char p = publicClass::getInstance()-> cllc_checkSum((unsigned char *)byteHead.data(),byteHead.size());
//            QString src =  publicClass::getInstance()-> Byte_16(&p,sizeof (char));
//            QString send = datahead;
//            datahead = QString(datahead+" "+src);
//            QString  data = QString(datahead);
//            QByteArray byte = QByteArray::fromHex(data.toLatin1());
//            P_QSerialWork->WriteData(byte,byte.size());
            _sleep(3000);
        }
    };
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
};
class serialWorkThreadPool_3 : public baseThreadPool/*, public QSerialWork*/
{
public:
    serialWorkThreadPool_3(int id, QSerialWork *QSerialWork =nullptr);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override{
        while (_isStart) {
            qDebug()<<"线程ID----------->3"<<QThread::currentThreadId();
            _sleep(3000);
        }
    };
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
};
class serialWorkThreadPool_4 : public baseThreadPool/*, public QSerialWork*/
{
public:
    serialWorkThreadPool_4(int id, QSerialWork *QSerialWork =nullptr);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override{
        while (_isStart) {
            qDebug()<<"线程ID----------->4"<<QThread::currentThreadId();
            _sleep(3000);
        }
    };
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
};
#endif // SERIALWORKTHREADPOOL_H
