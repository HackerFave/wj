#ifndef HTTPMETHORD_H
#define HTTPMETHORD_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
class httpMethord : public QObject
{
    Q_OBJECT
public:
    explicit httpMethord(QObject *parent = nullptr);
    ~httpMethord();
    int SumNums(QVector<int> nums);
signals:

protected slots:
    void slotNewConnectionSlot();
    void slotErrorStringSlot();
    void slotSendMsg();
private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QString m_SocketInfo;

};

#endif // HTTPMETHORD_H

