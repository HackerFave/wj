#include "sqlTruncateThread.h"
#include <QDebug>
#define TIME_OUT 60*60/**24*/ //1小时
#define SQL_SECONDS 60*60*24 //1天
sqlTruncateThread::sqlTruncateThread()
{

}
Q_INVOKABLE void sqlTruncateThread::startWork()
{
    _isStop = false;
}
Q_INVOKABLE void sqlTruncateThread::stopWork()
{
    _isStop = true;
}
Q_INVOKABLE void sqlTruncateThread::slotPostWork()
{

}
Q_INVOKABLE void sqlTruncateThread::slotPostAppendData(const void * f,size_t len,int id)
{

}
Q_INVOKABLE void sqlTruncateThread::slotSubAckAppendData(const void*f,int id,const uint32_t &len)
{

}
Q_INVOKABLE void sqlTruncateThread::slotWork()
{
    while (1)
    {
        if(_isStop){
            return;
        }else{
            qInfo()<<QStringLiteral("【启动数据库检查线程】");
            QString table_name = "testtable";
            QString dateKey = "date";
            QSqlQuery * ret = nullptr;
            SqlMethod::sqlmethod_instance()->getsqloperationinstance("del")->delRecord(table_name, dateKey,SQL_SECONDS, &ret);
        }
        QThread::sleep(TIME_OUT);
    }
}
