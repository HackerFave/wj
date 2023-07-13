#ifndef PLCTHREAD_H
#define PLCTHREAD_H

#include <QObject>
#include <QModbusDataUnit>
#include <QModbusRtuSerialMaster>
#include <QModbusClient>
#include <QModbusReply>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "global.h"
#include <QString>
#include <QDebug>
#include <QThread>
#include <QTimer>


class PlcThread : public QObject
{
    Q_OBJECT
public:
    explicit PlcThread(QObject *parent = nullptr);
    ~PlcThread();

    void doWork();
    void connectPlc();

    void readPlc();
    void torqReadReady();
    void spdReadReady();
    void on_writeTor(QString);

signals:
    void startWork();
    void finishWork();

    void statusBar(const QString&);
    void change2Discon();
    void change2Con();


    void updateT(QString);
    void updateS(QString);

public slots:

private:
    QModbusClient *modbusDevice;
    QTimer *dataTimer;
    uchar T[4];
    uchar S[4];

};

#endif // PLCTHREAD_H

