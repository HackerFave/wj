#ifndef PUBLICCLASS_H
#define PUBLICCLASS_H

#include <QObject>
#include <mutex>
#include <QApplication>
#include <QSettings>
#include "ControlCAN.h"
#include <QQueue>
#include <QtDebug>
typedef struct canBufstruct{
    VCI_CAN_OBJ bj;
    short canIndex;
};
class publicClass : public QObject
{
    Q_OBJECT
private:
    explicit publicClass(QObject *parent = nullptr);
    publicClass & operator=(const publicClass & ) = delete;
    publicClass(const publicClass &) = delete;
public:
    enum C_DirMode{
        dir = 0,
        dirpath
    };
    ~publicClass();
    static publicClass* getInstance(){
        if (P_publicClass == nullptr)
        {
            std::lock_guard<std::mutex> lgd(_mutex);
            if (P_publicClass == nullptr)
            {
                P_publicClass = new publicClass;
            }
        }
        return P_publicClass;
    }
    static void delInstance()
    {
        std::lock_guard<std::mutex> lgd(_mutex);
        if (P_publicClass)
        {
            delete P_publicClass;
            P_publicClass = nullptr;
        }
    }

public:
    QString Byte_16(uchar *Data,int iLength);
    QString Byte_16(QString strData,int strLen);

    uint8_t cllc_checkSum(uint8_t const *p_data,int32_t datalen);//校验和

    void doubleArr2Bytes(double* floatArr, unsigned int len, unsigned char* byteBufOut);
    QString ByteArrayToHexStr(QByteArray buf);//转16进制字符串

    int HexToAscii(uint8_t* pHex, char *pAscii, uint8_t hex_len);//char数组转asc码



    QString getAsciiByArray(QByteArray &data);//QByteArray zhuan asc
    void QString2Hex(QString src,char* charresult);
    void floatArr2Bytes(float* floatArr, unsigned int len, unsigned char* byteBufOut);//float 转数组

    void shortArr2Bytes(short* floatArr, unsigned int len, unsigned char* byteBufOut);
    void int32Arr2Bytes(int32_t* Arr, unsigned int len, unsigned char* byteBufOut);
    void int64Arr2Bytes(int64_t* Arr, unsigned int len, unsigned char* byteBufOut);
    void ushortArr2Bytes(ushort* Arr, unsigned int len, unsigned char* byteBufOut);
    void uint32Arr2Bytes(uint32_t* Arr, unsigned int len, unsigned char* byteBufOut);
    void uint64Arr2Bytes(uint64_t* Arr, unsigned int len, unsigned char* byteBufOut);
    void Str2CharSplitBlank(QString s,uchar *c,uchar *len);
    QString hex2Str(unsigned char *in, int len);
    float hex2Float(unsigned char *m);
    QString hex2StrFloat(unsigned char *m);
    void setValueIni(QString key,QString value);
    QString readValueIni(QString key);
    int getCurrentCanIndex() const {return _canIndex; };
    void setCurrentCanIndex(int canIndex){_canIndex = canIndex; };
    QString getTimeStampStr(uint32_t TimeStamp);
    QQueue<canBufstruct> _canbuf;
    bool sendCanBuf(const QString &id, const QString &canbuf,const short &canindex);
    void setBj(canBufstruct &vc);
    canBufstruct getBj();
signals:

private:
    static publicClass *P_publicClass;
    static std::mutex _mutex;
    QSettings *_setting = nullptr;
    int _canIndex = 0;

};

#endif // PUBLICCLASS_H
