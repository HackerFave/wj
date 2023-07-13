#include "widget.h"
#include "ui_widget.h"
#include <functional>
#include <QtDebug>
std::mutex Widget::_mutex ;
Widget* Widget::P_stac = nullptr;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    _FUN =  static_cast<funcCan*>(init()) ;
    auto Fun = std::bind(call,placeholders::_1);
    _FUN->regeditCallBack(Fun);
    _FUN->regeditCallBack(callbmq);
    initPoint();
    _groupBtn.addButton(ui->radioButton_up);
    _groupBtn.addButton(ui->radioButton_back);
    ui->radioButton_up->setChecked(true);
    p_func=  static_cast<func*>(initchassis());
}

Widget::~Widget()
{
    Release(_FUN);
    delete ui;
}


//初始化指针
void Widget::initPoint()
{

    P_stac = this;
}
void Widget::setValue_bmq(std::string com, int8_t valueFBL,int32_t valueDanquan,int32_t valueDuoquan)
{
    ui->label_bmq->setText(QString("com: %1").arg(valueDanquan));//编码器角度换算 valueDanquan *360/524287
}
void  Widget::callbmq(std::string com,int8_t valueFBL, int32_t valueDanquan,int32_t valueDuoquan )
{
    P_stac->setValue_bmq(com, valueFBL,  valueDanquan, valueDuoquan);

}
void  Widget:: call(CAN_OBJ *data)
{
    std::lock_guard<std::mutex> lgd(_mutex);
    CAN_OBJ obj;
    memmove(&obj,data,sizeof (CAN_OBJ));
    int id = obj.ID;
    switch (id) {
    case 0x582:{
        int32_t value;
        int16_t index;
        memmove(&index,&data->Data[1],2);
        memmove(&value,&data->Data[4],4);
        //        qDebug()<<QString("[ID:0X%1]").arg(QString::number(id,16).toUpper())
        //               <<QString("[INDEX:0X%1]").arg(QString::number(index,16).toUpper())
        //              <<"DATA:"<<value;
        //        P_stac->setValue_YK(value);
        break;
    }

    default:
        break;
    }

}
//右转 value为负
void Widget::on_pushButton_zhengzhuan_clicked()
{
    int32_t value =-ui->lineEdit_value->text().toInt();//300左右
    _FUN->turnMove(value);
}
//左转
void Widget::on_pushButton_fanzhuan_clicked()
{
    int32_t value = ui->lineEdit_value->text().toInt();
    _FUN->turnMove(value);
}
void Widget::slotRecvData(UINT id, BYTE *data)
{
    //    qDebug()<< QString("[ID: %1]").arg(QString::number(id,16).toUpper())+ publicClass::getInstance()->Byte_16(data,8).simplified();

    if(id == 0x582){
        QString dataStr = publicClass::getInstance()->Byte_16(data,8).simplified().simplified();
        dataStr = dataStr.split(" ").at(4)+" "+dataStr.split(" ").at(5)+" "+dataStr.split(" ").at(6)+" "+dataStr.split(" ").at(7);
        QByteArray data = QByteArray::fromHex(dataStr.toLatin1());
        //        qDebug()<<dataStr<<"XXXXXXXXXXXXXXXXXXXXXX";
        int32_t value;
        memmove(&value,data.data(),data.size());
        ui->label_bmq->setText(QString::number(value));
    }
}

void int32Arr2Bytes(int32_t* Arr, unsigned int len, unsigned char* byteBufOut)
{
    unsigned int pos = 0;
    unsigned char * temp = nullptr;
    int k = 0;
    for (int i = 0; i < len; i++) {
        temp = (unsigned char *)(&Arr[i]);

        for (k = 0; k < 4; k++) {
            byteBufOut[pos++] = *temp++;
        }
    }
}
void Widget::on_horizontalSlider_sliderMoved(int position)
{
    p_func->throttleMoved(position);
    ui->lineEdit->setText(QString::number(position));

}
//前进
void Widget::on_radioButton_up_clicked()
{
    p_func->frontMove();
}
//后退
void Widget::on_radioButton_back_clicked()
{
    p_func->backMove();

}
void Widget::setValue(int32_t value)
{
    ui->label_bmq->setText(QString::number(value));
}

void Widget::on_pushButton_back_clicked()
{

    p_func->throttleMoved(1500);
}

void Widget::on_pushButton_front_clicked()
{

    p_func->throttleMoved(1500);
}
void Widget::on_pushButton_stop_clicked()
{
     p_func->stopMove();
}
