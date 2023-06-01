#include "canDataSendThread.h"

canDataSendThread::canDataSendThread(const DWORD &DevType ,const DWORD &DevIndex,const DWORD &CanIndex):
    m_DevType(DevType),
    m_DevIndex(DevIndex),
    m_CanIndex(CanIndex)
{
    qRegisterMetaType<VCI_CAN_OBJ>("VCI_CAN_OBJ");
    qRegisterMetaType<void*>("void*");
}
Q_INVOKABLE void canDataSendThread::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void canDataSendThread::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void canDataSendThread::slotWork()
{
    while (_isStart) {
        VCI_CAN_OBJ bj ;
        int flag =0;
        if(_queCanBuf.size()>0){
            std::lock_guard<std::mutex> lgd(_mutex);
            bj = _queCanBuf.dequeue();
            flag=VCI_Transmit(m_DevType,m_DevIndex,m_CanIndex,&bj,1); //调用动态链接库发送函数
            if(flag<1)  //发送不正常
            {
                qDebug()<<QStringLiteral("发送失败")<<publicClass::getInstance()->Byte_16(bj.Data,8);

            }
            else {
                qDebug()<<QStringLiteral("发送成功")<<publicClass::getInstance()->Byte_16(bj.Data,8)<<m_CanIndex;
                _isStart = false;
            }
        }

    }
}
void canDataSendThread::slotSendCanBuf(void * data,int length)
{
    std::lock_guard<std::mutex> lgd(_mutex);
    VCI_CAN_OBJ bj;
    memmove(&bj,data,length);
    _queCanBuf.enqueue(bj);
}
void canDataSendThread::slotRecvStatus(QString status)
{

}
void canDataSendThread::slotRecvId(QString id)
{
    _id = id;
}
