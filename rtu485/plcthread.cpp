#include "plcthread.h"
#include <QSerialPort>
#include <QSerialPortInfo>

PlcThread::PlcThread(QObject *parent) : QObject(parent)
{

}

PlcThread::~PlcThread()
{

}

void PlcThread::doWork()
{
  modbusDevice = new QModbusRtuSerialMaster;
  dataTimer = new QTimer;
  connect(dataTimer,&QTimer::timeout,this,&PlcThread::readPlc);
}

void PlcThread::connectPlc()
{
    qDebug()<<"connect";
    qDebug()<<"显示plc线程ID:"<<QThread::currentThread();  //显示当前线程的数值


    if(!modbusDevice)
    {
        return;
    }
//    statusBar()->clearMessage();
    if(modbusDevice->state() != QModbusDevice::ConnectedState)
    {

        modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,global::ComPortName);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::EvenParity);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,QSerialPort::Baud9600);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);
        modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);
        modbusDevice->setTimeout(1000);
        modbusDevice->setNumberOfRetries(3);

        if(!modbusDevice->connectDevice())//连接失败
        {
            //statusBar()->showMessage(tr("Connect Failed:") + modbusDevice->errorString(),5000);
            emit statusBar(tr("Connect Failed:") + modbusDevice->errorString());
        }
        else//成功连接
        {
            emit change2Discon();
            dataTimer->start(500);
        }
    }
    else
    {
        modbusDevice->disconnectDevice();
        dataTimer->stop();
        emit change2Con();
    }
    qDebug() << modbusDevice->state();

}

void PlcThread::readPlc()
{
    qDebug()<<"read";
    if (!modbusDevice)
    {
        return;
    }
    //statusBar()->clearMessage();
    emit statusBar(nullptr);
    QModbusDataUnit readUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, 0, 2);
    if (auto *reply = modbusDevice->sendReadRequest(readUnit, 1)) //1->modbus设备地址
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &PlcThread::torqReadReady);
        }
        else
        {
            delete reply; // broadcast replies return immediately
        }
    }
    else
    {
        //statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
        emit statusBar(tr("Read error: ") + modbusDevice->errorString());
    }
    /**/
    QModbusDataUnit readUnit2 = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, 2, 2);
    if (auto *reply = modbusDevice->sendReadRequest(readUnit2, 1)) //1->modbus设备地址
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &PlcThread::spdReadReady);
        }
        else
        {
            delete reply; // broadcast replies return immediately
        }
    }
    else
    {
        //statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
        emit statusBar(tr("Read error: ") + modbusDevice->errorString());
    }


}

void PlcThread::torqReadReady()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
    {
        return;
    }

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();
        for (uint i = 0; i < unit.valueCount(); i++)
        {
            int ii = static_cast<int>(i);
            QString str =QString("%1").arg(unit.value(ii),4,16,QLatin1Char('0'));
            qDebug()<<str;
            bool ok;
            T[3-2*ii]= static_cast<uchar>(str.mid(0,2).toInt(&ok,16));
            T[2-2*ii]= static_cast<uchar>(str.mid(2,4).toInt(&ok,16));
        }

        float f_T;
        memcpy_s(&f_T , sizeof(float) , T , 4);
        qDebug()<<f_T;

        //ui->readT->setText(QString::number(static_cast<double>(f_T) ));

        emit updateT(QString::number(static_cast<double>(f_T) ));
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
//        statusBar()->showMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
//                                    arg(reply->errorString()).
//                                    arg(reply->rawResult().exceptionCode(), -1, 16), 5000);
        emit statusBar(tr("Read response error: %1 (Mobus exception: 0x%2)").
                       arg(reply->errorString()).
                       arg(reply->rawResult().exceptionCode(), -1, 16));
    }
    else
    {
//        statusBar()->showMessage(tr("Read response error: %1 (code: 0x%2)").
//                                    arg(reply->errorString()).
//                                    arg(reply->error(), -1, 16), 5000);
        emit statusBar(tr("Read response error: %1 (code: 0x%2)").
                       arg(reply->errorString()).
                       arg(reply->error(), -1, 16));
    }

    reply->deleteLater();

}

void PlcThread::spdReadReady()
{
    auto reply2 = qobject_cast<QModbusReply *>(sender());
    if (!reply2)
    {
        return;
    }

    if (reply2->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply2->result();
        for (uint i = 0; i < unit.valueCount(); i++)
        {
            int ii = static_cast<int>(i);
            QString str =QString("%1").arg(unit.value(ii),4,16,QLatin1Char('0'));
            qDebug()<<str;
            bool ok;
            S[3-2*ii]= static_cast<uchar>(str.mid(0,2).toInt(&ok,16));
            S[2-2*ii]= static_cast<uchar>(str.mid(2,4).toInt(&ok,16));
        }

        float f_S;
        memcpy_s(&f_S , sizeof(float) , S , 4);
        qDebug()<<f_S;

       // ui->readS->setText(QString::number(static_cast<double>(f_S) ));
        emit updateS(QString::number(static_cast<double>(f_S) ));
    }
    else if (reply2->error() == QModbusDevice::ProtocolError)
    {
//        statusBar()->showMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
//                                    arg(reply2->errorString()).
//                                    arg(reply2->rawResult().exceptionCode(), -1, 16), 5000);
        emit statusBar(tr("Read response error: %1 (Mobus exception: 0x%2)").
                       arg(reply2->errorString()).
                       arg(reply2->rawResult().exceptionCode(), -1, 16));

    }
    else
    {
//        statusBar()->showMessage(tr("Read response error: %1 (code: 0x%2)").
//                                    arg(reply2->errorString()).
//                                    arg(reply2->error(), -1, 16), 5000);
        emit statusBar(tr("Read response error: %1 (code: 0x%2)").
                       arg(reply2->errorString()).
                       arg(reply2->error(), -1, 16));

    }

    reply2->deleteLater();

}

void PlcThread::on_writeTor(QString t)
{
    if (!modbusDevice)
        return;
    //statusBar()->clearMessage();
    emit statusBar(nullptr);

    //QModbusDataUnit的参数::QModbusDataUnit(QModbusDataUnit::HoldingRegisters, startAddress, numberOfEntries)
    QModbusDataUnit writeUnit = QModbusDataUnit(QModbusDataUnit::HoldingRegisters, 4, 2);
    for (uint i = 0; i < writeUnit.valueCount(); i++)
    {
        int ii = static_cast<int>(i);
        //writeUnit.setValue(ii, holdingRegisters[ii + writeUnit.startAddress()]);
        int j = 4*ii;
        QString st = t.mid (j,4);
        bool ok;
        int hex =st.toInt(&ok,16);//将textedit中读取到的数据转换为16进制发送
        quint16 qhex =static_cast<quint16>(hex);
       // qDebug()<<writeUnit.valueCount();
        writeUnit.setValue(ii,qhex);

    }

    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit, 1)) {//1->modbus 地址
        if (!reply->isFinished()) {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::ProtocolError)
                {
//                    statusBar()->showMessage(tr("Write response error: %1 (Mobus exception: 0x%2)")
//                        .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16),
//                        5000);
                    emit statusBar(tr("Write response error: %1 (Mobus exception: 0x%2)")
                                                          .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
                } else if (reply->error() != QModbusDevice::NoError)
                {
//                    statusBar()->showMessage(tr("Write response error: %1 (code: 0x%2)").
//                        arg(reply->errorString()).arg(reply->error(), -1, 16), 5000);
                    emit statusBar(tr("Write response error: %1 (code: 0x%2)").
                                                  arg(reply->errorString()).arg(reply->error(), -1, 16));
                }
                reply->deleteLater();
            });
        } else {
            // broadcast replies return immediately
            reply->deleteLater();
        }
    } else {
        //statusBar()->showMessage(tr("Write error: ") + modbusDevice->errorString(), 5000);
        emit statusBar(tr("Write error: ") + modbusDevice->errorString());
    }

}

