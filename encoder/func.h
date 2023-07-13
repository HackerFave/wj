#ifndef FUNC_H
#define FUNC_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMap>
#include "basethreadpool.h"
#include <QThreadPool>
#include "serialWorkThreadPool.h"
#include <QTimer>
#include <QSharedMemory>
#include <QBuffer>
#include <QDataStream>
#include <QtNetwork/QLocalServer>
#include <QtNetwork/QLocalSocket>
#define QSERIALWORK_ERR_OK               0
#define QSERIALWORK_ERR_OPEN_SUCCESS     1
#define QSERIALWORK_ERR_OPEN_FAILED      2
class func : public QObject
{
    Q_OBJECT
public:
    explicit func(QObject *parent = nullptr);
    ~func();
private:
    QSerialPort *init();
    void initThread();
    void initClient();
    void reset();
signals:
    void signalStatus(int);
private slots:
    void slotWriteData();
    void slotDataArrived();
    void slotWriteShareMemory(QString & data);
    void slotReconect_to_server();
    void slotDisconnect_from_server();
    void slot_rcv_data();
    void slot_connect_success();
    void slot_error_proc(QLocalSocket::LocalSocketError state);
private:
    QSerialPort* _serialPort;
    QThreadPool _pool;
    QMap<int,baseThreadPool*> _threadMap;
    QTimer _timerTest;
    QByteArray _buffer;
//    QSharedMemory _shareMemory;
    QLocalSocket *m_socket=nullptr;
    QTimer *_reconnect_timer = nullptr;
    QByteArray _com = "";
};

#endif // FUNC_H
