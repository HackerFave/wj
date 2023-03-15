#ifndef NET485_H
#define NET485_H

#include <QObject>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Net485 : public QObject
{
    Q_OBJECT
public:
    explicit Net485(long baud_rate, QString port_name,QObject *parent = nullptr);
    bool send(BYTE data[], int length);
protected:
    void set_up_serial_port(long baud);

private:

    HANDLE serial_port;

signals:

};

#endif // NET485_H



