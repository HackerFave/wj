#ifndef QTHTTPFORS_H
#define QTHTTPFORS_H

//#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
namespace Ui {
class QtHttpForS;
}

class QtHttpForS : public QWidget
{
    Q_OBJECT

public:
    explicit QtHttpForS(QWidget *parent = nullptr);
    ~QtHttpForS();
    int SumNums(QVector<int> nums);

protected slots:
    void newConnectionSlot();
    void errorStringSlot();
    void sendMsg();
private:
    Ui::QtHttpForS *ui;
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;
    QString m_SocketInfo;
};

#endif // QTHTTPFORS_H
