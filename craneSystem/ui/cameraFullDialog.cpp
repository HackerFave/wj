#include "cameraFullDialog.h"
#include "ui_cameraFullDialog.h"
#include <QtDebug>
cameraFullDialog::cameraFullDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cameraFullDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_ShowModal);

}

cameraFullDialog::~cameraFullDialog()
{
    delete ui;
}
void cameraFullDialog::addWin(QWidget * w)
{
    while(ui->gridLayout_camera->count()){
        QWidget *pWidget = ui->gridLayout_camera->itemAt(0)->widget();//循环每次取第一个控件，依次删除下去
        pWidget->setParent(NULL);
        ui->gridLayout_camera->removeWidget(pWidget);
        delete pWidget;
    }
    ui->gridLayout_camera->addWidget(w);
}
void cameraFullDialog::closeEvent(QCloseEvent *event)
{

    emit signalCameraMin();
}

