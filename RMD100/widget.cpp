#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qRegisterMetaType<int32_t>("int32_t");
    P_func = new func;
    initJasudu();
    connect(&_timer,&QTimer::timeout,this,&Widget::slotUpdateTimer);
    ui->pushButton_fanzhuan->setVisible(false);

}

Widget::~Widget()
{
    on_pushButton_stop_clicked();
    delete ui;
}

void Widget::initJasudu()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0x34;
    head[2] = 0x02;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;
    //    QString databody = ui->lineEdit_body->text().simplified();

    int32_t valuebody = /*10*100*100*/1800*100;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,4);

    body[4] = pbody;

    uint8_t data[10] = {};

    memmove(data,head,5);
    memmove(&data[5],body,5);
    QString checkStr = "3E3402";
    P_func->writeData(data,10,checkStr);
}

void Widget::on_pushButton_zhengzhuan_clicked()
{
    _timer.start(8000);

    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0xa2;
    head[2] = 0x02;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;

    int32_t valuebody = -/*10*100*100*/180*100;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

    body[4] = pbody;

    uint8_t data[10] = {};

    memmove(data,head,5);
    memmove(&data[5],body,5);
    QString checkStr = "3EA202";
    P_func->writeData(data,10,checkStr);

}

void Widget::on_pushButton_fanzhuan_clicked()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0xa2;
    head[2] = 0x02;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;

    int32_t valuebody = /*10*100*100*/180*100;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

    body[4] = pbody;

    uint8_t data[10] = {};

    memmove(data,head,5);
    memmove(&data[5],body,5);
    QString checkStr = "3EA202";
    P_func->writeData(data,10,checkStr);
}

void Widget::on_pushButton_stop_clicked()
{
    uint8_t head[5]={};
    head[0] = 0x3e;
    head[1] = 0xa2;
    head[2] = 0x02;
    head[3] = 0x04;

    //速度环控制
    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    head[4] = p;

    int32_t valuebody = 0;
    uint8_t body[5]={};
    memmove(body,&valuebody,4);
    unsigned char pbody = publicClass::getInstance()->cllc_checkSum((unsigned char *)body,/*bytebody.size()*/4);

    body[4] = pbody;

    uint8_t data[10] = {};

    memmove(data,head,5);
    memmove(&data[5],body,5);
    QString checkStr = "3EA202";
    P_func->writeData(data,10,checkStr);

    _timer.stop();
}
void Widget::slotUpdateTimer()
{
    //    uint8_t head[5]={};
    //    head[0] = 0x3e;
    //    head[1] = 0x9c;
    //    head[2] = 0x01;
    //    head[3] = 0x00;

    //    //速度环控制
    //    unsigned char p = publicClass::getInstance()->cllc_checkSum(head,4);

    //    head[4] = p;

    //    P_func->writeData(head,5,"");

    static int num = 0;

    if(num == 0){
        on_pushButton_fanzhuan_clicked();
        num = 1;
    }
    else if (num == 1) {
        on_pushButton_zhengzhuan_clicked();
        num = 0;
    }
}
