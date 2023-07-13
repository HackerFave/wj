#include "canDataRecvThread.h"
#include <QtDebug>
#include <QTime>
canDataRecvThread::canDataRecvThread(const DWORD &DevType ,const DWORD &DevIndex,const DWORD &CanIndex):
    m_DevType(DevType),
    m_DevIndex(DevIndex),
    m_CanIndex(CanIndex)
{
    //    qRegisterMetaType<UINT>("UINT");
    //    qRegisterMetaType<BYTE>("BYTE");
    qRegisterMetaType<VCI_CAN_OBJ>("VCI_CAN_OBJ");
}

Q_INVOKABLE void canDataRecvThread::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void canDataRecvThread::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void canDataRecvThread::slotWork()
{
    while (_isStart) {
#if CANDEV_CX
        VCI_CAN_OBJ Recv[2500];
        DWORD Recv_Len;

        Recv_Len=VCI_Receive(m_DevType, m_DevIndex,m_CanIndex,Recv,2500,10);
        if(Recv_Len==1||Recv_Len==2)
        {
            emit signalRecvStatus(true);
            emit signalSendRecvData(Recv,Recv_Len,m_CanIndex); //接收到数据
            //             qDebug()<<"Recv_Len:"<<Recv_Len;
        }
        else if (Recv_Len>10) {
            //            qDebug()<<"Recv_Len:"<<Recv_Len;
            emit signalSendError(m_CanIndex);
        }
#endif

#if CANDEV_GC
        DWORD dwRel;
        CAN_OBJ vco[100];
        dwRel = Receive(3, 0, 0, vco, 100, 10);

        if(dwRel>0){
            emit signalSendRecvData(vco,dwRel,0); //接收到数据
        }
        else {
            if(_numStart==0){
                _numStart =  QTime::currentTime().second();
            }
            _numEnd=  QTime::currentTime().second();
            if(_numEnd-_numStart>=15){
                emit signalReset();
                _numStart = 0;
            }

        }
#endif
    }
}
void canDataRecvThread::slotRecvStatus(QString status)
{
    //    _index = num;
}
//void canDataRecvThread::slotReset()
//{
//    emit signalReset();
//    qDebug()<<QThread::currentThreadId()<<"2222222222222222222222222222222";
//    _timerReset.stop();
//}
