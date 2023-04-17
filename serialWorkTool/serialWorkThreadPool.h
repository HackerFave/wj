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
    serialWorkThreadPool(int id);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
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
    serialWorkThreadPool_1(int id);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
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
    serialWorkThreadPool_2(int id);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
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
    serialWorkThreadPool_3(int id);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
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
    serialWorkThreadPool_4(int id);
    virtual Q_INVOKABLE void startWork() override;
    virtual Q_INVOKABLE void stopWork() override;
    virtual Q_INVOKABLE void run() override;
    virtual Q_INVOKABLE bool isStart() override { return _isStart;};
public slots:
    virtual Q_INVOKABLE void slotWork() override;
    void slotWorkData(QByteArray data);
private:
    QSerialWork *P_QSerialWork;
    int _id;
    bool _isStart = false;
};
#endif // SERIALWORKTHREADPOOL_H
