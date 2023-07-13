#ifndef SERIALWORK_H
#define SERIALWORK_H

#include <QObject>
#include <QSerialPort>
#include <QTimer>
#include <mutex>
#define SERIALWORK_ERR_OK               0
#define SERIALWORK_ERR_OPEN_SUCCESS     1
#define SERIALWORK_ERR_OPEN_FAILED      2

class serialWork : public QObject
{
    Q_OBJECT
public:
    explicit serialWork(QObject *parent = nullptr);

    ~serialWork();

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
//    void slotWriteData();
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
    QByteArray _buffer;
    std::mutex _mutex;
};

#endif // QSERIALWORK_H
