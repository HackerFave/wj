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
#include <QProcess>
#include <QQueue>
#define QSERIALWORK_ERR_OK               0
#define QSERIALWORK_ERR_OPEN_SUCCESS     1
#define QSERIALWORK_ERR_OPEN_FAILED      2
class func : public QObject
{
    Q_OBJECT
public:
    explicit func(QObject *parent = nullptr);
    ~func();
    void writeData(uint8_t  data[],int len,QString &checkstr);

private:
    QSerialPort *init();
    void initServer();
    void exitProcess();
signals:
    void signalStatus(int);
    void signalBmq(int32_t,int32_t,int32_t);
private slots:
    void slotWriteData();
    void slotDataArrived();
    void slotUpdateBmq();
    void slot_new_connection();
    void slot_recv_data();
    void slotEncoder();
private:
    QSerialPort* _serialPort;
    QTimer _timerTest;
    QByteArray _buffer;
    QLocalSocket *m_socket=nullptr;
    QTimer *_reconnect_timer = nullptr;
    QByteArray _com = "";

    QLocalServer *m_server = nullptr;

    QList<QLocalSocket*> _local_sockets;
    QProcess *_process = nullptr;
    QTimer _timerBmqRead;
    bool _isOnlineBmq = false;
    QString _bmqcom = "";
    QString _checkStr = "";
    QQueue<QString> _queRecv;
    QTimer _timerEncoder;
};

#endif // FUNC_H
