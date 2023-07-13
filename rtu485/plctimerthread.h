#ifndef PLCTIMERTHREAD_H
#define PLCTIMERTHREAD_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QTime>
#include <QString>
#include "ui_mainwindow.h"
#include <QMainWindow>

#include <QModbusDataUnit>
#include <QModbusRtuSerialMaster>
#include <QModbusClient>
#include <QModbusReply>

#include <QSerialPort>
#include <QSerialPortInfo>

class PlcTimerThread : public QObject
{
    Q_OBJECT
public:
    explicit PlcTimerThread(QObject *parent = nullptr);
    ~PlcTimerThread();
public:
    void run();
    void dowork();
    void printSpinBox(int);
signals:
    void workStart();
    void workFinished();
    void upDateTime(QString);
private:
    QTimer *timer;
    QString str_time;
    int spinbox;


public slots:
};

#endif // PLCTIMERTHREAD_H

