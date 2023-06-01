#ifndef QTHTTPFORC_H
#define QTHTTPFORC_H

#include <QWidget>
#include <QTcpSocket>
#include <QButtonGroup>
namespace Ui {
class QtHttpForC;
}

class QtHttpForC : public QWidget
{
    Q_OBJECT

public:
    explicit QtHttpForC(QWidget *parent = nullptr);
    ~QtHttpForC();

private slots:
    void on_pushButton_clicked();
private:
    Ui::QtHttpForC *ui;
    QButtonGroup *m_Buttongroup;
    QTcpSocket *m_Socket;
};

#endif // QTHTTPFORC_H
