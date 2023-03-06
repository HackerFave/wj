#include "baseForm.h"
#include "ui_baseForm.h"
#include <QtDebug>
baseForm::baseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::baseForm)
{
    ui->setupUi(this);
    this->installEventFilter(this);
}

baseForm::~baseForm()
{
    delete ui;
}
void baseForm::changeEvent(QEvent *)
{

}
void baseForm::mouseDoubleClickEvent(QMouseEvent *event)
{
    //     if(this->isFullScreen()){
    //         this->showNormal();
    //     }
    //     else {
    //         this->showMaximized();
    //     }
}
void baseForm::enterEvent(QEvent *event)
{

}
void baseForm::moveEvent(QMoveEvent *event)
{

}
void baseForm::showEvent(QShowEvent *event)
{

}
void baseForm::closeEvent(QCloseEvent *event)
{

}
void baseForm::hideEvent(QHideEvent *event)
{

}
void baseForm:: mouseMoveEvent(QMouseEvent *event)
{

}
void baseForm::keyReleaseEvent(QKeyEvent *event)
{

    qDebug()<<"keyReleaseEvent"<<event->key();
}
void baseForm::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"keyPressEvent"<<event->key();
    if(event->key()==Qt::Key_Escape){
        if(this->isMaximized()){
            this->showNormal();
        }
        else {
            this->showMaximized();
        }
    }else if (event->key() == Qt::Key_0) {
        ModuleDir dir;
        dir.append(MD_TestForm);
        emit  signalKeyEvent(dir,CW_Test1 ,"http://baidu.com");
    }
}

void baseForm::mousePressEvent(QMouseEvent *event)
{

}
void baseForm::mouseReleaseEvent(QMouseEvent *event)
{

}
void baseForm::wheelEvent(QWheelEvent *event)
{

}
