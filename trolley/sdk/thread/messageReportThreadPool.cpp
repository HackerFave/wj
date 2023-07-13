#include "messageReportThreadPool.h"
#define TT 0
#define MS 100
messageReportThreadPool_MT_141::messageReportThreadPool_MT_141(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_MT_141::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_MT_141::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_MT_141::slotWork()
{
}
void messageReportThreadPool_MT_141::slotWorkData(QByteArray data)
{
}
void messageReportThreadPool_MT_141::run()
{
    while (_isStart) {

#if CANDEV_CX
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "141";
        QStringList sendMsg;
        //        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
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
            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
#endif

#if CANDEV_GC
        CAN_OBJ frame;
        memset(&frame,0,sizeof(frame));
        frame.ID=0x141/*&0x7FF*/;
        frame. DataLen=8;
        frame. SendType=0;
        frame. RemoteFlag=0;
        frame. ExternFlag=0;
        QString sendMsg=QString("9C 00 00 00 00 00 00 00");//读取电机状态2
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg,frame.Data,&frame.DataLen);
        //        memcpy(frame.Data,data, frame.DataLen);
        _sleep(MS);
        if(Transmit(3, 0, 0,&frame,1) !=STATUS_OK)
        {
            qDebug()<<"[ID:141]"<<"[ERROR]"<<"SEND DATA FAILED!";
        }
        else {
            //            qDebug()<<"[ID:141]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId;
        }
#endif
    }


}

messageReportThreadPool_MT_145::messageReportThreadPool_MT_145(int id,int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_MT_145::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_MT_145::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_MT_145::slotWork()
{
}
void messageReportThreadPool_MT_145::slotWorkData(QByteArray data)
{
}
void messageReportThreadPool_MT_145::run()
{
    while (_isStart) {
#if CANDEV_CX
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "145";
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


            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;

            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
#endif
#if CANDEV_GC
        CAN_OBJ frame;
        memset(&frame,0,sizeof(frame));
        frame.ID=0x145;
        frame. DataLen=8;
        frame. SendType=0;
        frame. RemoteFlag=0;
        frame. ExternFlag=0;
        //            BYTE data[]={1,2,3,4,5,6,7,8};
        QString sendMsg=QString("9C 00 00 00 00 00 00 00");//读取电机状态2
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg,frame.Data,&frame.DataLen);
        //        memcpy(frame.Data,data, frame.DataLen);
        _sleep(MS);
        if(Transmit(3, 0, 0,&frame,1) !=STATUS_OK)
        {
            qDebug()<<"[ID:145]"<<"[ERROR]"<<"SEND DATA FAILED!";
        }
        else {
            //            qDebug()<<"[ID:145]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId;
        }
#endif

    }
}
messageReportThreadPool_LX_603::messageReportThreadPool_LX_603(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_LX_603::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_LX_603::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_LX_603::slotWork()
{
}
void messageReportThreadPool_LX_603::slotWorkData(QByteArray data)
{

}
void messageReportThreadPool_LX_603::run()
{
    while (_isStart) {
#if CANDEV_CX
        VCI_CAN_OBJ sendbuf[12];
        bool ok;
        QString id = "603";
        QStringList sendMsg;
        //        sendMsg.append(QString("00 05 00 01"));
        //        sendMsg.append(QString("00 02"));
        //        sendMsg.append(QString("00 08"));

        sendMsg.append(QString("40 6C 60 00 00 00 00 00"));//获取实际速度
        sendMsg.append(QString("40 64 60 00 00 00 00 00"));//获取当前位置
        sendMsg.append(QString("40 3F 60 00 00 00 00 00"));//错误码
        sendMsg.append(QString("40 78 60 00 00 00 00 00"));//电机实际电流
        sendMsg.append(QString("40 75 60 00 00 00 00 00"));//电机额定电流
        sendMsg.append(QString("40 77 60 00 00 00 00 00"));//电机实际扭矩
        sendMsg.append(QString("40 40 22 00 00 00 00 00"));//电机编码器位置
        sendMsg.append(QString("40 A2 22 00 00 00 00 00"));//驱动器温度
        sendMsg.append(QString("40 69 60 00 00 00 00 00"));//速度传感器实际值
        sendMsg.append(QString("40 78 60 00 00 00 00 00"));//电机实际电流
        sendMsg.append(QString("40 79 60 00 00 00 00 00"));//直流链路电路电压
        sendMsg.append(QString("40 7c 60 00 00 00 00 00"));//原点偏移
        //40 61 60 00 00 00 00 00 //读取当前运行模式
        //40 6C 60 00 00 00 00 00 获取实际速度
        //40 64 60 00 00 00 00 00 获取当前位置
        //        40 64 60 00 00 00 00 00
        // 3F 60 错误码
        //   78 60 电机实际电流
        // 61 60 操作模式
        // 41 60 状态字
        // 77 60 电机实际扭矩
        //0d 10 寿命因素
        //17 10 电机心跳时间设置
        // 40 22 电机编码器位置
        //A2 22 驱动器温度
        // 69 60 速度传感器实际值
        // 72 60 最大扭距
        // 73 60最大的电流
        // 78 60 电机实际电流
        //79 60 直流链路电路电压
        // 7b 60 位置范围限制
        // 7c 60 原点偏移
        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）


            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;


            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            _sleep(MS);
            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
#endif
#if CANDEV_GC
        CAN_OBJ sendbuf[3];
        QStringList sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("40 64 60 00 00 00 00 00"));//获取当前位置
        //        sendMsg.append(QString("40 41 60 00 00 00 00 00"));//判断使能 /*"01 0C 00 00 00 00"*/
//        sendMsg.append(QString("01 0C 00 00 00 00"));
        sendMsg.append(QString("00 05 00 01"));//读取速度

        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            //            sendbuf[i].DataLen=8;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            if(i==0){
                sendbuf[i].ID=0x603&0x7FF;
            }else {
                sendbuf[i].ID=0x643;
            }
            flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"[ID:603]"<<"[ERROR]"<<"SEND DATA FAILED!";

            }
            else
            {
                //                qDebug()<<"[ID:601]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId;
            }

        }
#endif
    }
}


messageReportThreadPool_TT_601::messageReportThreadPool_TT_601(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_TT_601::startWork()
{
    _isStart = true;
#if CANDEV_CX
    VCI_CAN_OBJ sendbuf;
    QString id = "01";
    QString sendMsg="10 10";//发送数据
    bool ok;
    sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）


    sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;

    sendbuf.SendType=0;
    sendbuf.TimeFlag=0;
    sendbuf.TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
    ULONG flag;

    flag=VCI_Transmit(4,0,_CanId,&sendbuf,1); //调用动态链接库发送函数
    _sleep(MS);
    if(flag<1)  //发送不正常
    {
        //                             emit signalError("error");

    }
    else {
    }
#endif
#if CANDEV_GC
    CAN_OBJ frame;
    memset(&frame,0,sizeof(frame));
    frame.ID=0x01&0x7FF;
    frame. DataLen=2;
    frame. SendType=0;
    frame. RemoteFlag=0;
    frame. ExternFlag=0;
    frame.Data[0]= 0x10;
    frame.Data[1]= 0x10;
    if(Transmit(3, 0, 0,&frame,1) !=STATUS_OK)
    {
        qDebug()<<"[ID:01]"<<"[ERROR]"<<"SEND DATA FAILED!";
    }
    else
    {
        qDebug()<<"[ID:01]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId<<publicClass::getInstance()->Byte_16(frame.Data,frame.DataLen);
    }
#endif
}
void messageReportThreadPool_TT_601::setInitStatus(bool status)
{
    _initStatus = status;
}
Q_INVOKABLE void messageReportThreadPool_TT_601::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_TT_601::slotWork()
{
}
void messageReportThreadPool_TT_601::slotWorkData(QByteArray data)
{
}
void messageReportThreadPool_TT_601::run()
{
    while (_isStart) {
#if CANDEV_CX
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "601";
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


            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;

            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                //                             emit signalError("error");

            }
            else {
            }
        }
#endif

#if CANDEV_GC

        CAN_OBJ sendbuf[11];
        QStringList sendMsg;
        sendMsg.clear();
        //        sendMsg.append(QString("43 0D 30 00 00 00 00 00"));//线圈温度
        //        sendMsg.append(QString("43 0E 30 00 00 00 00 00"));//模块温度
        //        sendMsg.append(QString("43 05 30 00 00 00 00 00"));//电机电流
        //        sendMsg.append(QString("43 09 30 00 00 00 00 00"));//母线电压
        //        sendMsg.append(QString("40 0A 30 00 00 00 00 00"));//告警码
        //        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//告警码

        //        sendMsg.append(QString("43 64 60 00 00 00 00 00"));//编码器绝对位置
        //        sendMsg.append(QString("43 0F 30 00 00 00 00 00"));//第二位置编码器
        sendMsg.append(QString("43 41 60 00 00 00 00 00"));//判断当前是否使能

        //        sendMsg.append(QString("43 63 60 00 00 00 00 00"));//当前电机位置
        //        sendMsg.append(QString("43 7A 60 00 00 00 00 00"));//目标位置
        //        sendMsg.append(QString("43 08 30 00 00 00 00 00"));//第一位置编码器
        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//电机转速

        //        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//告警码
        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
            sendbuf[i].ID=0x601&0x7FF;
            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            sendbuf[i].DataLen=8;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"[ID:601]"<<"[ERROR]"<<"SEND DATA FAILED!";

            }
            else
            {
                //                qDebug()<<"[ID:601]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId;
            }

        }
#endif

    }


}
messageReportThreadPool_YK_602::messageReportThreadPool_YK_602(int id,const int CanId):
    _id(id),_CanId(CanId)
{

}
Q_INVOKABLE void messageReportThreadPool_YK_602::startWork()
{
    _isStart = true;
#if CANDEV_CX
    VCI_CAN_OBJ sendbuf[4];
    QString id = "602";
    QStringList sendMsgList ;//="10 10";//发送数据
    bool ok;
    //    sendMsgList.push_back("2B 40 60 00 00 00 00 00");
    sendMsgList.push_back("2B 40 60 00 00 00 00 00");
    sendMsgList.push_back("2B 40 60 00 06 00 00 00");
    sendMsgList.push_back("2B 40 60 00 07 00 00 00");
    //    sendMsgList.push_back("2B 40 60 00 0F 00 00 00");
    sendMsgList.push_back(QString("2F 60 60 00 01 00 00 00"));
    for(int i=0;i<4;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）


        sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;

        sendbuf[i].SendType=0;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsgList[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(MS);
        if(flag<1)  //发送不正常
        {
            //                             emit signalError("error");

        }
        else {
        }
    }
#endif

#if CANDEV_GC

    CAN_OBJ sendbuf[4];
    QStringList sendMsgList ;//="10 10";//发送数据
    bool ok;
    //    sendMsgList.push_back("2B 40 60 00 00 00 00 00");
    sendMsgList.push_back("2B 40 60 00 00 00 00 00");
    sendMsgList.push_back("2B 40 60 00 06 00 00 00");
    sendMsgList.push_back("2B 40 60 00 07 00 00 00");
    //    sendMsgList.push_back("2B 40 60 00 0F 00 00 00");
    sendMsgList.push_back(QString("2F 60 60 00 01 00 00 00"));
    for(int i=0;i<4;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
        sendbuf[i].ID=0x602;
        sendbuf[i].SendType=0;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        sendbuf[i].DataLen=8;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsgList[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;

        flag=Transmit(3,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(MS);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"[ID:602]"<<"[ERROR]"<<"SEND DATA FAILED!";

        }
        else
        {
            //            qDebug()<<"[ID:602]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId;
        }
    }
#endif

}
Q_INVOKABLE void messageReportThreadPool_YK_602::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_YK_602::slotWork()
{
}
void messageReportThreadPool_YK_602::slotWorkData(QByteArray data)
{

}
void messageReportThreadPool_YK_602::run()
{
    while (_isStart) {

#if CANDEV_CX
        VCI_CAN_OBJ sendbuf[4];
        bool ok;
        QString id = "602";
        QStringList sendMsg;
        sendMsg.clear();
        //        sendMsg.append(QString("00 05 00 01"));
        //        sendMsg.append(QString("00 02"));
        //        sendMsg.append(QString("00 08"));

        //        sendMsg.append(QString("40 6C 60 00 00 00 00 00"));//获取实际速度
        sendMsg.append(QString("40 64 60 00 00 00 00 00"));//获取当前位置
        //        sendMsg.append(QString("40 3F 60 00 00 00 00 00"));//错误码
        //        sendMsg.append(QString("40 78 60 00 00 00 00 00"));//电机实际电流
        //        sendMsg.append(QString("40 75 60 00 00 00 00 00"));//电机额定电流
        //        sendMsg.append(QString("40 77 60 00 00 00 00 00"));//电机实际扭矩
        //        sendMsg.append(QString("40 40 22 00 00 00 00 00"));//电机编码器位置
        //        sendMsg.append(QString("40 A2 22 00 00 00 00 00"));//驱动器温度
        //        sendMsg.append(QString("40 69 60 00 00 00 00 00"));//速度传感器实际值
        //        sendMsg.append(QString("40 78 60 00 00 00 00 00"));//电机实际电流
        //        sendMsg.append(QString("40 79 60 00 00 00 00 00"));//直流链路电路电压
        //        sendMsg.append(QString("40 7c 60 00 00 00 00 00"));//原点偏移
        for(int i=0;i<sendMsg.size();i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）


            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;

            sendbuf[i].SendType=0;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                //                             emit signalError("error");

            }
            else {
            }
        }
#endif
#if CANDEV_GC
        CAN_OBJ sendbuf;
        QString sendMsg =(QString("40 64 60 00 00 00 00 00"));//获取当前位置
        for(int i=0;i<sendMsg.size();i++){
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
            sendbuf.ID=0x602&0x7ff;
            sendbuf.DataLen=8;
            sendbuf.SendType=0;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
            ULONG flag;
            flag=Transmit(3,0,0,&sendbuf,1); //调用动态链接库发送函数
            _sleep(MS);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"[ID:602]"<<"[ERROR]"<<"SEND DATA FAILED!";

            }
            else {
                //                qDebug()<<"[ID:602]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId;
            }
        }
#endif
    }
}

MachineEnableThreadPool::MachineEnableThreadPool(int id,const int CanId):
    _id(id),_CanId(CanId)
{

}
Q_INVOKABLE void MachineEnableThreadPool::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void MachineEnableThreadPool::stopWork()
{
    _isStart = false;

}
Q_INVOKABLE void MachineEnableThreadPool::slotWork()
{

}
void MachineEnableThreadPool::setStatusEnable(int32_t ID,bool status)
{
    switch (ID) {
    case 0x601:{
        _isTTEnable = status;
        break;
    }
    case 0x603:{
        _isLXEnable = status;
        break;
    }
    case 0x141:{
        _isRmd141Enable = status;
        break;
    }
    case 0x145:{
        _isRmd145Enable = status;
        break;
    }
    default:
        break;
    }
}
void MachineEnableThreadPool::run()
{
    while (_isStart) {

#if CANDEV_CX

#endif
#if CANDEV_GC
        if(!_isLXEnable){
            enableLX();
            _isLXEnable= true;
        }

        if(!_isTTEnable){
            enableTT();
            //            _isTTEnable= true;
        }
#endif
        _sleep(2000);
    }
}
void MachineEnableThreadPool::enableLX()
{
#if CANDEV_GC

    qDebug()<<"ENABLE LX!!!";
#if 0
    CAN_OBJ sendbuf[9];
    QStringList sendMsg;
    //    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    //    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式
    sendMsg.append(QString("00 88 00 00 27 10"));//设置加速度为 10000 count/s²
    sendMsg.append(QString("00 89 00 00 27 10"));//设置减速度为 10000 count/s²
    sendMsg.append(QString("00 8A 00 00 27 10"));//设置目标速度为 10000 count/s
    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能
    //    sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
    /***
     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
     * */
    //450953 限位
    //    sendMsg.append(QString("00 86 00 06 E1 89"));//262144count 相当于180度=262144*（360/524287） 目标位置 89 E1 06 00
    //    sendMsg.append(QString("00 83"));//开始运动
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
        sendbuf[i].ID=0x643&0x7FF;
        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;

        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"[ID:603]"<<"[ERROR]"<<"SEND DATA FAILED!";

        }
        else {
            //            qDebug()<<"[ID:603]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId
            //                   <<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen);
        }
    }
#endif
    CAN_OBJ sendbuf[7];
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为连续运动
    sendMsg.append(QString("00 8D 00 00 00 00"));//设置运动模式为连续运动模式（相当于速度模式，以5C1 3E 设定速度连续运行）
    sendMsg.append(QString("00 88 00 00 75 30"));// 设置加速度 30000
    sendMsg.append(QString("00 89 00 00 75 30"));//设置减速度 30000
    sendMsg.append(QString("00 8A 00 00 00 00"));//设置速度
    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能
    sendMsg.append(QString("00 83"));//电机使能
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
        sendbuf[i].ID=0X643&0x7FF;
        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(5);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"[ID:603]"<<"[ERROR]"<<"SEND DATA FAILED!";

        }
        else {
            //            qDebug()<<"[ID:643]"<<"SEND DATA SUCCESS"<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen);
        }
    }
#endif
}

void MachineEnableThreadPool::enableTT()
{
#if CANDEV_GC
    qDebug()<<"ENABLE TT!!!";
#if 0
    CAN_OBJ sendbuf[10];
    bool ok;
    QString id = ("601");
    QList<QString> sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//相对位置模式



    //        sendMsg.append(QString("23 7A 60 00 10 27 00 00"));//设置目标位置 一圈32768 除以减速比1/101

    sendMsg.append(QString("23 7A 60 00 00 00 00 00"));//设置转动角度


    sendMsg.append(QString("23 81 60 00 28 23 00 00"));//设置速度转速 rpm
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 6F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 7F 00 00 00"));

    QString RowStr;
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
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
        }
        else {

        }
    }
#endif
    CAN_OBJ sendbuf[6];
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 60 60 00 03 00 00 00"));//03:设置速度模式
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));//80:清除报警异常
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));//06:伺服准备
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));//07:伺服等待使能
    sendMsg.append(QString("2B 40 60 00 0f 00 00 00"));//0F:伺服使能
    //    sendMsg.append(QString("23 FF 60 00 00 00 00 00"));//初始化速度设置为0

    QString RowStr;
    for(int i=0;i<sendMsg.size();i++){
        sendbuf[i].DataLen=8 ;
        sendbuf[i].ExternFlag=0 ;
        sendbuf[i].RemoteFlag=0;
        sendbuf[i].ID=0x601&0x7ff;
        sendbuf[i].SendType=0;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(5);
        if(flag<1)  //发送不正常
        {
        }
        else {
        }
    }
#endif
}

void MachineEnableThreadPool::enableRmd141()
{
#if CANDEV_GC


#endif
}

void MachineEnableThreadPool::enableRmd145()
{
#if CANDEV_GC

    qDebug()<<"TEST ENABLE LX!!!";
    CAN_OBJ sendbuf[9];
    //    bool ok;
    //    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 4E 00 00 00 03"));//设置控制模式为位置控制
    sendMsg.append(QString("00 8D 00 00 00 01"));//设置运动模式为目标绝对位置模式
    sendMsg.append(QString("00 88 00 00 27 10"));//设置加速度为 10000 count/s²
    sendMsg.append(QString("00 89 00 00 27 10"));//设置减速度为 10000 count/s²
    sendMsg.append(QString("00 8A 00 00 27 10"));//设置目标速度为 10000 count/s
    sendMsg.append(QString("01 00 00 00 00 01"));//电机使能
    sendMsg.append(QString("00 87 00 00 00 00"));//设置相对位置为 0 count
    /***
     * 设置目标绝对位置 262144count,运动方向取决于目标位置相对当前位置是递增(向前运动)还是递减（向后运动）
     * （注：eRobxx-xxxI-BS 为单圈编码器型号，适用 于 运 动 位 置 范 围 0~360° ，
     * 对应编码器值范围0~524287count，实际位置可超出一圈，但掉电重启后多圈值不保存）
     * */
    //450953 限位
    sendMsg.append(QString("00 86 00 06 E1 89"));//262144count 相当于180度=262144*（360/524287） 目标位置 89 E1 06 00
    sendMsg.append(QString("00 83"));//开始运动
    for(int i=0;i<9;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
        sendbuf[i].ID=0x643&0x7FF;
        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;

        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(5);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"[ID:603]"<<"[ERROR]"<<"SEND DATA FAILED!";

        }
        else {
            qDebug()<<"[ID:603]"<<"SEND DATA SUCCESS"<<"[CAN:]"<<_CanId
                   <<publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen);
        }
    }
#endif
}
void MachineEnableThreadPool::disenableLX()
{
#if CANDEV_GC
    CAN_OBJ sendbuf[2];
    bool ok;
    QString id = "643";
    QStringList sendMsg;
    sendMsg.append(QString("00 84"));//停止运动
    sendMsg.append(QString("01 00 00 00 00 00"));//停止使能

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

        flag=Transmit(3,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
        _sleep(5);
        if(flag<1)  //发送不正常
        {
            qDebug()<<"[ID:603]"<<"[ERROR]"<<"DISENABLE FAILED!";

        }
        else {

        }
    }
#endif
}
void MachineEnableThreadPool::disenableTT()
{
#if CANDEV_GC
    CAN_OBJ sendbuf;
    bool ok;
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2B 40 60 00 02 00 00 00"));
    QString RowStr;
    sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）
    sendbuf.DataLen = 8;
    sendbuf.ID=0x601&0x7ff;
    sendbuf.SendType=1;
    sendbuf.TimeFlag=0;
    sendbuf.TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg[0],sendbuf.Data,&sendbuf.DataLen);
    ULONG flag;
    flag=Transmit(3,0,0,&sendbuf,1); //调用动态链接库发送函数
    //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
    if(flag<1)  //发送不正常
    {
        qDebug()<<"[ID:601]"<<"[ERROR]"<<"DISENABLE FAILED!";
    }
    else {

    }
#endif
}
void MachineEnableThreadPool::disenableRmd141()
{

}
void MachineEnableThreadPool::disenableRmd145()
{

}
