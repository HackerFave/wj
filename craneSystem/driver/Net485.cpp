#include "Net485.h"
#include <QtDebug>
#include <qlogging.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
Net485::Net485(long baud_rate, QString port_name,QObject *parent) : QObject(parent)
{
    const wchar_t name[8] = L"COM4";
    serial_port = CreateFile(name, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
    if (serial_port == INVALID_HANDLE_VALUE)
    {
        qWarning()<<"Error opening portn:"<<stderr;
        CloseHandle(serial_port);
    }
    else
    {
        set_up_serial_port(baud_rate);
    }
}



bool Net485::send(BYTE data[],int length)
{
    if (serial_port == INVALID_HANDLE_VALUE)
    {
        qWarning("发送失败::INVALID_HANDLE_VALUE");
        return false;
    }

    DWORD dwTx = 0;
    BOOL ret = FALSE;
    DWORD dwLength = length;

    Sleep(10);

    if (dwLength > 0)
    {
        ret = WriteFile(serial_port, data, dwLength, &dwTx, NULL);
        if (ret == FALSE)
        {
            qWarning()<<"发送失败";
            return false;
        }
    }

    return true;
}

void Net485::set_up_serial_port(long baud)
{
    DCB properties;

    // 设置读写缓冲区
    GetCommState(serial_port, &properties);

    switch (baud)
    {
    case 1200:
        properties.BaudRate = CBR_1200;
        break;
    case 2400:
        properties.BaudRate = CBR_2400;
        break;
    case 4800:
        properties.BaudRate = CBR_4800;
        break;
    case 9600:
        properties.BaudRate = CBR_9600;
        break;
    case 14400:
        properties.BaudRate = CBR_14400;
        break;
    case 19200:
        properties.BaudRate = CBR_19200;
        break;
    case 38400:
        properties.BaudRate = CBR_38400;
        break;
    default:
        fprintf(stderr, "Invalid baud rate: %ldn", baud);
        qWarning()<<QString("Invalid baud rate: %1n:").arg(baud)<<stderr;
        exit(0);
        break;
    }

    properties.Parity = NOPARITY;
    properties.ByteSize = 8;
    properties.StopBits = ONESTOPBIT;

    SetCommState(serial_port, &properties);

    //在读写串口前，用 PurgeComm 函数清空缓冲区
    PurgeComm(serial_port, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_TXABORT | PURGE_TXABORT);

    return;
}
/**************************测试****************************/
//void main()
//{
//    /// 485PLC通信
//    Net485* net = new Net485(9600,L"COM4");

//    BYTE data[2];
//    data[0] = 0x01;
//    if (info.th == 1) {

//        data[1] = 0x11;
//    }
//    else {

//        data[1] = 0x12;
//    }
//    net->send(data,sizeof(data));
//}

//void test(){
//    // 打开串口
//    QSerialPort serial;
//    serial.setPortName("COM1");    // 设置串口号
//    serial.setBaudRate(QSerialPort::Baud9600);   // 设置波特率
//    serial.setDataBits(QSerialPort::Data8);  // 设置数据位
//    serial.setParity(QSerialPort::NoParity); // 设置校验位
//    serial.setStopBits(QSerialPort::OneStop);    // 设置停止位
//    serial.setFlowControl(QSerialPort::NoFlowControl);  // 设置流控制

//    if (!serial.open(QIODevice::ReadWrite))
//    {
//        qDebug() << QObject::tr("打开串口失败!");
//        //        return a.exec();
//    }

//    // 读写数据
//    uint8_t data[8]={} ;//= {01 06 00 11 00 1E 59 C7};
//    data[0] = 0x01;
//    data[1] = 0x06;
//    data[2] = 0x00;
//    data[3] = 0x11;
//    data[4] = 0x00;
//    data[5] = 0x1E;
//    data[6] = 0x59;
//    data[7] = 0xC7;
////    QByteArray data;
////    data.append("hello");
//    serial.write((const char*)data,8);
////    serial.write(data,8);
////    data = serial.readAll();

//    // 关闭串口
//    serial.close();

//    //    return a.exec();
//}


//#include "mythread.h"
//MyThread::MyThread(Widget * parent, QSerialPort *port)
//{
//    this->parent = parent;//传入父对象，以便给它发信号this->port = port;//传入串口对象，以便在线程中使用
//}
////CRC校验码计算
//unsigned short CRC16(unsigned char *pBuf,unsigned short len)
//{
//    unsigned short uCRC=0xFFFF;
//    int i,j;for(i=0;i<len;i++){uCRC^=(*(pBuf+i));
//        for(j=0;j<8;j++)
//        {
//            if((uCRC&0x0001)==0x0001){uCRC=(uCRC>>1);
//                uCRC^=0xA001;}elseuCRC=(uCRC>>1);}
//    }return uCRC;
//}
//void MyThread::run()
//{
//    bool bRet = false;unsigned char buf[6];//关联信号与槽，用于给父对象信号，告知通讯结果
   //QObject::connect(this, SIGNAL(sendResult(int, QString)), parent, SLOT(result(int, QString)));//与43个RS485设备通讯，检查设备是否有回应
//for(unsigned char addr = 1; addr <= 43 ; ++addr){buf[0] = addr;buf[1] = 0x03;buf[2] = 0xA0;buf[3] = 0x06;unsigned short crc = CRC16(buf, 4);buf[4] = static_cast<unsigned char>(crc);buf[5] = static_cast<unsigned char>(crc >> 8);port->write(reinterpret_cast<const char *>(buf), 6);//发送数据port->flush();//让数据立刻从串口发送出去,不要在缓冲区里墨迹        msleep(200);//等待200ms//检查串口接收到了多少数据int num = static_cast<int>(port->bytesAvailable());if(num != 6){QString str = QString().sprintf("addr=%02d，设备没有响应, 返回数据量为%d",addr, static_cast<int>(num));emit sendResult(0, str);}else{// 接收到了6个字节，表时RS485设备有响应QByteArray array = port->readAll();QString str = QString().sprintf("addr=%02d, 发现设备，返回数据量为%d",addr, static_cast<int>(num));emit sendResult(0, str);}msleep(800);      }
//}
