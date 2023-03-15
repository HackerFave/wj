#ifndef BURGLARALARM485_H
#define BURGLARALARM485_H

#include <QObject>
#include <QtGlobal>
#include <stdint.h>
#include <QStringList>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTime>
#include <QtCharts>
//#include <QModbusDataUnit>
#include <QModbusClient>
#include <QModbusRtuSerialMaster>
#include <QQueue>

//寄存器地址
#define   Alarm_playing_status  0X0010 //报警器状态
#define   Alarm_volume   0X0011 // 报警器音量
#define   Alarm_tone   0X0012 //报警器音调
#define   Alarm_play_mode   0X0013 //报警器播放模式
#define   Warning_light_flashing_mode   0X0014 //警示灯闪烁模式
#define   Total_track_of_alarm   0X0080 //报警器总曲目
#define   Slave_address   0X0020 //从机地址
//功能码
#define READ 0X03 //读取数据
#define WRITE_SINGLE 0X06 //写单个寄存器
#define WRITE_MULTIPEL 0X10 //写多个寄存器
//地址码
#define  ADDRESS     0X01
#define  ADDRESS_SET 0X00
#define  ALARM_ADDRESS 0x0001 //报警器地址
#define  ALARM_STATE_ADDRESS (uint16)0x040E //报警器播放状态寄存器


/*
 * 功能码
 * 0X03 读取数据
 * 0X06 写入单个数据
 * 0X10 写入多个数据
 *----------------------------------------------------------------------------------------------|
 *              |      发送数据             |     接收数据                |     接收数据说明          |
 *--------------|--------------------------------------------------------------------------------|
 * 读取数据（03H）|  01 03 00 11 00 01 D4 0F |  01 03 02 00 03 F8 45      |    当前报警音量为3级      |
 *-----------------------------------------------------------------------------------------------|
 *              | 01 06 00 11 00 1E 59 C7  | 01 06 00 11 00 1E 59 C7    |   设置报警音量为30级      |
 *              |-------------------------------------------------------- -----------------------|
 *写入单个数据    | 00 06 00 20 00 02 08 10  |   02 06 00 20 00 02 09 F2  |    设置从机地址为02       |
 *   (06H)      |--------------------------------------------------------------------------------|
 *              | 00 06 00 20 00 01 48 11  |   01 06 00 20 00 01 49 C0  |    设置从机地址为01       |
 *-----------------------------------------------------------------------------------------------|
 *              | 01 10 00 10 00 05 0A 00  |                            |                        |
 *              | 03 00 10 01 02 00 02 02  |   01 10 00 10 00 05 01 CF  |    设置警示灯与报警器打开， |
 *              | 01 0C 68                 |                            |     报警音量为16级，      |
 * 写入连续寄存器  |                          |                            |     第1个文件夹第2首曲目， |
 *              |                          |                            |     单曲播放模式，        |
 *              |                          |                            |    警示灯与报警器同步，    |
 *              |                          |                            |    发光模式为爆闪         |
 *              |                          |                            |                        |
 * -------------------------------------------------------------------------------------------------
 *  0103 读取数据0x11(报警器音量,起始位)0x0001(一个字节) D4 0F(CRC)
 *  0103 返回数据0x02（两个字节） 0x0003 （音量3级） F8 45(CRC)
 *
 *  0106 写入单个数据 0x0011（报警器音量）  0x001E （设置音量30级） 59 C7（CRC校验）
 *
 *  0110 写入连续寄存器 0x0010（报警器状态） 0x0005 （5个寄存器）0x0A00(10个字节) 0x0003（报警器与警示灯都打开)--起始地址10
 *  0x0010（报警音量16级）--起始地址11  0x0102（报警音调，第一个文件夹第二首曲目）--起始地址12 0x0002（播放模式，单曲播放）--起始地址13
 *  0x0201（警示灯闪烁模式，警示灯与报警器不同步，模式为爆闪模式）--起始地址14  0C 68（CRC校验）
 */

typedef struct
{
    bool eRcvState;
    uint8_t ucRcvBuf[100]; // 接收缓冲区
    uint32_t usRcvBufPos; // 接收数据数据下标
    uint32_t usRcvTimeOutCnt; // 接收超时完成计数
    uint8_t usRcvStartTimeCntFlag; // 接收超时完成标志
    bool eSndState;
    uint8_t ucSndBuf[100]; // 发送缓冲区
    uint32_t usSndBufPos; // 发送数据数据下标
    uint8_t bActive;
    //接收数据有效性，0:接收未完成 1:接收完成数据有效 2:接收完成数据无效
}UartEvent_TypeDef;

/***********************************
 *
 *  例：01 83 02 C0 F1 （0x02为错误码）
 *
 * ***********************************/
//错误码
enum Error_Code
{
    error_01 =  0x01 ,//-非法的功能码
    error_02 =  0x02,//-非法的寄存器地址
    error_03 =  0x03,//-非法的数据（包括数据值、数据长度等）
    error_07 =  0x07 //-非法的校验码
};
class burglarAlarm485 : public QObject
{
    Q_OBJECT
public:
    explicit burglarAlarm485(QObject *parent = nullptr);
private:
    //    void InitialSetting();

    void SearchSerialPorts();//搜索串口


    void WriteRequest(QModbusDataUnit::RegisterType type,QList<quint16> values,int startAddress,int serverAddress/***从站地址****/);

    uint16_t usMBCRC16(uint8_t *crcdata, uint32_t sizeofarray);//CRC校验
    uint16_t ModbusCRC16(QByteArray senddata);//CRC校验qt
    void Alarm_Command_06H_Change_Register(UartEvent_TypeDef *Obj, uint16_t Register_Address,uint16_t Change_Data);
    void initConnect(QString comNum,int Baud,int Interval);//串口连接
    void disconnectCom();//断开设备
    void refreshSerialPorts();//刷新串口
private slots:
    void slotReadSerialData();
    //QModbusDataUnit readRequest() const;
    void slotReadRequest(QModbusDataUnit::RegisterType type,int startAddress,int readNum);
    void slotReadRequest();
private:
    //QSerialPort *serialPort;
    QModbusReply *lastRequest = nullptr;
    QModbusClient *modbusDevice = nullptr;
    QTimer *pollTimer;

    QTimer *chartTimer;

    uint16_t values[8];

    QQueue<QString> _quePort;//串口

};

#endif // BURGLARALARM485_H



//QModbusClient :: QModbusClient（QObject * parent = nullptr）
//构造函数

//[signal] void QModbusClient::timeoutChanged(int newTimeout)
//当此QModbusClient实例超时时，将发出此信号。设备的新响应超时将作为newTimeout传递。

//int QModbusClient::numberOfRetries() const
//返回客户端在请求失败之前将执行的重试次数。默认值设置为3。

//[virtual protected] bool QModbusClient::processPrivateResponse(const QModbusResponse &response, QModbusDataUnit *data)
//将通过自定义Modbus客户端实现来实现。默认实现忽略响应和数据。它始终返回false表示错误。

//[virtual protected] bool QModbusClient::processResponse(const QModbusResponse &response, QModbusDataUnit *data)
//处理Modbus服务器响应并将解码后的信息存储在data中。成功返回true；否则为假。

//QModbusReply *QModbusClient::sendRawRequest(const QModbusRequest &request, int serverAddress)
//发送原始Modbus请求。原始请求可以包含适合Modbus PDU数据部分且具有有效功能代码的任何内容。因此，在发送之前执行的唯一检查就是有效性检查，
//请参见QModbusPdu :: isValid。如果没有错误发生，该函数将返回一个新的有效QModbusReply ; 否则为nullptr。Modbus网络可能有多个服务器，每个服务器都有一个唯一的serverAddress。

//QModbusReply *QModbusClient::sendReadRequest(const QModbusDataUnit &read, int serverAddress)
//发送到读取由指向的数据的内容的请求的读取。如果没有发生错误，则返回一个新的有效QModbusReply对象，否则返回nullptr。Modbus网络可能有多个服务器，每个服务器都有唯一的serverAddress。

//QModbusReply *QModbusClient::sendReadWriteRequest(const QModbusDataUnit &read, const QModbusDataUnit &write, int serverAddress)
//发送请求以使用Modbus功能代码QModbusPdu :: ReadWriteMultipleRegisters读取read指向的数据的内容并修改write指向的数据的内容。如果没有发生错误，则返回一个新的有效QModbusReply对象，
//否则返回nullptr。Modbus网络可能有多个服务器，每个服务器都有唯一的serverAddress。

//QModbusReply *QModbusClient::sendWriteRequest(const QModbusDataUnit &write, int serverAddress)
//发送请求以修改write指向的数据内容。如果没有发生错误，则返回一个新的有效QModbusReply对象，否则返回nullptr。Modbus网络可能有多个服务器，每个服务器都有唯一的serverAddress。

//void QModbusClient::setNumberOfRetries(int number)
//设置重试请求失败之前，客户端将执行的次数。默认值设置为3。

//注意：新值必须大于或等于0。更改此属性将仅影响新请求，而不影响已计划的请求。

//void QModbusClient::setTimeout(int newTimeout)
//设置超时时间为newTimeout。最小超时为10毫秒。

//客户端使用超时来确定它等待服务器响应的时间。如果在要求的超时时间内未收到响应，则设置TimeoutError。

//这样的超时持续时间更改不会影响已经激活/正在运行的超时。
//-----------------------------------
//©著作权归作者所有：来自51CTO博客作者itcast0的原创作品，请联系作者获取转载授权，否则将追究法律责任
//【Qt】QModbusClient类

