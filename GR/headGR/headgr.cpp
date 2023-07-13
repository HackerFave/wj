#include "headgr.h"
#include <QMetaType>
#include <QMetaObject>
HeadGR::HeadGR()
{
    qRegisterMetaType<int32_t>("int32_t");
    P_func = new func;
    connect(P_func,&func::signalData,this,&HeadGR::slotData);
    connect(&_timerInitData,&QTimer::timeout,this,&HeadGR::slotInitData);
    _timerInitData.start(500);
    connect(&_timerReadAngle,&QTimer::timeout,this,&HeadGR::slotReadAngle);
    _timerReadAngle.start(50);
}
void HeadGR::setOffsetAngle(uint8_t ID,int16_t angle)
{
    uint8_t data[8]={};
    data[0] = 0x3e;
    data[1] = 0x91;
    data[2] = ID;
    data[3] = 0x02;
    uint8_t srcHead[4]={};
    memmove(srcHead,data,4);
    unsigned char p = publicClass::getInstance()->cllc_checkSum(srcHead,4);//校验和

    data[4] = p;

    int16_t encoder = angle* 16383/360;

    memmove(&data[5],&encoder,2);
    uint8_t srcBody[2]={};
    memmove(srcBody,&data[5],2);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum(srcBody,2);//校验和
    data[7] = pbody;

    QString checkStr = QString("3E910%1").arg(QString::number(ID));
    qDebug()<<"0偏:"<<publicClass::getInstance()->Byte_16(data,8);
    P_func->writeData(data,8,checkStr);
}
//初始化加速度
void HeadGR::initAccel(uint8_t ID,int32_t accel)
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x34;
    head[2] = ID;
    head[3] = 0x04;
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
    head[4] = p;
    uint8_t body[5]={};
    memmove(body,&accel,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,4);
    body[4] = pbody;
    uint8_t data[10] = {};
    memmove(data,head,5);
    memmove(&data[5],body,5);
    QString checkStr = QString("3E340%1").arg(QString::number(ID));
    P_func->writeData(data,10,checkStr);

}
void HeadGR::setTurnAngle(uint8_t ID,int32_t angle,uint32_t speed)
{

    if(ID == 0X01){//水平方向

        if(abs(angle)>300){
            return;
        }

        int clockwise = publicClass::getInstance()->readValueIni("x1/clockwise").simplified().toInt();//顺时针
        int anticlockwise = publicClass::getInstance()->readValueIni("x1/anticlockwise").simplified().toInt();//逆时针
        if((angle+_angleX1)>clockwise){

            qDebug()<<"顺时针方向超出软限位";
            return;
        }
        else if ((angle+_angleX1)<anticlockwise) {
            qDebug()<<"逆时针方向超出软限位";
            return;
        }
//        qDebug()<<"current angle:"<<_angleX1<<clockwise<<anticlockwise;
        int32_t sangle = angle*100;
        uint32_t sspeed = speed*100;
        uint8_t data[14]={};
        data[0] = 0x3e;
        data[1] = 0xa8;
        data[2] = ID;
        data[3] = 0x08;
        uint8_t srcHead[4]={};
        memmove(srcHead,data,4);
        unsigned char p = publicClass::getInstance()->cllc_checkSum(srcHead,4);//校验和

        data[4] = p;

        memmove(&data[5],&sangle,4);
        memmove(&data[9],&sspeed,4);
        uint8_t srcBody[8]={};
        memmove(srcBody,&data[5],8);
        unsigned char pbody = publicClass::getInstance()->cllc_checkSum(srcBody,8);//校验和
        data[13] = pbody;

        QString checkStr = QString("3EA80%1").arg(QString::number(ID));
        P_func->writeData(data,14,checkStr);

    }
    else if (ID == 0X02) {//垂直方向
        int32_t sangle = angle*100;
        uint32_t sspeed = speed*100;
        uint8_t data[14]={};
        data[0] = 0x3e;
        data[1] = 0xa8;
        data[2] = ID;
        data[3] = 0x08;
        uint8_t srcHead[4]={};
        memmove(srcHead,data,4);
        unsigned char p = publicClass::getInstance()->cllc_checkSum(srcHead,4);//校验和

        data[4] = p;

        memmove(&data[5],&sangle,4);
        memmove(&data[9],&sspeed,4);
        uint8_t srcBody[8]={};
        memmove(srcBody,&data[5],8);
        unsigned char pbody = publicClass::getInstance()->cllc_checkSum(srcBody,8);//校验和
        data[13] = pbody;

        QString checkStr = QString("3EA80%1").arg(QString::number(ID));
        P_func->writeData(data,14,checkStr);
    }
}
void HeadGR::slotData(QString data)
{
    //    qDebug()<<data;
    if(data.contains("3EA80207")){

    }
    else if (data.contains("3E9C0207")) {//垂直方向 编码器角度值
        if(data.size()>=26){
            QStringList list = publicClass::getInstance()->Byte_16(data,data.size()).simplified().split(" ");

            uint8_t bmq[2]={};

            bool ok;
            uint8_t s1 = list[10].toInt(&ok,16);
            uint8_t s2 = list[11].toInt(&ok,16);
            int16_t s =0;

            memmove(bmq,&s1,1);
            memmove(&bmq[1],&s2,1);
            memmove(&s,&bmq,2);
            _angleX2 = s*360/16383;
            //            qDebug()<<"[ANGLE X2:]"<<_angleX2;
            _funCall(encoder_x2,_angleX2);
        }
    }
    else if (data.contains("3E9C0107")) {//水平方向 编码器角度值
        if(data.size()>=26){
            QStringList list = publicClass::getInstance()->Byte_16(data,data.size()).simplified().split(" ");

            uint8_t bmq[2]={};

            bool ok;
            uint8_t s1 = list[10].toInt(&ok,16);
            uint8_t s2 = list[11].toInt(&ok,16);
            int16_t s =0;

            memmove(bmq,&s1,1);
            memmove(&bmq[1],&s2,1);
            memmove(&s,&bmq,2);
            _angleX1 = s*360/16383;
            //            qDebug()<<"[ANGLE X1:]"<<_angleX1;
            _funCall(encoder_x1,_angleX1);
        }
    }
    else if (data.contains("3E330204")) {//垂直方向 加速度
        if(data.size()>=20){
            QStringList list = publicClass::getInstance()->Byte_16(data,data.size()).simplified().split(" ");

            uint8_t bmq[4]={};

            bool ok;
            uint8_t s1 = list[5].toInt(&ok,16);
            uint8_t s2 = list[6].toInt(&ok,16);
            uint8_t s3 = list[7].toInt(&ok,16);
            uint8_t s4 = list[8].toInt(&ok,16);
            int32_t s =0;

            memmove(bmq,&s1,1);
            memmove(&bmq[1],&s2,1);
            memmove(&bmq[2],&s3,1);
            memmove(&bmq[3],&s4,1);
            memmove(&s,&bmq,4);
            _funCall(accel_x2,s);
            qDebug()<<"[ACCEL X2:]"<<s;
        }
    }
    else if (data.contains("3E330104")) {//水平方向 加速度
        if(data.size()>=20){
            QStringList list = publicClass::getInstance()->Byte_16(data,data.size()).simplified().split(" ");

            uint8_t bmq[4]={};

            bool ok;
            uint8_t s1 = list[5].toInt(&ok,16);
            uint8_t s2 = list[6].toInt(&ok,16);
            uint8_t s3 = list[7].toInt(&ok,16);
            uint8_t s4 = list[8].toInt(&ok,16);
            int32_t s =0;

            memmove(bmq,&s1,1);
            memmove(&bmq[1],&s2,1);
            memmove(&bmq[2],&s3,1);
            memmove(&bmq[3],&s4,1);
            memmove(&s,&bmq,4);
            _funCall(accel_x1,s);
            qDebug()<<"[ACCEL X1:]"<<s;
        }
    }
}
void HeadGR::regeditCallBack(FuncCall fun)/*注册回调函数*/
{
    _funCall = fun;
}
void HeadGR::getEncoder(uint8_t id)
{
    switch (id) {
    case 0x01:{
        QString STR1 = "3e 9c 01 00 DB";
        QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
        QString check ="";
        P_func->writeData((unsigned char*)byte.data(),byte.size(),check);
        break;
    }
    case 0x02:{
        QString STR1 = "3e 9c 02 00 DC";
        QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
        QString check ="";
        P_func->writeData((unsigned char*)byte.data(),byte.size(),check);
        break;
    }
    default:
        break;
    }
}
void HeadGR::getAccel(uint8_t ID)
{

    switch (ID) {
    case 0x01:{
        QString STR1 = "3e 33 01 00 72";
        QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
        QString check ="";
        P_func->writeData((unsigned char*)byte.data(),byte.size(),check);
        break;
    }
    case 0x02:{
        QString STR1 = "3e 33 02 00 73";
        QByteArray byte = QByteArray::fromHex(STR1.toLatin1());
        QString check ="";
        P_func->writeData((unsigned char*)byte.data(),byte.size(),check);
        break;
    }
    default:
        break;
    }
}
void HeadGR::clearError(uint8_t ID)
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x9B;
    head[2] = ID;
    head[3] = 0x00;
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
    head[4] = p;
    QString checkStr = QString("3E9B0%1").arg(QString::number(ID));
    P_func->writeData(head,5,checkStr);
}
void HeadGR::clearAngle(uint8_t ID)
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x95;
    head[2] = ID;
    head[3] = 0x00;
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);
    head[4] = p;
    QString checkStr = QString("3E950%1").arg(QString::number(ID));
    P_func->writeData(head,5,checkStr);
}
void HeadGR::slotInitData()
{
    static int num = 0;
    if(num == 0){
        initAccel(0x01,1800);
        num++;
    }
    else if(num == 1) {
        initAccel(0x02,12000);
        _timerInitData.stop();
    }

}
void HeadGR::slotReadAngle()
{
    static int num = 0;
    if (num == 0) {
        getEncoder(0x01);
        num++;
    }
    else if (num == 1) {
        getEncoder(0x02);
        num = 0;
    }

}
