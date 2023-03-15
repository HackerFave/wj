#include "burglarAlarm485.h"
#include <QtDebug>
#include <QByteArray>
burglarAlarm485::burglarAlarm485(QObject *parent) : QObject(parent)
{
    QByteArray ba;
    ba.resize(3);
    ba[0] = 0x00;
    ba[1] = 0x01;
    ba[2] = 0x02;
    uint16_t wcrc = ModbusCRC16(ba);
    qDebug()<<"CRC码：低字节:"<<uint8_t(wcrc)<<" 高字节:"<<uint8_t(wcrc>>8);

    modbusDevice = new QModbusRtuSerialMaster();
    pollTimer = new QTimer;
}
uint16_t burglarAlarm485::usMBCRC16(uint8_t *crcdata, uint32_t sizeofarray)
{
    unsigned int j = 0, k = 0;
    unsigned int reg_crc =0xFFFF;
    uint16_t outCRC;
    for(j = 0; j < sizeofarray; j++)
    {
        reg_crc ^= crcdata[j];
        for(k = 0; k < 8; k++)
        {
            if(reg_crc & 0x01)
                reg_crc = (reg_crc >> 1) ^ 0xA001;
            else
                reg_crc = reg_crc >> 1;
        }
    }
    outCRC = ((reg_crc << 8) & 0xFF00) | ((reg_crc >> 8) & 0x00FF);
    return outCRC;
}

/*06 功能码把设置的单个数值写入指定的寄存器 /****************
*******************************************
* 名 称： Alarm_Command_06H_Change_Register(UartEvent_TypeDef *Obj, uint16
Register_Address, uint16 Change_Data)
* 功 能： 把设置的单个数值写入指定的寄存器
* 入口参数： 写入地址； 寄存器地址； 修改的数值
* 出口参数：
*说 明：
* 调用方法： Alarm_Command_06H_Change_Register(&UART2,RegAdderss, RegData06H );
**********************************************************/
void burglarAlarm485::Alarm_Command_06H_Change_Register(UartEvent_TypeDef *Obj, uint16_t Register_Address,
                                                        uint16_t Change_Data)
{
    unsigned int usCRC16;
    unsigned char i;
    Obj->usSndBufPos = 0;
    //写从机（报警器）地址
    //下标清零
    Obj->ucSndBuf[Obj->usSndBufPos++] = ALARM_ADDRESS;//1
    //写命令
    Obj->ucSndBuf[Obj->usSndBufPos++] = 0x06;//2
    //写地址数据
    Obj->ucSndBuf[Obj->usSndBufPos++] = Register_Address >> 8;//3 //寄存器高位//
    Obj->ucSndBuf[Obj->usSndBufPos++] = Register_Address;//4   //  寄存器低位

    //修改数据
    Obj->ucSndBuf[Obj->usSndBufPos++] = Change_Data >> 8;//修改数据高位//
    Obj->ucSndBuf[Obj->usSndBufPos++] = Change_Data;//修改数据低位


    //CRC 校验
    usCRC16 = usMBCRC16(Obj->ucSndBuf,Obj->usSndBufPos);
    Obj->ucSndBuf[Obj->usSndBufPos++] = usCRC16 >> 8;  //CRC 数据低位
    Obj->ucSndBuf[Obj->usSndBufPos++] = usCRC16;   //CRC 数据高位


    //    //**********开始发送数据串**********//
    //    ALARM_RS485_Switch_TxState( ); //流控 IO,RS485 设置为发送
    //    for( i = 0; i < Obj->usSndBufPos; i++ ) //发送 485 指令
    //    {
    //        Uart2_SendByte( Obj->ucSndBuf[i] );
    //    }
    //    ALARM_RS485_Switch_RxState( ); //流控 IO,RS485 设置为接收
    //    //**********数据串发送结束**********//
}


//CRC16计算函数
uint16_t burglarAlarm485::ModbusCRC16(QByteArray senddata)
{
    int len=senddata.size();
    uint16_t wcrc=0XFFFF;//预置16位crc寄存器，初值全部为1
    uint8_t temp;//定义中间变量
    int i=0,j=0; //定义计数
    for(i=0;i<len;i++)//循环计算每个数据
    {
        temp=senddata.at(i);
        wcrc^=temp;
        for(j=0;j<8;j++){
            //判断右移出的是不是1，如果是1则与多项式进行异或。
            if(wcrc&0X0001){
                wcrc>>=1;//先将数据右移一位
                wcrc^=0XA001;//与上面的多项式进行异或
            }
            else//如果不是1，则直接移出
                wcrc>>=1;//直接移出
        }
    }
    temp=wcrc;//crc的值
    return wcrc;
}


//搜索串口
void burglarAlarm485::SearchSerialPorts()
{
    //    ui->comboBoxPort->clear();
    _quePort.clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        //        ui->comboBoxPort->addItem(info.portName());
        _quePort.push_back(info.portName());
    }

}

//写数据请求
void burglarAlarm485::WriteRequest(QModbusDataUnit::RegisterType type,QList<quint16> values,int startAddress,int serverAddress)
{
    if (!modbusDevice)
    {
        //        QMessageBox::information(NULL,  "Title",  QStringLiteral("尚未连接从站设备"));
        qWarning()<<QStringLiteral("尚未连接从站设备");
        return;
    }

    //    int startAddress = ui->spinBoxStartWrite->value();//起始地址
    Q_ASSERT(startAddress >= 0 && startAddress < 10);

    QModbusDataUnit writeUnit = QModbusDataUnit(type,startAddress, values.size());
    for(int i=0; i<values.size(); i++)
    {
        writeUnit.setValue(i, values.at(i));
    }

    //serverEdit 发生给slave的ID
    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,/*ui->spinBoxStation->value()*/serverAddress))//从站地址
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::ProtocolError) {
                    qDebug() << QString("Write response error: %1 (Mobus exception: 0x%2)")
                                .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
                } else if (reply->error() != QModbusDevice::NoError) {
                    qDebug() << QString("Write response error: %1 (code: 0x%2)").
                                arg(reply->errorString()).arg(reply->error(), -1, 16);
                }
                reply->deleteLater();
            });
        }
        else
        {
            reply->deleteLater();
        }
    }
    else
    {
        qFatal(("Write error:")+ modbusDevice->errorString().toLocal8Bit());
    }
}
void burglarAlarm485::slotReadRequest()
{
    if (!modbusDevice)
    {
        //        QMessageBox::information(NULL,  "Title", QStringLiteral("尚未连接从站设备"));
        qWarning()<<QStringLiteral("尚未连接从站设备");
        return;
    }
    //    int startAddress = ui->spinBoxStartRead->value();
    //    Q_ASSERT(startAddress >= 0 && startAddress < 10);

    // do not go beyond 10 entries
    quint16 numberOfEntries = qMin(quint16(/*ui->spinBoxNumberRead->value()*/2), quint16(10 - 1));
    QModbusDataUnit readUnit=QModbusDataUnit(QModbusDataUnit::Coils, 1, numberOfEntries);

    //    statusBar()->clearMessage();

    if (auto *reply = modbusDevice->sendReadRequest(readUnit, /*ui->spinBoxStation->value()*/1))
    {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &burglarAlarm485::slotReadSerialData);
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        //        statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
        qFatal(QString("Read error: %1").arg(modbusDevice->errorString()).toLocal8Bit());

    }
}
//读数据请求
void burglarAlarm485::slotReadRequest(QModbusDataUnit::RegisterType type,int startAddress/**起始地址*****/,int readNum)
{
    if (!modbusDevice)
    {
        //        QMessageBox::information(NULL,  "Title", QStringLiteral("尚未连接从站设备"));
        qWarning()<<QStringLiteral("尚未连接从站设备");
        return;
    }
    //    int startAddress = ui->spinBoxStartRead->value();
    Q_ASSERT(startAddress >= 0 && startAddress < 10);

    // do not go beyond 10 entries
    quint16 numberOfEntries = qMin(quint16(/*ui->spinBoxNumberRead->value()*/readNum), quint16(10 - startAddress));
    QModbusDataUnit readUnit=QModbusDataUnit(type, startAddress, numberOfEntries);

    //    statusBar()->clearMessage();

    if (auto *reply = modbusDevice->sendReadRequest(readUnit, /*ui->spinBoxStation->value()*/1))
    {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &burglarAlarm485::slotReadSerialData);
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        //        statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
        qFatal(QString("Read error: %1").arg(modbusDevice->errorString()).toLocal8Bit());

    }

}

//从串口接收数据
void burglarAlarm485::slotReadSerialData()
{
    auto reply = qobject_cast<QModbusReply*>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();

        for (int i = 0, total = int(unit.valueCount()); i < total; ++i)
        {
            const QString entry = QString("Address: %1, Value: %2").arg(unit.startAddress() + i)
                    .arg(QString::number(unit.value(i),
                                         unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
            //            ui->textBrowser->append(entry);
            qInfo()<<entry;
            if((unit.startAddress() + i)<8)
            {
                values[(unit.startAddress() + i)]=unit.value(i);
            }
        }
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        qFatal(QString("Read response error: %1 (Mobus exception: 0x%2)").
               arg(reply->errorString()).
               arg(reply->rawResult().exceptionCode(), -1, 16).toLocal8Bit());
    }
    else
    {
        qFatal(QString("Read response error: %1 (code: 0x%2)").
               arg(reply->errorString()).
               arg(reply->error(), -1, 16).toLocal8Bit());
    }

    reply->deleteLater();
}

//初始化串口连接
void burglarAlarm485::initConnect(QString comNum,int Baud,int Interval/******时间周期**********/)
{
    if (!modbusDevice)
        return;

    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,comNum);//串口号
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,Baud);//波特率

    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);


    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);//设置数据位
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);//设置停止位
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::TwoStop);//设置停止位


    modbusDevice->setTimeout(1000);
    modbusDevice->setNumberOfRetries(3);

    if (modbusDevice->connectDevice())
    {
        connect(pollTimer,SIGNAL(timeout()),this,SLOT(slotReadRequest()));
        pollTimer->setInterval(/*ui->spinBoxInterval->value()*/Interval);
        pollTimer->start();
    }
    else    //打开失败提示
    {

        //        QMessageBox::information(this,QStringLiteral("错误"),QStringLiteral("连接从站失败！"),QMessageBox::Ok);
        qFatal(QString(QStringLiteral("连接从站失败")).toLocal8Bit());
    }
}

//断开连接
void burglarAlarm485::disconnectCom()
{
    modbusDevice->disconnectDevice();
    pollTimer->stop();

}

//刷新串口
void burglarAlarm485::refreshSerialPorts()
{
    //填充串口号组合框
    SearchSerialPorts();
}
