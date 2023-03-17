#ifndef HTTPMETHORD_H
#define HTTPMETHORD_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#define PORT 8080
class httpMethord : public QObject
{
    Q_OBJECT
public:
    explicit httpMethord(QObject *parent = nullptr);
    ~httpMethord();
signals:

protected slots:
    void slotNewConnectionSlot();
    void slotErrorStringSlot();
    void slotSendMsg();
    void slotconnection();
private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QString m_SocketInfo;


    qint64 bytesAvailable() const;

};

#endif // HTTPMETHORD_H

