//#include "thread.h"

//Thread::Thread()
//{

//}

#include "thread.h"
#include "mainwindow.h"
Thread::Thread(int s,QObject *parent) :
    QThread(parent)
{
    socket  = s;
    running = true;
}

void Thread::run()
{
    //qDebug()<<"start can receive Thread!";
    int nbytes;
    int len;
    struct can_frame frame;
    struct sockaddr_can addr;
    char buf[8];

    while(running){
        nbytes=recvfrom(socket,&frame,sizeof(struct can_frame),0,(struct sockaddr *)&addr,(socklen_t*)&len);
        //接收can数据：方式一
//        if(nbytes>0){
//            memset(buf,0,8);
//            strncpy(buf,(char*)frame.data,8);
//            //emit message(&addr,&len);
//             printf("id=%x,len=%d\n",(struct sockaddr *)&addr,(socklen_t*)&len);
//        }
        //接收can数据：方式二
          nbytes = read(socket, &frame, sizeof(frame)); //接收报文
          if(nbytes > 0){
            printf("id=%x,len=%d,data=%x%x%x%x%x%x%x%x\n",frame.can_id&0x7fffffff,frame.can_dlc,frame.data[0],frame.data[1],frame.data[2],frame.data[3],frame.data[4],frame.data[5],frame.data[6],frame.data[7]);
          }
    }

}

void Thread::stop()
{
    running = false;
}
