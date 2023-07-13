#ifndef CTRLOBJ_H
#define CTRLOBJ_H

#include <QWidget>
#include <QThread>

#include "ECanVci.h"
#include "can.h"
namespace Ui {
class ctrlobj;
}

class ctrlobj : public QWidget
{
    Q_OBJECT

public:
    explicit ctrlobj(QWidget *parent = 0);
    ~ctrlobj();
    int hex_str_to_int(unsigned char *ch);
    unsigned int hex_str_to_uint(char *ch_id);
    bool mconnect=false;
    byte mbaud;
private slots:

    void on_bt_Connected_clicked();

    void on_BT_Send_clicked();
    void deal_my_string(QString str);//子线程结束槽函数

private:
    Ui::ctrlobj *ui;
    Thread *MyCANControlThread;//定义类指针

};
extern bool  IsOpenFlag;
#endif // CTRLOBJ_H
