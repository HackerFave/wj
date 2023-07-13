#include "canDataRecvThread.h"
#include <QtDebug>
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
        VCI_CAN_OBJ Recv[2500];
        DWORD Recv_Len;

        Recv_Len=VCI_Receive(m_DevType, m_DevIndex,m_CanIndex,Recv,2500,0);
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
    }
}
void canDataRecvThread::slotRecvStatus(bool status)
{
    //    _index = num;
}