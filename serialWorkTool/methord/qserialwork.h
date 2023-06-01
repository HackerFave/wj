#ifndef QSERIALWORK_H
#define QSERIALWORK_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>
#include <mutex>
#include "public/publicclass.h"
#define QSERIALWORK_ERR_OK               0
#define QSERIALWORK_ERR_OPEN_SUCCESS     1
#define QSERIALWORK_ERR_OPEN_FAILED      2

class QSerialWork : public QObject
{
    Q_OBJECT
public:
    explicit QSerialWork(QObject *parent = nullptr);

    ~QSerialWork();

    QSerialPort* InitSerialPort();

    bool isOpen();
    void setState(int error);
    int getState() const;
    void waitForReadyRead(int);
    QByteArray SendData_Syn(const char* sendData, uint ulen, uint expectReceiveLen);
public slots:

    void OpenPort(QString portName,QSerialPort::BaudRate flag,QSerialPort::DataBits bit);

    void ClosePort();

    void WriteData(const QByteArray& buf, qint64 len);
    void timeUpdate();
    void slotWriteData();
private slots:

    void DataArrived();

signals:

    void NewData(QByteArray data);

    void State(int err);

private:

    QSerialPort* m_serialPort;

    bool m_isOpen;
    int _errorState;
    QTimer _timer;
    QTimer _timerTest;
    QByteArray _buffer;
    std::mutex _mutex;
//    QStringList _list;
//    QString _str;
};

#endif // QSERIALWORK_H
