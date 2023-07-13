#ifndef CONTROLRMD_H
#define CONTROLRMD_H

#include <QObject>
#include "serialWork.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include "publicinterface.h"
#include "backend485_global.h"
class BACKEND485_EXPORT controlRmd : public QObject
{
    Q_OBJECT
public:
    explicit controlRmd(QObject *parent = nullptr);
    ~controlRmd();
signals:

public slots:
    void slotUpdateData();
private slots:
    void slotState(int err);
    void slotNewData(QByteArray data);

private:
    serialWork* P_Serial;
    QSerialPort *P_port;
    QString _com;
    QTimer _timerRMD;

};

#endif // CONTROLRMD_H
