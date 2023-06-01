#include "canDataSendThread.h"

canDataSendThread::canDataSendThread()
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
        canBufstruct st ;
        int flag =0;
//        std::lock_guard<std::mutex> lgd(_mutex);
        if(publicClass::getInstance()->_canbuf.size()>0){
            st = publicClass::getInstance()->getBj();
            if(_isTrue){
                flag=VCI_Transmit(4,0,st.canIndex,&st.bj,1); //调用动态链接库发送函数
                if(flag<1)  //发送不正常
                {
                    qDebug()<<QStringLiteral("发送失败")<<publicClass::getInstance()->Byte_16(st.bj.Data,8)<<"XXXXXXXXXXXXXXXXXX"<<QThread::currentThreadId();
                    //                    publicClass::getInstance()->_queCanBuf.enqueue(bj);
                    //                    while (1) {
                    //                        flag=VCI_Transmit(4,0,st.canIndex,&st.bj,1); //调用动态链接库发送函数
                    //                        _sleep(10);
                    //                    }

                }
                else {
                    //                    qDebug()<<QStringLiteral("发送成功")<<publicClass::getInstance()->Byte_16(st.bj.Data,8)<<"!!!!!!!!!!!!!!!!!!!!!!!!!"<<QThread::currentThreadId();
                    _isTrue = false;
                }
            }
        }
        _sleep(10);
    }
}
void canDataSendThread::slotSendCanBuf(void * data,int length,int canIndex)
{

}
void canDataSendThread::slotRecvStatus(bool istrue)
{
    _isTrue = istrue;
    //    qDebug()<<_isTrue<<"LLLLLLLLLLLLLLLLLLLLLLLLLLLL";
}
void canDataSendThread::slotRecvId(QString id)
{
    _id = id;
}
