#ifndef MESSAGEREPORTTHREADPOOL_H
#define MESSAGEREPORTTHREADPOOL_H

#include "basethreadpool.h"
#include "public/publicclass.h"
#include <QSharedMemory>
#include <QBuffer>
#include <QObject>
enum ID{
    ID_1 = 0X01,
    ID_2,
    ID_3,
    ID_4,
    ID_5
};

class serialWorkThreadPool : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};

class serialWorkThreadPool_1 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_1(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};
class serialWorkThreadPool_2 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_2(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};
class serialWorkThreadPool_3 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_3(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};
class serialWorkThreadPool_4 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_4(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};
//编码器读取线程
class serialWorkThreadPool_BMQ : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
    void DataArrived();
    void slotReadShareMemory();
signals:
    void signalComData(QString data);
private:
    bool _isStart = false;
    QSharedMemory _sharememory;
    QString _COM_port;
};
class serialWorkThreadPool_6 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_6(int id,const int CanId);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
    void setCurrentCanId( int canId){_CanId = canId;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
    int _CanId;
};
#endif // SERIALWORKTHREADPOOL_H
