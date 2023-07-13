#include "publicclass.h"
#include <QUuid>
#include <QCryptographicHash>
#include <QtDebug>
#define uint8ToHexStr(dest, src, len)\
    for(int i = 0; i < len; i++ ){\
    sprintf(&dest[i * 2], "%02x", (unsigned char)src[i]);\
    }\
    dest[len * 2] = '\0';
typedef struct {
    char cmd;
    QString data;
} cmdList_t; /* 该结构体可以精简掉 直接用QStringList也可以处理 */
static cmdList_t cmdList[] = {
    {0x00, QString("NULL")}, {0x01, QString("SOH")}, {0x02, QString("STX")},
    {0x03, QString("ETX")},  {0x04, QString("EOT")}, {0x05, QString("ENQ")},
    {0x06, QString("ACK")},  {0x07, QString("BEL")}, {0x08, QString("BS")},
    {0x09, QString("HT")},   {0x0A, QString("LF")},  {0x0B, QString("VT")},
    {0x0C, QString("FF")},   {0x0D, QString("CR")},  {0x0E, QString("SO")},
    {0x0F, QString("SI")},   {0x10, QString("DLE")}, {0x11, QString("DC1")},
    {0x12, QString("DC2")},  {0x13, QString("DC3")}, {0x14, QString("DC4")},
    {0x15, QString("NAK")},  {0x16, QString("SYN")}, {0x17, QString("ETB")},
    {0x18, QString("CAN")},  {0x19, QString("EM")},  {0x1A, QString("SUB")},
    {0x1B, QString("ESC")},  {0x1C, QString("FS")},  {0x1D, QString("GS")},
    {0x1E, QString("RS")},   {0x1F, QString("US")},  {0x20, QString(" ")},
    {0x7F, QString("DEL")}};

publicClass* publicClass::P_publicClass = Q_NULLPTR;
std::mutex publicClass::_mutex;
publicClass::publicClass(QObject *parent ):QObject(parent)
{

    //iniSystemConfigFile();
    _setting = new QSettings(QCoreApplication::applicationDirPath()+"/config/config.ini",QSettings::IniFormat);
}


publicClass::~publicClass()
{
    P_publicClass->delInstance();
}
QString publicClass::Byte_16(uchar *Data,int iLength)      //输入 uchar 型 字符串，返回 QString 型 16进制 字符串。
{
    QString ST="",strT;
    int iB,iS;
    char cB,cS;

    //---
    for (int i=0;i<iLength;i++)
    {
        iB = *(Data+i)/16;
        if (iB>=10)
        {
            cB = 'A' + (iB-10);
        }
        else
            cB = '0' + iB;

        iS = *(Data+i)%16;
        if (iS >= 10)
        {
            cS = 'A' + (iS-10);
        }
        else
            cS = '0' + iS;
        strT=QString("%1%2 ").arg(cB).arg(cS);
        ST += strT;
    }
    return ST;
}
QString publicClass::Byte_16(QString strData,int strLen)      //输入 uchar 型 字符串，返回 QString 型 16进制 字符串。
{

    if(strData.size()!=strLen){
        return QString("");
    }
     QString ST="",strT;
    for(int i=0;i<strData.size()-1;i=i+2){
        ST= ST+strData.at(i)+strData.at(i+1)+" ";
    }

    return ST.simplified();
}
uint8_t publicClass::cllc_checkSum(uint8_t const *p_data,int32_t datalen)
{
    uint8_t sum = 0;
    while (datalen--) {
        sum+=*p_data++;
    }
    return sum;
}
int publicClass::HexToAscii(uint8_t* pHex, char *pAscii, uint8_t hex_len)
{
    uint8_t hex_data[2] = {0x00};
    for (uint16_t i = 0; i < hex_len; i++)
    {
        hex_data[0] = (pHex[i] & 0xF0) >> 4;
        hex_data[1] = pHex[i] & 0x0F;
        for (uint16_t j = 0; j < 2; j++)
        {
            //0-9 convert
            if(hex_data[j] < 10)
            {
                hex_data[j] += 0x30; //0x30 is '0'
            }
            //A-F convert
            else if(hex_data[j] < 16)
            {
                hex_data[j] = hex_data[j] - 10 + 0x41; //0x41 is 'A'
            }
            else
            {
                return -1;
            }
            *pAscii++ = hex_data[j];
        }
    }
    return 1;
}
QString publicClass::getAsciiByArray(QByteArray &data)
{
    uint16_t len = data.length();
    QString sRet;
    if (len == 0) {
        return sRet;
    }
    QString tmp;
    for (uint16_t cnt = 0; cnt < len; cnt++) {
        if (0x00 > data.at(cnt))
            continue;
        if (0x20 < data.at(cnt) && 0x7E >= data.at(cnt)) {
            tmp.clear();
            sRet += QString::asprintf("%c", data.at(cnt));
        } else {
            if (0x7F == data[cnt]) {
                sRet += cmdList[32].data;
            } else if (0x20 >= data.at(cnt)) {
                sRet += cmdList[(int)data.at(cnt)].data;
            } else {
                continue;
            }
        }
    }

    return sRet;
}
void publicClass::floatArr2Bytes(float* floatArr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&floatArr[i]);

        for (k = 0; k < 4; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::doubleArr2Bytes(double* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 8; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::shortArr2Bytes(short* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 2; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::int32Arr2Bytes(int32_t* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 4; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::int64Arr2Bytes(int64_t* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);
        for (k = 0; k < 8; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::ushortArr2Bytes(ushort* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 2; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::uint32Arr2Bytes(uint32_t* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 4; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void publicClass::uint64Arr2Bytes(uint64_t* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);
        for (k = 0; k < 8; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
QString  publicClass::ByteArrayToHexStr(QByteArray buf)
{
    QString ret(buf.toHex().toUpper());
    int len = ret.length()/2;
    //    qDebug()<<len;
    for(int i=1;i<len;i++)
    {
        ret.insert(2*i+i-1," ");
    }

    return ret;
}
//qstring zhuan char*
void publicClass::QString2Hex(QString src,char* charresult)
{
    bool ok;
    uint Bytesize = src.size()/2;
    for (int j =0;j<Bytesize;++j )
    {
        QString hexstring = ("0X"+src.mid(j*2,2));
        charresult[j] = hexstring.toUInt(&ok,16);
    }
}
/**
  *@brief:将发送框里面的字符串s去除空格，保存到*C,并反馈出数据的长度到len
  *@param:
  *@date:
  */
void publicClass::Str2CharSplitBlank(QString s, uchar *c,uchar *len)
{
    bool ok;
    QStringList lstr=s.split(" ");
    *len =static_cast<uchar>(lstr.length());
    if(*len!=0){
        for(int i=0;i<*len;i++)
        {
            c[i]=static_cast<unsigned char>(lstr[i].toInt(&ok,16));
        }
    }
}
/*************************************************内部调用函数************************************************************/

//16进制数据转字符串形式，数据间插入空格
QString publicClass::hex2Str(unsigned char *in, int len)
{
    QString s;
    for(int i=0;i<len;i++)
    {
        s+=QString("%1").arg(in[i]&0xFF,2,16,QLatin1Char('0')).toUpper();
        s.append(" ");
    }
    return s;
}
//16进制转float
float publicClass::hex2Float(unsigned char *m)
{
    union{
        unsigned char data[4];
        float num;
    }v_type;
    // memcpy(v_type.data,m,4);
    v_type.data[0]=m[3];
    v_type.data[1]=m[2];
    v_type.data[2]=m[1];
    v_type.data[3]=m[0];
    return v_type.num;
}
/**
 * @brief canDataShowForm::hex2StrFloat 16进制转浮点型字符串格式
 * @param m
 * @return
 */
QString publicClass::hex2StrFloat(unsigned char *m)
{
    union{
        unsigned char data[4];
        float num;
    }v_type;
    v_type.data[0]=m[3];
    v_type.data[1]=m[2];
    v_type.data[2]=m[1];
    v_type.data[3]=m[0];
    return QString("%1").arg(static_cast<double>(v_type.num),0,'f');
}
void publicClass::setValueIni(QString key,QString value)
{
    _setting->setValue(key,value);
}
QString  publicClass::readValueIni(QString key)
{
    return _setting->value(key).toString();
}
QString publicClass::getTimeStampStr(uint32_t TimeStamp)

{

    QString resultStr = "";

    int hour = TimeStamp/36000000;

    int minute = (TimeStamp - hour*36000000)/600000;

    int second = (TimeStamp - hour*36000000 - minute*600000)/10000;

    int ms = (TimeStamp - hour*36000000 - minute*600000 - second*10000)/10;

    int mms = (TimeStamp - hour*36000000 - minute*600000 - second*10000 - ms*10);

    resultStr = QString("%1:").arg(hour,2,10,QChar('0'));//时

    resultStr += QString("%1:").arg(minute,2,10,QChar('0'));//分

    resultStr += QString("%1:").arg(second,2,10,QChar('0'));//秒

    resultStr += QString("%1:").arg(ms,3,10,QChar('0'));//毫秒

    resultStr += QString::number(mms);//0.1ms

    return resultStr;

}
