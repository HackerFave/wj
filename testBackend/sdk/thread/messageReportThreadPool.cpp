#include "messageReportThreadPool.h"
#include "ControlCAN.h"
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
    }

}
messageReportThreadPool_MT_142::messageReportThreadPool_MT_142(int id,int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_MT_142::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_MT_142::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_MT_142::slotWork()
{

}
void messageReportThreadPool_MT_142::slotWorkData(QByteArray data)
{
}
void messageReportThreadPool_MT_142::run()
{
    while (_isStart) {
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "142";
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
    }
}

messageReportThreadPool_MT_143::messageReportThreadPool_MT_143(int id,int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_MT_143::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_MT_143::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_MT_143::slotWork()
{
}
void messageReportThreadPool_MT_143::slotWorkData(QByteArray data)
{
}
void messageReportThreadPool_MT_143::run()
{
    while (_isStart) {
        VCI_CAN_OBJ sendbuf[11];
        bool ok;
        QString id = "143";
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

    }
}

messageReportThreadPool_XT_01::messageReportThreadPool_XT_01(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_XT_01::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_XT_01::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_XT_01::slotWork()
{

}
void messageReportThreadPool_XT_01::slotWorkData(QByteArray data)
{

}
void messageReportThreadPool_XT_01::run()
{
    while (_isStart) {

        VCI_CAN_OBJ sendbuf[16];
        bool ok;
        QString id = "01";
        QStringList sendMsg;
        sendMsg.append(QString("01 00"));//读取伺服状态(0:关闭/1:打开)
        //        sendMsg.append(QString("01 01"));//读取电机编码器(1)单圈绝对位置
        //        sendMsg.append(QString("01 02"));//读取电机编码器(1)圈数(断电清零)
        //        sendMsg.append(QString("01 03"));//读取电机编码器(1)累积位置(断电清零)
        sendMsg.append(QString("01 04"));//读取当前转速(转/分钟)
        //        sendMsg.append(QString("01 05"));//读取 Kp1 比例系数(刚性)
        //        sendMsg.append(QString("01 06"));//读取 Ki1 积分系数(定位)
        //        sendMsg.append(QString("01 07"));//读取 Kd1 微分系数(阻尼)
        sendMsg.append(QString("01 08"));//读取电机温度
        sendMsg.append(QString("01 09"));//读取故障代码
        //        sendMsg.append(QString("01 0A"));//读取电机 ID 号
        sendMsg.append(QString("01 11"));//读取输出轴编码器(2)单圈绝对位置
        sendMsg.append(QString("01 28"));//读取驱动电机电流(单位:毫安)
        //        sendMsg.append(QString("01 29"));//读取电机运行状态
        //        sendMsg.append(QString("01 2b"));//读取加速度时间(单位:ms)
        //        sendMsg.append(QString("01 2c"));//读取减速度时间(单位:ms)

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
    }
}

messageReportThreadPool_XT_02::messageReportThreadPool_XT_02(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_XT_02::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_XT_02::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_XT_02::slotWork()
{

}
void messageReportThreadPool_XT_02::slotWorkData(QByteArray data)
{

}
void messageReportThreadPool_XT_02::run()
{
    while (_isStart) {

        VCI_CAN_OBJ sendbuf[16];
        bool ok;
        QString id = "02";
        QStringList sendMsg;
        sendMsg.append(QString("02 00"));//读取伺服状态(0:关闭/1:打开)
        //        sendMsg.append(QString("02 01"));//读取电机编码器(1)单圈绝对位置
        //        sendMsg.append(QString("02 02"));//读取电机编码器(1)圈数(断电清零)
        //        sendMsg.append(QString("02 03"));//读取电机编码器(1)累积位置(断电清零)
        sendMsg.append(QString("02 04"));//读取当前转速(转/分钟)
        //        sendMsg.append(QString("02 05"));//读取 Kp1 比例系数(刚性)
        //        sendMsg.append(QString("02 06"));//读取 Ki1 积分系数(定位)
        //        sendMsg.append(QString("02 07"));//读取 Kd1 微分系数(阻尼)
        sendMsg.append(QString("02 08"));//读取电机温度
        sendMsg.append(QString("02 09"));//读取故障代码
        //        sendMsg.append(QString("02 0A"));//读取电机 ID 号
        sendMsg.append(QString("02 11"));//读取输出轴编码器(2)单圈绝对位置
        sendMsg.append(QString("02 28"));//读取驱动电机电流(单位:毫安)
        //        sendMsg.append(QString("02 29"));//读取电机运行状态
        //        sendMsg.append(QString("02 2b"));//读取加速度时间(单位:ms)
        //        sendMsg.append(QString("02 2c"));//读取减速度时间(单位:ms)

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
        Sleep(8);
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
        qDebug() << "cann't attach sahrememory";
    }
    QBuffer buffer;
    _sharememory.lock();
    buffer.setData((char*)_sharememory.constData(),_sharememory.size());
    buffer.open(QBuffer::ReadWrite);
    buffer.readAll();
    _sharememory.unlock();
    _sharememory.detach();
    qDebug() << buffer.data().data();
    emit signalComData(QString(buffer.data().data()));
}

messageReportThreadPool_TT_602::messageReportThreadPool_TT_602(int id,const int CanId):
    _id(id),_CanId(CanId)
{
}
Q_INVOKABLE void messageReportThreadPool_TT_602::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void messageReportThreadPool_TT_602::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void messageReportThreadPool_TT_602::slotWork()
{
}
void messageReportThreadPool_TT_602::slotWorkData(QByteArray data)
{
}
void messageReportThreadPool_TT_602::run()
{
    while (_isStart) {

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
    }


}
