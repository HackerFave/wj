#include "cameraDisplayForm.h"
#include "ui_cameraDisplayForm.h"
#include <QtDebug>

cameraDisplayForm::cameraDisplayForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cameraDisplayForm)
{
    ui->setupUi(this);
    for(int i = 0; i<4 ; ++i){
        _mapDisplay.insert(i,new baseCameraForm);
        connect(_mapDisplay.value(i),SIGNAL(signalCameraFormId(const QString&)),
                this,SLOT(slotCameraFormId(const QString&)));
    }
    initUi();
}

cameraDisplayForm::~cameraDisplayForm()
{
    delete ui;
}
void cameraDisplayForm::initUi()
{
    P_cameraFullDialog = new cameraFullDialog;
    connect(P_cameraFullDialog,SIGNAL(signalCameraMin()),this,SLOT(slotCameraMin()));
    _mapDisplay.value(0)->setClassName("0");
    _mapDisplay.value(1)->setClassName("1");
    _mapDisplay.value(2)->setClassName("2");
    _mapDisplay.value(3)->setClassName("3");
    ui->gridLayout_camera_1->addWidget(_mapDisplay.value(0));
    ui->gridLayout_camera_2->addWidget(_mapDisplay.value(1));
    ui->gridLayout_camera_3->addWidget(_mapDisplay.value(2));
    ui->gridLayout_camera_4->addWidget(_mapDisplay.value(3));




}
void cameraDisplayForm::mouseDoubleClickEvent(QMouseEvent *event)
{
    //   this->showMaximized();
    //    qDebug()<<"############################################"/*<<event->type()*/
    //           <<qobject_cast<baseCameraForm*>(sender())->objectName();


}
void cameraDisplayForm::slotCameraFormId(const QString &id)
{
    _mapDisplay.value(id.toInt())->setCameraShowStatus(true);
    P_cameraFullDialog->addWin(_mapDisplay.value(id.toInt()));
    P_cameraFullDialog->showNormal();

}
void cameraDisplayForm::slotCameraMin()
{
    ui->gridLayout_camera_1->addWidget(_mapDisplay.value(0));
    ui->gridLayout_camera_2->addWidget(_mapDisplay.value(1));
    ui->gridLayout_camera_3->addWidget(_mapDisplay.value(2));
    ui->gridLayout_camera_4->addWidget(_mapDisplay.value(3));
    _mapDisplay.value(0)->setCameraShowStatus(false);
    _mapDisplay.value(1)->setCameraShowStatus(false);
    _mapDisplay.value(2)->setCameraShowStatus(false);
    _mapDisplay.value(3)->setCameraShowStatus(false);
}
