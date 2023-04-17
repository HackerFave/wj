#include "serialWorkThreadPool.h"
#include "ControlCAN.h"
#define TT 0
serialWorkThreadPool::serialWorkThreadPool(int id):
    _id(id)
{
}
Q_INVOKABLE void serialWorkThreadPool::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool::slotWork()
{
}
void serialWorkThreadPool::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool::run()
{
    while (_isStart) {
#if TT
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "602";
        QStringList sendMsg;
        sendMsg.append(QString("43 0D 30 00 00 00 00 00"));//线圈温度
        sendMsg.append(QString("43 0E 30 00 00 00 00 00"));//模块温度
        sendMsg.append(QString("43 05 30 00 00 00 00 00"));//电机电流
        sendMsg.append(QString("43 09 30 00 00 00 00 00"));//母线电压
        sendMsg.append(QString("40 0A 30 00 00 00 00 00"));//告警码
        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//告警码

        sendMsg.append(QString("43 64 60 00 00 00 00 00"));//编码器绝对位置
        sendMsg.append(QString("43 0F 30 00 00 00 00 00"));//第二位置编码器
        sendMsg.append(QString("43 63 60 00 00 00 00 00"));//当前电机位置
        sendMsg.append(QString("43 7A 60 00 00 00 00 00"));//目标位置
        sendMsg.append(QString("43 08 30 00 00 00 00 00"));//第一位置编码器
        //        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//告警码

        for(int i=0;i<11;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(1000);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
#endif
    }
}
serialWorkThreadPool_1::serialWorkThreadPool_1(int id):
    _id(id)
{
}
Q_INVOKABLE void serialWorkThreadPool_1::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_1::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_1::slotWork()
{

}
void serialWorkThreadPool_1::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_1::run()
{
    while (_isStart) {
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "141";
        QStringList sendMsg;
        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
        sendMsg.append(QString("33 00 00 00 00 00 00 00"));//读取加速度
        sendMsg.append(QString("90 00 00 00 00 00 00 00"));//读取编码器
        sendMsg.append(QString("92 00 00 00 00 00 00 00"));//读取多圈角度命令
        sendMsg.append(QString("94 00 00 00 00 00 00 00"));//读取单圈角度命令
        sendMsg.append(QString("9A 00 00 00 00 00 00 00"));//读取电机状态1和错误标志命令

        sendMsg.append(QString("9C 00 00 00 00 00 00 00"));//读取电机状态2
        sendMsg.append(QString("9D 00 00 00 00 00 00 00"));//读取电机状态3

        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(3000);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
    }
}

serialWorkThreadPool_2::serialWorkThreadPool_2(int id):
    _id(id)
{
}
Q_INVOKABLE void serialWorkThreadPool_2::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_2::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_2::slotWork()
{
}
void serialWorkThreadPool_2::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_2::run()
{
    while (_isStart) {
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "143";
        QStringList sendMsg;
        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
        sendMsg.append(QString("33 00 00 00 00 00 00 00"));//读取加速度
        sendMsg.append(QString("90 00 00 00 00 00 00 00"));//读取编码器
        sendMsg.append(QString("92 00 00 00 00 00 00 00"));//读取多圈角度命令
        sendMsg.append(QString("94 00 00 00 00 00 00 00"));//读取单圈角度命令
        sendMsg.append(QString("9A 00 00 00 00 00 00 00"));//读取电机状态1和错误标志命令

        sendMsg.append(QString("9C 00 00 00 00 00 00 00"));//读取电机状态2
        sendMsg.append(QString("9D 00 00 00 00 00 00 00"));//读取电机状态3

        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(3000);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
    }
}

serialWorkThreadPool_3::serialWorkThreadPool_3(int id):
    _id(id)
{
}
Q_INVOKABLE void serialWorkThreadPool_3::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_3::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_3::slotWork()
{
}
void serialWorkThreadPool_3::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_3::run()
{
    while (_isStart) {
        _sleep(3000);
    }
}

serialWorkThreadPool_4::serialWorkThreadPool_4(int id):
    _id(id)
{
}
Q_INVOKABLE void serialWorkThreadPool_4::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_4::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_4::slotWork()
{

}
void serialWorkThreadPool_4::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_4::run()
{
    while (_isStart) {
        _sleep(3000);
    }
}
