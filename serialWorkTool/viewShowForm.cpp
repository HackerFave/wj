#include "viewShowForm.h"
#include "ui_viewShowForm.h"

viewShowForm::viewShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewShowForm)
{
    ui->setupUi(this);
    //----------------波形相关设置-------------------//
    auto graph =ui->plot1->addGraph();
    graphMap["current"] =graph;//电流
    graph->setName("current");//电流
    QPen pen(QColor(255,0,0));
    pen.setWidth(3);//设置线宽
    graph->setPen(pen);
    graph =ui->plot1->addGraph();
    graphMap["voltage"] =graph;//电压
    graph->setName("voltage");
    graph->setPen(QPen(QColor(0,255,0)));

    graph =ui->plot1->addGraph();
    graphMap["speed"] =graph;//转速
    graph->setName("speed");//转速
    graph->setPen(QPen(QColor(0,0,255)));

    ui->plot1->xAxis->setRange(-1,500);
    ui->plot1->yAxis->setRange(-10,100);

    ui->plot1->axisRect()->setupFullAxesBox(true);
    ui->plot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    ui->plot1->legend->setVisible(true);
    ui->plot1->legend->setIconSize(QSize(50,20));
    ui->plot1->legend->setTextColor(Qt::white);
    ui->plot1->setBackground(QBrush(Qt::black));
    QColor color("#ffaaff");
    color.setAlpha(50);

    ui->plot1->legend->setBrush(QBrush(color));

    ui->plot1->legend->setBorderPen(QPen(Qt::DashDotLine));
    //设置坐标文本颜色
    ui->plot1->xAxis->setTickLabelColor(Qt::white);
    ui->plot1->yAxis->setTickLabelColor(Qt::white);
    //设置坐标名称文本颜色
    ui->plot1->xAxis->setLabelColor(Qt::white);
    ui->plot1->yAxis->setLabelColor(Qt::white);
    //设置坐标轴颜色
    ui->plot1->xAxis->setBasePen(QPen(Qt::white));
    ui->plot1->xAxis->setTickPen(QPen(Qt::white));
    //    Init();
    //    connect(&_timer,SIGNAL(timeout()),this,SLOT(slotDraw()));
    _timeStamp = QDateTime::currentMSecsSinceEpoch();
    ui->pushButton->setVisible(false);
    ui->label->setVisible(false);
    ui->kValue->setVisible(false);
    ui->formula->setVisible(false);
    ui->horizontalSlider->setVisible(false);

}

viewShowForm::~viewShowForm()
{
    x.squeeze();
    y.squeeze();
    delete ui;
}

//void viewShowForm::on_checkBox_Rpm_stateChanged(int arg1)
//{
//    switch (arg1) {
//    case 0:{

//        break;
//    }
//    case 1:{

//        break;
//    }
//    default:
//        break;
//    }
//}

//void viewShowForm::on_checkBox_Volt_stateChanged(int arg1)
//{
//    switch (arg1) {
//    case 0:{

//        break;
//    }
//    case 1:{

//        break;
//    }
//    default:
//        break;
//    }
//}

//void viewShowForm::on_checkBox_Current_stateChanged(int arg1)
//{
//    switch (arg1) {
//    case 0:{

//        break;
//    }
//    case 1:{

//        break;
//    }
//    default:
//        break;
//    }
//}
double viewShowForm::GetX()
{
    return (QDateTime::currentMSecsSinceEpoch()-_timeStamp)/1000;
}

//实时更新波形数据（注意：此处节点信息波形只做示范例子，具体要显示的内容根据自己测试内容仿照修改）
void viewShowForm::slotPlotViewUpdate(UINT id, BYTE *data)
{

    if(id==0x581){
        QString datastr = publicClass::getInstance()->Byte_16(data,8);
        QString ids = datastr.split(" ").at(1) +" "+ datastr.split(" ").at(2);
        QString valuestr = datastr.split(" ").at(4) +" "+ datastr.split(" ").at(5)+" "+ datastr.split(" ").at(6)+" "+ datastr.split(" ").at(7);
        QByteArray array = datastr.toLatin1();
        int16_t index;
        QByteArray byte = QByteArray::fromHex(ids.toLatin1());
        memcpy(&index,byte.data(),byte.size());
        //    qDebug()<<"[recv:]"<<publicClass::getInstance()->Byte_16(data,8) ;
        switch(index)
        {
        case 12302://模块温度
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_module_temperature->setText(QStringLiteral("模块温度:%1℃").arg(value));
            ui->plot1->replot();
            break;
        }
        case 12293://电机电流
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int16_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_Current->setText(QStringLiteral("电机电流:%1A").arg(value*0.1));
            graphMap["current"]->addData(GetX(), value);
            ui->plot1->replot();
            break;
        }
        case 12301://线圈温度
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_coil_temperature->setText(QStringLiteral("线圈温度:%1℃").arg(value));
            //        graphMap["current"]->addData(GetX(),value.toInt());

            ui->plot1->replot();
            break;
        }
        case /*12297*/0X3009://母线电压
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_Volt->setText(QStringLiteral("母线电压:%1V").arg(value));
            graphMap["voltage"]->addData(GetX(),value);
            ui->plot1->replot();
            break;
        }
        case 12298://告警码
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            //            int32_t value;
            //            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_error->setText(QStringLiteral("告警码:%1").arg(/*value*/datastr));
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        case 12288://转速
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int16_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_Rpm->setText(QStringLiteral("转速:%1rpm").arg(value));
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        case 12296://第一位置编码器
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_bainmaqi1->setText(QStringLiteral("第一位置编码器:%1").arg(value));
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        case 24676://编码器绝对位置
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_jueduiweizhi->setText(QStringLiteral("编码器绝对位置:%1").arg(value));
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        case 24698://目标位置
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_mubiaoweizhi->setText(QStringLiteral("目标位置:%1").arg(value));
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        case 24675://当前电机位置
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_dianjiweizhi->setText(QStringLiteral("当前电机位置:%1").arg(value));
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        case 12303://第二位置编码器
        {
            QByteArray valuebyte = QByteArray::fromHex(valuestr.toLatin1());
            int32_t value;
            memcpy(&value,valuebyte.data(),valuebyte.size());
            ui->label_bianmaqi2->setText(QStringLiteral("第二位置编码器:%1").arg(value));
            //        publicClass::getInstance()->setValueIni("index/limit",value);
            //                graphMap["current"]->addData(GetX(),hex2Float(data));

            //        ui->plot1->replot();
            break;
        }
        default:
            break;
        }
    }
}
void viewShowForm::on_checkBox_allShow_clicked(bool checked)
{

    graphMap["speed"]->setVisible(checked);
    graphMap["voltage"]->setVisible(checked);
    graphMap["current"]->setVisible(checked);
}
//初始化
void viewShowForm::Init()
{
    //设置背景颜色为白色
    ui->plot1->setBackground(QBrush(Qt::black));

    //设置网格为灰色虚线
    ui->plot1->xAxis->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));
    ui->plot1->yAxis->grid()->setPen(QPen(QColor(180,180,180),1,Qt::PenStyle::DashLine));

    //显示子网格线
    ui->plot1->xAxis->grid()->setSubGridVisible(false);
    ui->plot1->yAxis->grid()->setSubGridVisible(false);

    //设置坐标轴颜色
    ui->plot1->xAxis->setBasePen(QPen(Qt::black));
    ui->plot1->yAxis->setBasePen(QPen(Qt::black));

    //设置坐标轴终点图案为箭头
    ui->plot1->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot1->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    //设置坐标轴刻度数目
    ui->plot1->xAxis->ticker()->setTickCount(5);
    ui->plot1->yAxis->ticker()->setTickCount(5);

    //设置坐标轴范围
    ui->plot1->xAxis->setRange(-3.1,5.1);
    ui->plot1->yAxis->setRange(-2,3);

    //设置滑动条初始值为0
    ui->horizontalSlider->setValue(0);
    //设置滑动条范围为0-10000
    ui->horizontalSlider->setRange(0,10000);

    //设置画笔属性
    pen.setColor(Qt::red);
    pen.setWidthF(1);

    //添加曲线
    ui->plot1->addGraph();

    //设置曲线画笔
    ui->plot1->graph(0)->setPen(pen);


    //添加曲线
    ui->plot1->addGraph();
    QPen pen(QColor(0,0,255));
    pen.setWidth(2);
    //设置曲线画笔
    ui->plot1->graph(1)->setPen(pen);
}

//绘制曲线
void viewShowForm::Draw()
{
    ui->plot1->graph(0)->data()->clear();
    for(int i = 0;i < 400;i++){
        x.append(static_cast<qreal>(i) / 100 - 1.99);
        y.append(qPow(qAbs(x[i]),2.0/3.0) + 0.9*qPow((4-qPow(x[i],2)),0.5)*sin(k*3.14*x[i]));
    }
    ui->plot1->graph(0)->setData(x,y);   //关联数据
    ui->plot1->replot(QCustomPlot::rpQueuedReplot);
    x.clear();
    y.clear();

    ui->plot1->graph(1)->data()->clear();
    for(int i = 0;i < 400;i++){
        x1.append((static_cast<qreal>(i) / 100 - 1.99)+2);
        y1.append(qPow(qAbs(x1[i]),2.0/3.0) + 0.9*qPow((4-qPow(x1[i],2)),0.5)*sin(k*3.14*x1[i]));
    }
    ui->plot1->graph(1)->setData(x1,y1);   //关联数据
    ui->plot1->replot(QCustomPlot::rpQueuedReplot);
    x1.clear();
    y1.clear();

}

void viewShowForm::on_horizontalSlider_sliderMoved(int position)
{
    qDebug()<<position<<"****************************";
    k = static_cast<qreal>(position)/100;
    ui->kValue->clear();
    ui->formula->clear();
    ui->kValue->setText(QString("%1").arg(k));
    ui->formula->setText(QStringLiteral("f(x) = x^(2/3) + [0.9*(3.3 - x^2)^0.5] * sin(%1Πx)").arg(k));
    Draw();
}

void viewShowForm::on_pushButton_clicked()
{
    QColor c = QColorDialog::getColor(Qt::red);
    if(c.isValid()){
        pen.setColor(c);
        ui->plot1->graph(0)->setPen(pen);
        ui->plot1->replot(QCustomPlot::rpQueuedReplot);
    }

    _timer.start(100);
}



void viewShowForm::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.drawPoint(m_x, m_y);
}

void viewShowForm::timerEvent(QTimerEvent *)
{
    if (m_t > 1000)
    {
        update();
        m_t = 0;
    }
    m_x = 16 * m_k * sin(m_k*m_t)*sin(m_k*m_t)*sin(m_k*m_t);
    m_y = 13 * m_k * cos(m_k*m_t) - 5 * m_k * cos(2 * m_k * m_t) - 2 * m_k * cos(3 * m_k * m_t) - cos(4 * m_k * m_t);
    m_x += this->width() / 2;
    m_y -= this->height() / 2;
    m_y *= -1;
    update(m_x,m_y,1,1);
    m_t += 0.1;

}
void viewShowForm::slotDraw()
{
    static int i = 0;
    if(300 == i++){
        on_horizontalSlider_sliderMoved(4000);
        _timer.stop();
        return;
    }
    ui->label->setText(QString::number(i));
    on_horizontalSlider_sliderMoved(qrand()%10000);

}

void viewShowForm::on_pushButton_reversal_clicked()
{
    VCI_CAN_OBJ sendbuf;
    bool ok;
    QString id = ("601");
//    QList<QString> sendMsg;
//    sendMsg.clear();
    //    sendMsg.append(QString("2F 60 60 00 03 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    //    sendMsg.append(QString("2B 40 60 00 0f 00 00 00"));

    int32_t  ss2 = -ui->lineEdit_suduRpm->text().simplified().toInt()*10; //设置速度

    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    QByteArray byArr2((const char*)out2,4);

    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    QString sudu = QString("23 FF 60 00 %1").arg(ssss2);
//    sendMsg.append(sudu);
    QString RowStr;
//    for(int i=0;i<1;i++){
        sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf.ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf.SendType=1;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        qDebug()<<sendbuf.DataLen<<sudu<<"xxxxxxxxxxxxxxxxxxxxxxx";
        publicClass::getInstance()->Str2CharSplitBlank(sudu,sendbuf.Data,&sendbuf.DataLen);
        ULONG flag;

        flag=VCI_Transmit(4,0,0,&sendbuf,1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {

        }
        else {
            qDebug()<<publicClass::getInstance()->Byte_16(sendbuf.Data,8)<<"xxxxxxxxxxxxxxxx";
        }
//    }
}
/*
 * @brief   :速度模式使能
 * @author  :tanchuang
 * @date    :2023.04.04
 */
void viewShowForm::on_pushButton_enable_clicked()
{
    VCI_CAN_OBJ sendbuf[6];
    bool ok;
    QString id = "601";
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 60 60 00 03 00 00 00"));//速度模式
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0f 00 00 00"));
    //    sendMsg.append(QString("23 FF 60 00 18 FC FF FF"));

    QString RowStr;
    for(int i=0;i<5;i++){
        sendbuf[i].ExternFlag=0 ;
        sendbuf[i].RemoteFlag=0;

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=0;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {
        }
        else {
            qDebug()<<publicClass::getInstance()->Byte_16(sendbuf[i].Data,8)<<"xxxxxxxxxxxxxxxx";
        }
    }
}

void viewShowForm::on_pushButton_foreward_clicked()
{
    VCI_CAN_OBJ sendbuf;
    bool ok;
    QString id = "601";

    int32_t  ss2 = ui->lineEdit_suduRpm->text().simplified().toInt()*10; //设置速度

    unsigned char out2[4] ={};
    publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
    QByteArray byArr2((const char*)out2,4);

    QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
    QString sudu = QString("23 FF 60 00 %1").arg(ssss2);

        sendbuf.ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf.RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf.ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf.ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf.ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf.SendType=1;
        sendbuf.TimeFlag=0;
        sendbuf.TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sudu,sendbuf.Data,&sendbuf.DataLen);
        ULONG flag;
        flag=VCI_Transmit(4,0,0,&sendbuf,1); //调用动态链接库发送函数
        if(flag<1)  //发送不正常
        {
        }
        else {
        }


}

void viewShowForm::on_pushButton_enable_weizhimoshi_clicked()
{
    if(ui->comboBox_xiangduiweizhi->currentIndex()==0){
        VCI_CAN_OBJ sendbuf[10];
        bool ok;
        QString id = "601";
        QList<QString>   sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//相对位置模式


        int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
        unsigned char out[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
        QByteArray byArr((const char*)out,4);
        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);
        sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms


        int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
        unsigned char out1[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
        QByteArray byArr1((const char*)out1,4);
        QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);
        sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms
        int32_t  ssangle = 0;

#if LIMIT

        if(abs(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())>num){

            //            if(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt()>0){
            //                ssangle = (32768*101* num)/360; //设置角度
            //            }
            //            else {
            //                ssangle = (32768*101* (-num))/360; //设置角度
            //            }
            QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前角度超过限位"));
            return;
        }
        else {
            ssangle = (32768*101* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())/360; //设置角度
        }

#else
        ssangle = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
#endif
        unsigned char outangle[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
        QByteArray byArrangle((const char*)outangle,4);

        QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

        QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
        sendMsg.append(jiaodu);//设置转动角度

        int32_t  ss2 =  ui->lineEdit_weizhiRpm->text().simplified().toInt()*10;
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);


        sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));

        QString RowStr;
        for(int i=0;i<10;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            flag=VCI_Transmit(4,0,1,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            _sleep(10);
            if(flag<1)  //发送不正常
            {

            }
            else {

            }
        }
    }
    else {
        VCI_CAN_OBJ sendbuf[10];
        bool ok;
        QString id = ("601");
        QList<QString>   sendMsg;
        sendMsg.clear();
        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式

        int32_t ss = ui->lineEdit_jiasushijian->text().simplified().toInt();
        unsigned char out[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss,4,out);
        QByteArray byArr((const char*)out,4);

        QString ssss =  publicClass::getInstance()->Byte_16((unsigned char *)byArr.data(),4);

        sendMsg.append(QString("23 83 60 00 ")+ssss); //设置加速时间 ms

        int32_t  ss1 =  ui->lineEdit_jiansushijian->text().simplified().toInt();
        unsigned char out1[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss1,4,out1);
        QByteArray byArr1((const char*)out1,4);

        QString ssss1 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr1.data(),4);


        sendMsg.append(QString("23 84 60 00 ")+ssss1); //设置减速时间 ms

        //        sendMsg.append(QString("23 7A 60 00 10 27 00 00"));//设置目标位置 一圈32768 除以减速比1/101

        //        sendMsg.append(QString("23 7A 60 00 00 00 00 00"));//设置转动角度

        int32_t  ssangle = 0;

#if LIMIT
        if(abs(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())>num){

            //            if(ui->lineEdit_zhuandongjiaodu->text().simplified().toInt()>0){
            //                ssangle = (32768*101* num)/360; //设置角度
            //            }
            //            else {
            //                ssangle = (32768*101* (-num))/360; //设置角度
            //            }
            QMessageBox::warning(this,QStringLiteral("注意!"),QStringLiteral("当前角度超过限位"));
            return;
        }
        else {
            ssangle = (32768*101* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt())/360; //设置角度
        }

#else
        ssangle = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
#endif
        unsigned char outangle[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ssangle,4,outangle);
        QByteArray byArrangle((const char*)outangle,4);

        QString ssssangle =  publicClass::getInstance()->Byte_16((unsigned char *)byArrangle.data(),4);

        QString jiaodu = QString("23 7A 60 00 %1").arg(ssssangle);
        sendMsg.append(jiaodu);//设置转动角度

        int32_t  ss2 =  ui->lineEdit_weizhiRpm->text().simplified().toInt()*10;
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
        sendMsg.append(QString("23 81 60 00 ")+ssss2);//设置速度转速 rpm
        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

        QString RowStr;
        for(int i=0;i<10;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;
            //            qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
            //                   <<"sendMsg"<<sendMsg;
            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));

            _sleep(10);
            if(flag<1)  //发送不正常
            {
            }
            else {

            }
        }
    }
}

/*
 * @brief   :原点定位
 * @author  :tanchuang
 * @date    :2023.04.04
 */
void viewShowForm::on_pushButton_setyuandian_clicked()
{
    VCI_CAN_OBJ sendbuf[7];
    bool ok;
    QString id = ("601");
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2F 98 60 00 23 00 00 00"));//速度模式
    sendMsg.append(QString("2F 60 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
    sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

    //    sendMsg.append(QString("23 FF 60 00 E8 03 00 00"));
    QString RowStr;
    for(int i=0;i<7;i++){
        sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
        sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

        if((sendbuf->ExternFlag)==1)//帧格式，远程帧
        {
            sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
        }
        else//标准帧格式
        {
            sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
        }

        sendbuf[i].SendType=1;
        sendbuf[i].TimeFlag=0;
        sendbuf[i].TimeStamp=0;
        publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
        ULONG flag;
        flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
        _sleep(10);
        if(flag<1)  //发送不正常
        {

        }
        else {

        }
    }
}

void viewShowForm::on_pushButton_stopEnable_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    bool ok;
    QString id = ("601");
    QList<QString>   sendMsg;
    sendMsg.clear();
    sendMsg.append(QString("2B 40 60 00 02 00 00 00"));
    QString RowStr;
    sendbuf->ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf->RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

    if((sendbuf->ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf->ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
    }
    else//标准帧格式
    {
        sendbuf->ID=(id.toUInt(&ok,16))&0x7FF;
    }

    sendbuf->SendType=1;
    sendbuf->TimeFlag=0;
    sendbuf->TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg[0],sendbuf->Data,&sendbuf->DataLen);
    ULONG flag;
    //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
    //           <<"sendMsg"<<sendMsg;
    flag=VCI_Transmit(4,0,0,sendbuf,1); //调用动态链接库发送函数
    //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
    if(flag<1)  //发送不正常
    {

    }
    else {

    }


}

void viewShowForm::on_pushButton_init_clicked()
{
    VCI_CAN_OBJ sendbuf[1];
    QString id = ("601");
    bool ok;
    QString sendMsg="10 10";//发送数据
    QString RowStr;
    sendbuf->ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
    sendbuf->RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

    if((sendbuf->ExternFlag)==1)//帧格式，远程帧
    {
        sendbuf->ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
    }
    else//标准帧格式
    {
        sendbuf->ID=(id.toUInt(&ok,16))&0x7FF;
    }

    sendbuf->SendType=1;
    sendbuf->TimeFlag=0;
    sendbuf->TimeStamp=0;
    publicClass::getInstance()->Str2CharSplitBlank(sendMsg,sendbuf->Data,&sendbuf->DataLen);
    ULONG flag;
    //    qDebug()<<"m_DevType:"<<m_DevType<<"m_DevIndex:"<<m_DevIndex<<"m_CanIndex:"<<m_CanIndex
    //           <<"sendMsg"<<sendMsg;
    flag=VCI_Transmit(4,0,0,sendbuf,1); //调用动态链接库发送函数
    //    emit  signalSendCanBuf(sendbuf,/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
    if(flag<1)  //发送不正常
    {

    }
    else {

    }
}

void viewShowForm::on_pushButton_zhuandong_clicked()
{

    if(ui->comboBox_xiangduiweizhi->currentIndex()==0){ // 相对位置
        VCI_CAN_OBJ sendbuf[3];
        bool ok;
        QString id = "601";
        QList<QString>   sendMsg;
        sendMsg.clear();
        int32_t  ss2 = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);
        //        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//相对位置模式
        QString jiaodu = QString("23 7A 60 00 %1").arg(ssss2);
        sendMsg.append(jiaodu);//设置转动角度
        //        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 4F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 5F 00 00 00"));
        for(int i=0;i<3;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }

    }
    else{//绝对位置
        VCI_CAN_OBJ sendbuf[3];
        bool ok;
        QString id = "601";
        QList<QString>  sendMsg;
        sendMsg.clear();
        int32_t  ss2 = (32768*101/360)* ui->lineEdit_zhuandongjiaodu->text().simplified().toInt(); //设置角度
        unsigned char out2[4] ={};
        publicClass::getInstance()->int32Arr2Bytes(&ss2,4,out2);
        QByteArray byArr2((const char*)out2,4);

        QString ssss2 =  publicClass::getInstance()->Byte_16((unsigned char *)byArr2.data(),4);

        //        sendMsg.append(QString("2F 60 60 00 01 00 00 00"));//绝对位置模式
        QString jiaodu = QString("23 7A 60 00 %1").arg(ssss2);
        sendMsg.append(jiaodu);//设置转动角度
        //        sendMsg.append(QString("2B 40 60 00 80 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 06 00 00 00"));
        //        sendMsg.append(QString("2B 40 60 00 07 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 0F 00 00 00"));
        sendMsg.append(QString("2B 40 60 00 1F 00 00 00"));

        for(int i=0;i<3;i++){
            sendbuf[i].ExternFlag=0 ;//static_cast<BYTE>(ui->comboBox_format->currentIndex()); //帧格式 (扩展帧1 标准帧0 )
            sendbuf[i].RemoteFlag=0;//static_cast<BYTE>(ui->comboBox_frame_type->currentIndex());  //帧类型 （数据帧0 远程帧1）

            if((sendbuf->ExternFlag)==1)//帧格式，远程帧
            {
                sendbuf[i].ID =(id.toUInt(&ok,16)); //&0x1FFFFFFF;
            }
            else//标准帧格式
            {
                sendbuf[i].ID=(id.toUInt(&ok,16))&0x7FF;
            }

            sendbuf[i].SendType=1;
            sendbuf[i].TimeFlag=0;
            sendbuf[i].TimeStamp=0;
            publicClass::getInstance()->Str2CharSplitBlank(sendMsg[i],sendbuf[i].Data,&sendbuf[i].DataLen);
            ULONG flag;

            flag=VCI_Transmit(4,0,0,&sendbuf[i],1); //调用动态链接库发送函数
            //            emit  signalSendCanBuf(&sendbuf[i],/*sendbuf->DataLen*/sizeof (VCI_CAN_OBJ));
            _sleep(10);
            if(flag<1)  //发送不正常
            {
                //             emit signalError("error");

            }
            else {

            }
        }
    }
}
