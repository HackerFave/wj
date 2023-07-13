//#ifndef THREAD_H
//#define THREAD_H


//class Thread : public QThread
//{
//public:
//    Thread();
//};

//#endif // THREAD_H

#ifndef THREAD_H
#define THREAD_H

#include <QThread>
extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
}
#ifndef PF_CAN
#define PF_CAN 29
#endif

#ifndef AF_CAN
#define AF_CAN PF_CAN
#endif

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(int s,QObject *parent = 0);

signals:
    void message(sockaddr addr,socklen_t num);
public slots:
    void run();
    void stop();

private:
    int socket;
    bool running;

};

#endif // THREAD_H
