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
        if(Recv_Len>0)
        {
            emit signalSendRecvData(Recv,Recv_Len); //接收到数据
            qDebug()<<("RECV:")<<"[len=]"<<Recv_Len<<"[CAN:]"<<m_CanIndex;
        }
    }
}
void canDataRecvThread::slotRecvStatus(QString status)
{
    //    _index = num;
}
