#include "serialWorkThreadPool.h"
#include "ControlCAN.h"
#define TT 0
#define TIMEOUT 50
serialWorkThreadPool_MT_141::serialWorkThreadPool_MT_141(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_MT_141::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_MT_141::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_MT_141::slotWork()
{
}
void serialWorkThreadPool_MT_141::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_MT_141::run()
{
    while (_isStart) {

        //        VCI_CAN_OBJ sendbuf[3];
        //        bool ok;
        QString id = "141";
        QString sendMsg=QString("9C 00 00 00 00 00 00 00");//读取电机状态2
        //        sendMsg.clear();
        //        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
        //        sendMsg.append(QString("33 00 00 00 00 00 00 00"));//读取加速度
        //        sendMsg.append(QString("90 00 00 00 00 00 00 00"));//读取编码器
        //        sendMsg.append(QString("92 00 00 00 00 00 00 00"));//读取多圈角度命令
        //        sendMsg.append(QString("94 00 00 00 00 00 00 00"));//读取单圈角度命令
        //        sendMsg.append(QString("9A 00 00 00 00 00 00 00"));//读取电机状态1和错误标志命令

        //        sendMsg.append(QString("9C 00 00 00 00 00 00 00"));//读取电机状态2
        publicClass::getInstance()->sendCanBuf(id,sendMsg,0);
        _sleep(TIMEOUT);
    }

}
serialWorkThreadPool_MT_142::serialWorkThreadPool_MT_142(int id,int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_MT_142::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_MT_142::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_MT_142::slotWork()
{

}
void serialWorkThreadPool_MT_142::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_MT_142::run()
{
    while (_isStart) {
        QString id = "142";
        QStringList sendMsg;
        sendMsg.clear();
        //        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
        //        sendMsg.append(QString("33 00 00 00 00 00 00 00"));//读取加速度
        //        sendMsg.append(QString("90 00 00 00 00 00 00 00"));//读取编码器
        //        sendMsg.append(QString("92 00 00 00 00 00 00 00"));//读取多圈角度命令
        //        sendMsg.append(QString("94 00 00 00 00 00 00 00"));//读取单圈角度命令
        //        sendMsg.append(QString("9A 00 00 00 00 00 00 00"));//读取电机状态1和错误标志命令

        sendMsg.append(QString("9C 00 00 00 00 00 00 00"));//读取电机状态2
        //        sendMsg.append(QString("9D 00 00 00 00 00 00 00"));//读取电机状态3

        publicClass::getInstance()->sendCanBuf(id,sendMsg.at(0),1);
         _sleep(TIMEOUT);
    }
}

serialWorkThreadPool_MT_143::serialWorkThreadPool_MT_143(int id,int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_MT_143::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_MT_143::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_MT_143::slotWork()
{
}
void serialWorkThreadPool_MT_143::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_MT_143::run()
{
    while (_isStart) {
        QString id = "143";
        QStringList sendMsg;
        sendMsg.clear();
        //        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
        //        sendMsg.append(QString("33 00 00 00 00 00 00 00"));//读取加速度
        //        sendMsg.append(QString("90 00 00 00 00 00 00 00"));//读取编码器
        //        sendMsg.append(QString("92 00 00 00 00 00 00 00"));//读取多圈角度命令
        //        sendMsg.append(QString("94 00 00 00 00 00 00 00"));//读取单圈角度命令
        //        sendMsg.append(QString("9A 00 00 00 00 00 00 00"));//读取电机状态1和错误标志命令

        sendMsg.append(QString("9C 00 00 00 00 00 00 00"));//读取电机状态2
        //        sendMsg.append(QString("9D 00 00 00 00 00 00 00"));//读取电机状态3

        publicClass::getInstance()->sendCanBuf(id,sendMsg.at(0),1);
         _sleep(TIMEOUT);
    }
}

serialWorkThreadPool_MT_145::serialWorkThreadPool_MT_145(int id,int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_MT_145::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_MT_145::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_MT_145::slotWork()
{
}
void serialWorkThreadPool_MT_145::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_MT_145::run()
{
    while (_isStart) {
        QString id = "145";
        QStringList sendMsg;
        sendMsg.clear();
        //        sendMsg.append(QString("30 00 00 00 00 00 00 00"));//读取pid
        //        sendMsg.append(QString("33 00 00 00 00 00 00 00"));//读取加速度
        //        sendMsg.append(QString("90 00 00 00 00 00 00 00"));//读取编码器
        //        sendMsg.append(QString("92 00 00 00 00 00 00 00"));//读取多圈角度命令
        //        sendMsg.append(QString("94 00 00 00 00 00 00 00"));//读取单圈角度命令
        //        sendMsg.append(QString("9A 00 00 00 00 00 00 00"));//读取电机状态1和错误标志命令

        sendMsg.append(QString("9C 00 00 00 00 00 00 00"));//读取电机状态2
        //        sendMsg.append(QString("9D 00 00 00 00 00 00 00"));//读取电机状态3

        publicClass::getInstance()->sendCanBuf(id,sendMsg.at(0),0);
         _sleep(TIMEOUT);
    }
}

serialWorkThreadPool_LX_603::serialWorkThreadPool_LX_603(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_LX_603::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_LX_603::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_LX_603::slotWork()
{
}
void serialWorkThreadPool_LX_603::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_LX_603::run()
{
    while (_isStart) {
        QString id = "603";
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
        sendMsg.append(QString("40 69 60 00 00 00 00 00"));//速度传感器实际值
        //        sendMsg.append(QString("40 78 60 00 00 00 00 00"));//电机实际电流
        //        sendMsg.append(QString("40 79 60 00 00 00 00 00"));//直流链路电路电压
        //        sendMsg.append(QString("40 7c 60 00 00 00 00 00"));//原点偏移
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
        for(int i = 0;i<sendMsg.size();i++){
            publicClass::getInstance()->sendCanBuf(id,sendMsg.at(i),0);

        }
 _sleep(TIMEOUT);
    }
}


serialWorkThreadPool_YK_602::serialWorkThreadPool_YK_602(int id,const int CanId):
    _id(id),_CanId(CanId)
{

}
Q_INVOKABLE void serialWorkThreadPool_YK_602::startWork()
{
    _isStart = true;
    QString id = "602";
    QStringList sendMsgList ;//="10 10";//发送数据
    //    sendMsgList.push_back("2B 40 60 00 00 00 00 00");
    sendMsgList.push_back("2B 40 60 00 00 00 00 00");
    sendMsgList.push_back("2B 40 60 00 06 00 00 00");
    sendMsgList.push_back("2B 40 60 00 07 00 00 00");
    //    sendMsgList.push_back("2B 40 60 00 0F 00 00 00");
    sendMsgList.push_back(QString("2F 60 60 00 01 00 00 00"));
    for(int i = 0;i<sendMsgList.size();i++){
        publicClass::getInstance()->sendCanBuf(id,sendMsgList.at(i),1);
         _sleep(TIMEOUT);
    }

}
Q_INVOKABLE void serialWorkThreadPool_YK_602::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_YK_602::slotWork()
{
}
void serialWorkThreadPool_YK_602::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_YK_602::run()
{
    while (_isStart) {
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
        for(int i = 0;i<sendMsg.size();i++){
            publicClass::getInstance()->sendCanBuf(id,sendMsg.at(i),1);
        }
         _sleep(TIMEOUT);

    }
}

serialWorkThreadPool_XT_01::serialWorkThreadPool_XT_01(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_XT_01::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_XT_01::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_XT_01::slotWork()
{

}
void serialWorkThreadPool_XT_01::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_XT_01::run()
{
    while (_isStart) {

        VCI_CAN_OBJ sendbuf[9];
        bool ok;

        QString id = "01";
        QStringList sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("01 00"));//读取伺服状态(0:关闭/1:打开)
        //        sendMsg.append(QString("01 01"));//读取电机编码器(1)单圈绝对位置/
        //        sendMsg.append(QString("01 02"));//读取电机编码器(1)圈数(断电清零)
        //        sendMsg.append(QString("01 03"));//读取电机编码器(1)累积位置(断电清零)
        sendMsg.append(QString("01 04"));//读取当前转速(转/分钟)
        //        sendMsg.append(QString("01 05"));//读取 Kp1 比例系数(刚性)
        //        sendMsg.append(QString("01 06"));//读取 Ki1 积分系数(定位)
        //        sendMsg.append(QString("01 07"));//读取 Kd1 微分系数(阻尼)
        //        sendMsg.append(QString("01 08"));//读取电机温度
        //        sendMsg.append(QString("01 09"));//读取故障代码
        //        sendMsg.append(QString("01 0A"));//读取电机 ID 号
        sendMsg.append(QString("01 11"));//读取输出轴编码器(2)单圈绝对位置
        //        sendMsg.append(QString("01 28"));//读取驱动电机电流(单位:毫安)
        //        sendMsg.append(QString("01 29"));//读取电机运行状态
        //        sendMsg.append(QString("01 2b"));//读取加速度时间(单位:ms)
        //        sendMsg.append(QString("01 2c"));//读取减速度时间(单位:ms)

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

            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(TIMEOUT);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");
                qDebug()<<"7777777777777777777777777777777777777777777"<<"01"<<"error";

            }
            else {

            }
        }
    }

}

serialWorkThreadPool_XT_02::serialWorkThreadPool_XT_02(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_XT_02::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_XT_02::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_XT_02::slotWork()
{

}
void serialWorkThreadPool_XT_02::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_XT_02::run()
{
    while (_isStart) {

        VCI_CAN_OBJ sendbuf[11];
        bool ok;

        QString id = "02";
        QStringList sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("02 00"));//读取伺服状态(0:关闭/1:打开)
        //        sendMsg.append(QString("02 01"));//读取电机编码器(1)单圈绝对位置
        //        sendMsg.append(QString("02 02"));//读取电机编码器(1)圈数(断电清零)
        //        sendMsg.append(QString("02 03"));//读取电机编码器(1)累积位置(断电清零)
        sendMsg.append(QString("02 04"));//读取当前转速(转/分钟)
        //        sendMsg.append(QString("02 05"));//读取 Kp1 比例系数(刚性)
        //        sendMsg.append(QString("02 06"));//读取 Ki1 积分系数(定位)
        //        sendMsg.append(QString("02 07"));//读取 Kd1 微分系数(阻尼)
        //        sendMsg.append(QString("02 08"));//读取电机温度
        //        sendMsg.append(QString("02 09"));//读取故障代码
        //        sendMsg.append(QString("02 0A"));//读取电机 ID 号
        sendMsg.append(QString("02 11"));//读取输出轴编码器(2)单圈绝对位置
        //        sendMsg.append(QString("02 28"));//读取驱动电机电流(单位:毫安)
        //        sendMsg.append(QString("02 29"));//读取电机运行状态
        //        sendMsg.append(QString("02 2b"));//读取加速度时间(单位:ms)
        //        sendMsg.append(QString("02 2c"));//读取减速度时间(单位:ms)

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

            flag=VCI_Transmit(4,0,_CanId,&sendbuf[i],1); //调用动态链接库发送函数
            _sleep(TIMEOUT);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");
                qDebug()<<"88888888888888888888888888888888888888888"<<"02";

            }
            else {

            }
        }
    }

}

//编码器读取线程
serialWorkThreadPool_BMQ::serialWorkThreadPool_BMQ(QString &COM):_COM_port(COM)
{
    _sharememory.setKey(COM);
}
Q_INVOKABLE void serialWorkThreadPool_BMQ::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ::slotWork()
{

}
void serialWorkThreadPool_BMQ::slotWorkData(QByteArray data)
{

}
void serialWorkThreadPool_BMQ::run()
{
    while (_isStart) {
        slotReadShareMemory();
        qDebug()<<"9999999999999999999999999999999999999"<<"BMQ";
        Sleep(TIMEOUT);
    }
}
void serialWorkThreadPool_BMQ::DataArrived()
{
    //    std::lock_guard<std::mutex> lgd(_mutex);
    //    qDebug() << __FUNCTION__ << "xxxxxxxxxxxxxxxxxxxxxxxx:" << P_QSerialPort->readAll();

}
void serialWorkThreadPool_BMQ::slotReadShareMemory()
{
    if(!_sharememory.attach())
    {
        qDebug() << QString("编码器[%1]内存读取错误").arg(_COM_port);
    }
    QBuffer buffer;
    _sharememory.lock();
    buffer.setData((char*)_sharememory.constData(),_sharememory.size());
    buffer.open(QBuffer::ReadWrite);
    buffer.readAll();
    _sharememory.unlock();
    _sharememory.detach();
    //    qDebug() << buffer.data().data()<<"xxxxxxxxxxxxxxxxxxxxxxxxx"<<_COM_port;
    emit signalComData(QString(buffer.data().data()),_COM_port);
}

serialWorkThreadPool_TT_601::serialWorkThreadPool_TT_601(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void serialWorkThreadPool_TT_601::startWork()
{
    _isStart = true;
    QString id = "01";
    QString sendMsg="10 10";//发送数据
    publicClass::getInstance()->sendCanBuf(id,sendMsg,0);

}
Q_INVOKABLE void serialWorkThreadPool_TT_601::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_TT_601::slotWork()
{
}
void serialWorkThreadPool_TT_601::slotWorkData(QByteArray data)
{
}
void serialWorkThreadPool_TT_601::run()
{
//    while (_isStart) {
//        QString id = "601";
//        QStringList sendMsg;
//        sendMsg.clear();
//        //        sendMsg.append(QString("43 0D 30 00 00 00 00 00"));//线圈温度
//        //        sendMsg.append(QString("43 0E 30 00 00 00 00 00"));//模块温度
//        //        sendMsg.append(QString("43 05 30 00 00 00 00 00"));//电机电流
//        //        sendMsg.append(QString("43 09 30 00 00 00 00 00"));//母线电压
//        //        sendMsg.append(QString("40 0A 30 00 00 00 00 00"));//告警码
//        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//转速

//        //        sendMsg.append(QString("43 64 60 00 00 00 00 00"));//编码器绝对位置
//        //        sendMsg.append(QString("43 0F 30 00 00 00 00 00"));//第二位置编码器
//        //        sendMsg.append(QString("43 63 60 00 00 00 00 00"));//当前电机位置
//        //        sendMsg.append(QString("43 7A 60 00 00 00 00 00"));//目标位置
//        //        sendMsg.append(QString("43 08 30 00 00 00 00 00"));//第一位置编码器
//        //        sendMsg.append(QString("43 00 30 00 00 00 00 00"));//告警码

//        for(int i=0;i<sendMsg.size();i++){
//            publicClass::getInstance()->sendCanBuf(id,sendMsg[i],0);
//        }
//         _sleep(TIMEOUT);
//    }


}



//编码器读取线程
serialWorkThreadPool_BMQ_A2::serialWorkThreadPool_BMQ_A2(QString &COM):_COM_port(COM)
{
    _minValueDuo_A2 = publicClass::getInstance()->readValueIni("A2-min/duoquan").toLong();
    _minValueDan_A2 = publicClass::getInstance()->readValueIni("A2-min/danquan").toLong();
    _maxValueDuo_A2 = publicClass::getInstance()->readValueIni("A2-max/duoquan").toLong();
    _maxValueDan_A2 = publicClass::getInstance()->readValueIni("A2-max/danquan").toLong();

}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A2::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A2::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A2::slotWork()
{

}
void serialWorkThreadPool_BMQ_A2::slotWorkData(QString COM,int32_t duo,int32_t dan)
{

    if((duo-_minValueDuo_A2)*524287+dan<=_minValueDan_A2){
        _isNeedStopMachine_right = true;
    }
    else if ((duo-_maxValueDuo_A2)*524287+dan>=_maxValueDan_A2) {
        _isNeedStopMachine_left = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
}
void serialWorkThreadPool_BMQ_A2::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_right&&_rpm>0){

            VCI_CAN_OBJ sendbuf[1];
            QString id = "141";
            QStringList sendMsg;
            bool ok;
            QString datastr = "81 00 00 00 00 00 00 00";
            sendMsg.append(datastr.simplified());
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
                //                        flag =VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
                if(flag<1)  //发送不正常
                {
                    //             emit signalError("error");
                    qDebug()<<"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"<<"A2";

                }
                else {
                    qDebug()<<"[ID:]"<<id<<"stop machine...";
                }
            }

        }
        else if (_isNeedStopMachine_left&&_rpm<0) {

            VCI_CAN_OBJ sendbuf[1];
            QString id = "141";
            QStringList sendMsg;
            bool ok;
            QString datastr = "81 00 00 00 00 00 00 00";
            sendMsg.append(datastr.simplified());
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
                //                flag =VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
                if(flag<1)  //发送不正常
                {
                    //             emit signalError("error");
                    qDebug()<<"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"<<"A2";

                }
                else {
                    qDebug()<<"[ID:]"<<id<<"stop machine...";
                }
            }
        }
        _sleep(10);
    }

}

void serialWorkThreadPool_BMQ_A2::slotMachineData(int32_t &data)
{
    _rpm = data;
}

//编码器读取线程
serialWorkThreadPool_BMQ_A3::serialWorkThreadPool_BMQ_A3(QString &COM):_COM_port(COM)
{
    _minValueDuo_A3 = publicClass::getInstance()->readValueIni("A3-min/duoquan").toLong();
    _minValueDan_A3 = publicClass::getInstance()->readValueIni("A3-min/danquan").toLong();
    _maxValueDuo_A3 = publicClass::getInstance()->readValueIni("A3-max/duoquan").toLong();
    _maxValueDan_A3 = publicClass::getInstance()->readValueIni("A3-max/danquan").toLong();
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A3::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A3::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A3::slotWork()
{

}
void serialWorkThreadPool_BMQ_A3::slotWorkData(QString COM,int32_t duo,int32_t dan)
{
    if((duo-_minValueDuo_A3)*524287+dan<=_minValueDan_A3){
        _isNeedStopMachine_right = true;
    }
    else if ((duo-_maxValueDuo_A3)*524287+dan>=_maxValueDan_A3) {
        _isNeedStopMachine_left = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
}
void serialWorkThreadPool_BMQ_A3::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_left&&_rpm<0){
            VCI_CAN_OBJ sendbuf[1];
            bool ok;
            QString id = ("601");
            QList<QString>   sendMsg;
            sendMsg.clear();
            sendMsg.append(QString("2B 40 60 00 02 00 00 00"));
            QString RowStr;
            sendbuf->ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf->RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf->ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf->ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf->SendType=1;
            sendbuf->TimeFlag=0;
            sendbuf->TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[0],sendbuf->Data,&sendbuf->DataLen);
            ULONG flag;
            //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
            //           <<"sendMsg"<<sendMsg;
            //            flag=VCI_Transmit(4,0,0,sendbuf,1); //调用动态链接库发送函数
            //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            if(flag<1)  //发送不正常
            {
                qDebug()<<"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"<<"A3";
            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<"[right]"<<_rpm;;
            }

        }
        else if (_isNeedStopMachine_right&&_rpm>0) {
            VCI_CAN_OBJ sendbuf[1];
            bool ok;
            QString id = ("601");
            QList<QString>   sendMsg;
            sendMsg.clear();
            sendMsg.append(QString("2B 40 60 00 02 00 00 00"));
            QString RowStr;
            sendbuf->ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf->RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf->ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf->ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf->SendType=1;
            sendbuf->TimeFlag=0;
            sendbuf->TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[0],sendbuf->Data,&sendbuf->DataLen);
            ULONG flag;
            //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
            //           <<"sendMsg"<<sendMsg;
            //            flag=VCI_Transmit(4,0,0,sendbuf,1); //调用动态链接库发送函数
            //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            if(flag<1)  //发送不正常
            {
                qDebug()<<"CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"<<"A3";
            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<"[right]"<<_rpm;
            }
        }
        _sleep(8);
    }
}

void serialWorkThreadPool_BMQ_A3::slotMachineData(int32_t &data)
{
    _rpm = data;
}

//编码器读取线程
serialWorkThreadPool_BMQ_A4::serialWorkThreadPool_BMQ_A4(QString &COM):_COM_port(COM)
{
    //    _minValueDuo_A4 = publicClass::getInstance()->readValueIni("A4-min/duoquan").toLong();
    _minValueDan_A4 = publicClass::getInstance()->readValueIni("A4-min/danquan").toLong();
    //    _maxValueDuo_A4 = publicClass::getInstance()->readValueIni("A4-max/duoquan").toLong();
    _maxValueDan_A4 = publicClass::getInstance()->readValueIni("A4-max/danquan").toLong();
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A4::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A4::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A4::slotWork()
{

}
void serialWorkThreadPool_BMQ_A4::slotWorkData(QString COM,int32_t duo,int32_t dan)
{
    if(dan<=_minValueDan_A4){
        _isNeedStopMachine_right = true;
    }
    else if (dan>=_maxValueDan_A4) {
        _isNeedStopMachine_left = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
}
void serialWorkThreadPool_BMQ_A4::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_right&&_rpm<0){

            VCI_CAN_OBJ sendbuf[1];
            QString id = "145";
            QStringList sendMsg;
            bool ok;
            QString datastr = "81 00 00 00 00 00 00 00";
            sendMsg.append(datastr.simplified());
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
                //                flag =VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
                if(flag<1)  //发送不正常
                {
                    //             emit signalError("error");
                    qDebug()<<"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<"A4";

                }
                else {
                    qDebug()<<"[ID:]"<<id<<"stop machine...";
                }
            }

        }
        else if (_isNeedStopMachine_left&&_rpm>0) {

            VCI_CAN_OBJ sendbuf[1];
            QString id = "145";
            QStringList sendMsg;
            bool ok;
            QString datastr = "81 00 00 00 00 00 00 00";
            sendMsg.append(datastr.simplified());
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
                //                flag =VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
                if(flag<1)  //发送不正常
                {
                    //             emit signalError("error");
                    qDebug()<<"DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<"A4";

                }
                else {
                    qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
                }
            }
        }
        _sleep(10);
    }
}

void serialWorkThreadPool_BMQ_A4::slotMachineData(int32_t &data)
{
    _rpm = data;
}

//编码器读取线程
serialWorkThreadPool_BMQ_A8::serialWorkThreadPool_BMQ_A8(QString &COM):_COM_port(COM)
{
    _minValueDuo_A8 = publicClass::getInstance()->readValueIni("A8-min/duoquan").toLong();
    _minValueDan_A8 = publicClass::getInstance()->readValueIni("A8-min/danquan").toLong();
    _maxValueDuo_A8 = publicClass::getInstance()->readValueIni("A8-max/duoquan").toLong();
    _maxValueDan_A8 = publicClass::getInstance()->readValueIni("A8-max/danquan").toLong();
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A8::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A8::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A8::slotWork()
{

}
void serialWorkThreadPool_BMQ_A8::slotWorkData(QString COM,int32_t duo,int32_t dan)
{
    if((duo-_minValueDuo_A8)*524287+dan<=_minValueDan_A8-10000){
        _isNeedStopMachine_left = true;
    }
    else if ((duo-_maxValueDuo_A8)*524287+dan>=_maxValueDan_A8+10000) {
        _isNeedStopMachine_right = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
}
void serialWorkThreadPool_BMQ_A8::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_right&&_rpm<0){

            VCI_CAN_OBJ sendbuf;
            QString id = "143";
            QStringList sendMsg;
            bool ok;
            QString datastr = "81 00 00 00 00 00 00 00";

            //            QString datastr = "A2 00 00 00 A0 86 01 00";
            //            unsigned char s[4]={0,0,0,0} ;
            //            int32_t value = ui->lineEdit_5->text().toInt()*100;//(0.01dps/lsb) 1秒钟转0.01度  3000dps/lsb 表示 3000/360*60 rpm 转/min
            //            memmove(s,&value,4);

            //            datastr = datastr+ " "+ publicClass::getInstance()->Byte_16(s,4).simplified() ;

            //            sendMsg.append(datastr.simplified());

            //            sendMsg.append(datastr.simplified());
            //            for(int i=0;i<sendMsg.size();i++){
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf.ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf.SendType=1;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(datastr,sendbuf.Data,&sendbuf.DataLen);

            ULONG flag;
            //            flag =VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");
                qDebug()<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"A8";

            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
            }
        }

        //        }
        else if (_isNeedStopMachine_left&&_rpm>0) {

            VCI_CAN_OBJ sendbuf;
            QString id = "143";
            QStringList sendMsg;
            bool ok;
            QString datastr = "81 00 00 00 00 00 00 00";
            //                        QString datastr = "A2 00 00 00 60 79 FE FF";

            //            sendMsg.append(datastr.simplified());
            //            for(int i=0;i<sendMsg.size();i++){
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf.ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf.SendType=1;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(datastr,sendbuf.Data,&sendbuf.DataLen);

            ULONG flag;
            //            flag =VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");
                qDebug()<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<"A8";

            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine...";
            }
        }
        //        }
        _sleep(10);
    }

}

void serialWorkThreadPool_BMQ_A8::slotMachineData(int32_t &data)
{
    _rpm = data;
}


//编码器读取线程 零差云控
serialWorkThreadPool_BMQ_A1::serialWorkThreadPool_BMQ_A1(QString &COM):_COM_port(COM)
{
    //    _minValueDuo_A1 = publicClass::getInstance()->readValueIni("A8-min/duoquan").toLong();
    _minValueDan_A1 = publicClass::getInstance()->readValueIni("A1-min/danquan").toLong();
    //    _maxValueDuo_A1 = publicClass::getInstance()->readValueIni("A8-max/duoquan").toLong();
    _maxValueDan_A1 = publicClass::getInstance()->readValueIni("A1-max/danquan").toLong();
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A1::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A1::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_A1::slotWork()
{

}
void serialWorkThreadPool_BMQ_A1::slotWorkData(QString COM,int32_t duo,int32_t dan)
{
    if(dan<=_minValueDan_A1){
        _isNeedStopMachine_right = true;
    }
    else if (dan>=_maxValueDan_A1) {
        _isNeedStopMachine_left = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
}
void serialWorkThreadPool_BMQ_A1::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_right&&_rpm<-50){

            VCI_CAN_OBJ sendbuf[2];
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

                //                flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
                //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
                _sleep(TIMEOUT);
                if(flag<1)  //发送不正常
                {
                    qDebug()<<"error"<<"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"<<"A1";

                }
                else {
                    qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
                }
            }

        }
        else if (_isNeedStopMachine_left&&_rpm>50) {

            VCI_CAN_OBJ sendbuf[2];
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

                //                flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
                //        qDebug()<< publicClass::getInstance()->Byte_16(sendbuf[i].Data,sendbuf[i].DataLen)<<"OOOOOOOOOOOOOOOOOOOOOOOOOO";
                _sleep(50);
                if(flag<1)  //发送不正常
                {
                    qDebug()<<"error";

                }
                else {
                    qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
                }
            }
        }
        _sleep(10);
    }

}

void serialWorkThreadPool_BMQ_A1::slotMachineData(int32_t &data)
{
    _rpm = data;


}


/**********************************鑫拓限位***********************/
//编码器读取线程 01
serialWorkThreadPool_BMQ_XT_1::serialWorkThreadPool_BMQ_XT_1(QString &COM):_COM_port(COM)
{

    _minValueDan_BMQ_XT_1 = publicClass::getInstance()->readValueIni("XT01-min/danquan").toLong();
    _maxValueDan_BMQ_XT_1 = publicClass::getInstance()->readValueIni("XT01-max/danquan").toLong();
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_XT_1::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_XT_1::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_XT_1::slotWork()
{

}
void serialWorkThreadPool_BMQ_XT_1::slotWorkData(QString COM,int32_t duo,int32_t dan)
{

    if(dan<=_minValueDan_BMQ_XT_1){
        _isNeedStopMachine_left = true;
    }
    else if (dan>=_maxValueDan_BMQ_XT_1) {
        _isNeedStopMachine_right = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
    //    qDebug()<<_minValueDan_BMQ_XT_1 <<_maxValueDan_BMQ_XT_1<<dan<<"CCCCCCCCCCCCCCC";
}
void serialWorkThreadPool_BMQ_XT_1::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_left&&_rpm<0){

            VCI_CAN_OBJ sendbuf;
            bool ok;
            QString id = "01";
            QString sendMsg="01 87 00 00 00 01";
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf.ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf.SendType=1;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
            ULONG flag;

            //            flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
            _sleep(TIMEOUT);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"error"<<"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"<<"XT1";

            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
            }
        }

        else if (_isNeedStopMachine_right&&_rpm>0) {


            VCI_CAN_OBJ sendbuf;
            bool ok;
            QString id = "01";
            QString sendMsg="01 87 00 00 00 01";
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf.ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf.SendType=1;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
            ULONG flag;

            //            flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
            _sleep(TIMEOUT);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"error"<<"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"<<"XT1";

            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
            }

        }
        _sleep(5);
    }
}

void serialWorkThreadPool_BMQ_XT_1::slotMachineData(int32_t &data)
{
    _rpm = data;
}



/**********************************鑫拓限位***********************/
//编码器读取线程 02
serialWorkThreadPool_BMQ_XT_2::serialWorkThreadPool_BMQ_XT_2(QString &COM):_COM_port(COM)
{
    _minValueDan_BMQ_XT_2 = publicClass::getInstance()->readValueIni("XT02-min/danquan").toLong();
    _maxValueDan_BMQ_XT_2 = publicClass::getInstance()->readValueIni("XT02-max/danquan").toLong();
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_XT_2::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_XT_2::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_BMQ_XT_2::slotWork()
{

}
void serialWorkThreadPool_BMQ_XT_2::slotWorkData(QString COM,int32_t duo,int32_t dan)
{

    if(dan<=_minValueDan_BMQ_XT_2){
        _isNeedStopMachine_left = true;
    }
    else if (dan>=_maxValueDan_BMQ_XT_2) {
        _isNeedStopMachine_right = true;
    }
    else {
        _isNeedStopMachine_right = false;
        _isNeedStopMachine_left = false;
    }
}
void serialWorkThreadPool_BMQ_XT_2::run()
{
    while (_isStart) {

        if(_isNeedStopMachine_left&&_rpm<0){

            VCI_CAN_OBJ sendbuf;
            bool ok;
            QString id = "02";
            QString sendMsg="02 87 00 00 00 01";
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf.ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf.SendType=1;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
            ULONG flag;

            //            flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
            _sleep(TIMEOUT);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<"XT2"<<"error";

            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
            }
        }

        else if (_isNeedStopMachine_right&&_rpm>0) {


            VCI_CAN_OBJ sendbuf;
            bool ok;
            QString id = "02";
            QString sendMsg="02 87 00 00 00 01";
            sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf.ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf.SendType=1;
            sendbuf.TimeFlag=0;
            sendbuf.TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf.Data,&sendbuf.DataLen);
            ULONG flag;

            //            flag=VCI_Transmit(4,0,1,&sendbuf,1); //调用动态链接库发送函数
            _sleep(TIMEOUT);
            if(flag<1)  //发送不正常
            {
                qDebug()<<"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH"<<"XT2"<<"error";


            }
            else {
                qDebug()<<"[ID:]"<<id<<"stop machine..."<<_rpm;
            }

        }
        _sleep(10);
    }

}

void serialWorkThreadPool_BMQ_XT_2::slotMachineData(int32_t &data)
{
    _rpm =data;
}
