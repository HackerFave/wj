#include "serialWorkThreadPool.h"

serialWorkThreadPool::serialWorkThreadPool(int id, QSerialWork *port):
    _id(id),
    P_QSerialWork(port)
{
    connect(P_QSerialWork,&QSerialWork::NewData,this,&serialWorkThreadPool::slotWorkData);
}
Q_INVOKABLE void serialWorkThreadPool::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool::slotWork()
{
  qDebug()<<"111111111111111111111111111111111111111111111";
}
void serialWorkThreadPool::slotWorkData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");

//    ui->textEdit_recv->append("DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );

//    for(int i =5;i<list.size()-1;i++){

//        double f;
//        bool ok;
//        f = list.at(i).toInt(&ok, 16);
//        ui->textEdit_recv->append(list.at(i)+ "recv dec data:"+QString::number(f));

//    }
 qDebug()<<"DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) ;
    //    float val;
    //    unsigned char hexdata[4]={0x00,0x00,0x48,0x41};
    //    memcpy(&val,hexdata,4);
}
serialWorkThreadPool_1::serialWorkThreadPool_1(int id,QSerialWork *port):
    _id(id),
    P_QSerialWork(port)
{
    connect(P_QSerialWork,&QSerialWork::NewData,this,&serialWorkThreadPool_1::slotWorkData);
}
Q_INVOKABLE void serialWorkThreadPool_1::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_1::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_1::slotWork()
{
   qDebug()<<"222222222222222222222222222222222222222222222";

}
void serialWorkThreadPool_1::slotWorkData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");

//    ui->textEdit_recv->append("DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );

//    for(int i =5;i<list.size()-1;i++){

//        double f;
//        bool ok;
//        f = list.at(i).toInt(&ok, 16);
//        ui->textEdit_recv->append(list.at(i)+ "recv dec data:"+QString::number(f));

//    }
 qDebug()<<"DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) ;
    //    float val;
    //    unsigned char hexdata[4]={0x00,0x00,0x48,0x41};
    //    memcpy(&val,hexdata,4);
}
serialWorkThreadPool_2::serialWorkThreadPool_2(int id,QSerialWork *port):
    _id(id),
    P_QSerialWork(port)
{
    connect(P_QSerialWork,&QSerialWork::NewData,this,&serialWorkThreadPool_2::slotWorkData);
}
Q_INVOKABLE void serialWorkThreadPool_2::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_2::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_2::slotWork()
{
    qDebug()<<"3333333333333333333333333333333333333333333333";

}
void serialWorkThreadPool_2::slotWorkData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");

//    ui->textEdit_recv->append("DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );

//    for(int i =5;i<list.size()-1;i++){

//        double f;
//        bool ok;
//        f = list.at(i).toInt(&ok, 16);
//        ui->textEdit_recv->append(list.at(i)+ "recv dec data:"+QString::number(f));

//    }
 qDebug()<<"DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) ;
    //    float val;
    //    unsigned char hexdata[4]={0x00,0x00,0x48,0x41};
    //    memcpy(&val,hexdata,4);
}
serialWorkThreadPool_3::serialWorkThreadPool_3(int id,QSerialWork *port):
    _id(id),
    P_QSerialWork(port)
{
    connect(P_QSerialWork,&QSerialWork::NewData,this,&serialWorkThreadPool_3::slotWorkData);
}
Q_INVOKABLE void serialWorkThreadPool_3::startWork()
{
    _isStart = true;
}
Q_INVOKABLE void serialWorkThreadPool_3::stopWork()
{
    _isStart = false;
}
Q_INVOKABLE void serialWorkThreadPool_3::slotWork()
{
    qDebug()<<"4444444444444444444444444444444444444444444444444";

}
void serialWorkThreadPool_3::slotWorkData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");

//    ui->textEdit_recv->append("DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );

//    for(int i =5;i<list.size()-1;i++){

//        double f;
//        bool ok;
//        f = list.at(i).toInt(&ok, 16);
//        ui->textEdit_recv->append(list.at(i)+ "recv dec data:"+QString::number(f));

//    }
 qDebug()<<"DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) ;
    //    float val;
    //    unsigned char hexdata[4]={0x00,0x00,0x48,0x41};
    //    memcpy(&val,hexdata,4);
}
serialWorkThreadPool_4::serialWorkThreadPool_4(int id,QSerialWork *port):
    _id(id),
    P_QSerialWork(port)
{
    connect(P_QSerialWork,&QSerialWork::NewData,this,&serialWorkThreadPool_4::slotWorkData);
}
Q_INVOKABLE void serialWorkThreadPool_4::startWork()
{

}
Q_INVOKABLE void serialWorkThreadPool_4::stopWork()
{

}
Q_INVOKABLE void serialWorkThreadPool_4::slotWork()
{
    qDebug()<<"55555555555555555555555555555555555555555555";

}
void serialWorkThreadPool_4::slotWorkData(QByteArray data)
{
    QStringList list = publicClass::getInstance()->ByteArrayToHexStr(data).split(" ");

//    ui->textEdit_recv->append("DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) );

//    for(int i =5;i<list.size()-1;i++){

//        double f;
//        bool ok;
//        f = list.at(i).toInt(&ok, 16);
//        ui->textEdit_recv->append(list.at(i)+ "recv dec data:"+QString::number(f));

//    }
 qDebug()<<"DATA LEN:"+QString::number(list.size())+"DATA RECV:"+publicClass::getInstance()->ByteArrayToHexStr(data) ;
    //    float val;
    //    unsigned char hexdata[4]={0x00,0x00,0x48,0x41};
    //    memcpy(&val,hexdata,4);
}
