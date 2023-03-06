#include "baseCameraForm.h"
#include "ui_baseCameraForm.h"
#include <QtDebug>
baseCameraForm::baseCameraForm(QWidget *parent) :
    baseForm(parent),
    ui(new Ui::baseCameraForm)
{
    ui->setupUi(this);

}

baseCameraForm::~baseCameraForm()
{
    delete ui;
}
void baseCameraForm::setCameraTitle(const QString &camera){
    ui->camera_groupBox_title->setTitle(camera);
};
void baseCameraForm::slotSender()
{
    QString str = static_cast<QString>(this->sender()->objectName());
    qDebug()<<"objectName::"<<str;
}
void baseCameraForm::setClassName(const QString &name)
{
    this->setObjectName(name);
}
void baseCameraForm::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(!getCameraShowStatus()){
        QString str = this->objectName();
        qDebug()<<"objectName::"<<str;
        emit signalCameraFormId(str);
        this->setFocus();
    }
}

