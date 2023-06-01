#ifndef SERIALWORKTHREADPOOL_H
#define SERIALWORKTHREADPOOL_H

#include "thread/basethreadpool.h"
#include "methord/qserialwork.h"
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

class serialWorkThreadPool_MT_141 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_MT_141(int id,const int CanId);
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

class serialWorkThreadPool_MT_142 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_MT_142(int id,const int CanId);
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
class serialWorkThreadPool_MT_143 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_MT_143(int id,const int CanId);
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
class serialWorkThreadPool_MT_145 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_MT_145(int id,const int CanId);
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
class serialWorkThreadPool_TT_601 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_TT_601(int id,const int CanId);
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
class serialWorkThreadPool_LX_603 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_LX_603(int id,const int CanId);
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
class serialWorkThreadPool_YK_602 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_YK_602(int id,const int CanId);
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
class serialWorkThreadPool_XT_01 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_XT_01(int id,const int CanId);
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
class serialWorkThreadPool_XT_02 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_XT_02(int id,const int CanId);
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
    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QSharedMemory _sharememory;
    QString _COM_port;
};

//编码器读取线程
class serialWorkThreadPool_BMQ_A2 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_A2(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
    int32_t _minValueDuo_A2 = 0;
    int32_t _minValueDan_A2 = 0;
    int32_t _maxValueDuo_A2 = 0;
    int32_t _maxValueDan_A2 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};
//编码器读取线程
class serialWorkThreadPool_BMQ_A3 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_A3(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
    int32_t _minValueDuo_A3 = 0;
    int32_t _minValueDan_A3 = 0;
    int32_t _maxValueDuo_A3 = 0;
    int32_t _maxValueDan_A3 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};
//编码器读取线程
class serialWorkThreadPool_BMQ_A4 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_A4(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
//    int32_t _minValueDuo_A4 = 0;
    int32_t _minValueDan_A4 = 0;
//    int32_t _maxValueDuo_A4 = 0;
    int32_t _maxValueDan_A4 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};
//编码器读取线程
class serialWorkThreadPool_BMQ_A8 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_A8(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
    int32_t _minValueDuo_A8 = 0;
    int32_t _minValueDan_A8 = 0;
    int32_t _maxValueDuo_A8 = 0;
    int32_t _maxValueDan_A8 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};

//编码器读取线程 零差云控软限位
class serialWorkThreadPool_BMQ_A1 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_A1(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
    int32_t _minValueDuo_A1 = 0;
    int32_t _minValueDan_A1 = 0;
    int32_t _maxValueDuo_A1 = 0;
    int32_t _maxValueDan_A1 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};

//编码器读取线程 鑫拓电机01软限位
class serialWorkThreadPool_BMQ_XT_1 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_XT_1(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
    int32_t _minValueDuo_BMQ_XT_1 = 0;
    int32_t _minValueDan_BMQ_XT_1 = 0;
    int32_t _maxValueDuo_BMQ_XT_1 = 0;
    int32_t _maxValueDan_BMQ_XT_1 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};
//编码器读取线程 鑫拓电机02软限位
class serialWorkThreadPool_BMQ_XT_2 : public baseThreadPool/*, public QSerialWork*/
{
    Q_OBJECT
public:
    serialWorkThreadPool_BMQ_XT_2(QString &COM);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QString COM,int32_t duo,int32_t dan);
    void slotMachineData(int32_t &data);
signals:
//    void signalComData(QString data,QString com);
private:
    bool _isStart = false;
    QString _COM_port;
    int32_t _minValueDuo_BMQ_XT_2 = 0;
    int32_t _minValueDan_BMQ_XT_2 = 0;
    int32_t _maxValueDuo_BMQ_XT_2 = 0;
    int32_t _maxValueDan_BMQ_XT_2 = 0;
    bool _isNeedStopMachine_right = false;
    bool _isNeedStopMachine_left = false;
    int32_t _rpm = 0;
};
#endif // SERIALWORKTHREADPOOL_H
