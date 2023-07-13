#include "viewShowForm.h"
#include "ui_viewShowForm.h"

viewShowForm::viewShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewShowForm)
{
    ui->setupUi(this);
    //----------------波形相关设置-------------------//
//    auto graph =ui->plot1->addGraph();

//    graphMap["current"] =graph;//电流
//    graph->setName("current");//电流
//    graph->setPen(QPen(QColor(255,0,0)));

//    graph =ui->plot1->addGraph();
//    graphMap["voltage"] =graph;//电压
//    graph->setName("voltage");
//    graph->setPen(QPen(QColor(0,255,0)));

//    graph =ui->plot1->addGraph();
//    graphMap["speed"] =graph;//转速
//    graph->setName("speed");//转速
//    graph->setPen(QPen(QColor(0,0,255)));

//    ui->plot1->xAxis->setRange(0,100);
//    ui->plot1->yAxis->setRange(-1,3);

//    ui->plot1->axisRect()->setupFullAxesBox(true);
//    ui->plot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

//    ui->plot1->legend->setVisible(true);
//    ui->plot1->legend->setIconSize(QSize(100,20));

}

viewShowForm::~viewShowForm()
{
    delete ui;
}

void viewShowForm::on_checkBox_Rpm_stateChanged(int arg1)
{

}

void viewShowForm::on_checkBox_Volt_stateChanged(int arg1)
{

}

void viewShowForm::on_checkBox_Current_stateChanged(int arg1)
{

}
