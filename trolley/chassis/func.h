#ifndef FUNC_H
#define FUNC_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMap>
#include <QThreadPool>
#include <QTimer>
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#include "chassis_global.h"
#include "publicclass.h"
#define QSERIALWORK_ERR_OK               0
#define QSERIALWORK_ERR_OPEN_SUCCESS     1
#define QSERIALWORK_ERR_OPEN_FAILED      2
class CHASSIS_EXPORT func : public QObject
{
    Q_OBJECT
public:
    explicit func(QString com,QObject *parent = nullptr);
    ~func();
    /**********底盘运动**********/
    void frontMove();//向前
    void backMove();//向后
    void throttleMoved(int position);//油门
    void stopMove();//停止
private:
    void control(QString value);//控制底盘
    QSerialPort *init();
    void initThread();
signals:
    void signalStatus(int);
private slots:
    void slotDataArrived();
private:
    QSerialPort* _serialPort;
    QByteArray _buffer;
    QString _com = "";
    QQueue<QString> _data485;
    std::mutex _mutex;
};

#endif // FUNC_H
