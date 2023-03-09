#include "IFunWidget.h"
#include <QStyleOption>
#include <QPainter>
IFunWidget::IFunWidget(QWidget *parent) :
    /*QWidget*/baseForm(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);


}
IFunWidget::~IFunWidget()
{

}

void IFunWidget::initWidget()
{

}

void IFunWidget::quit()
{
    this->hide();
}

bool IFunWidget::isQuit()
{
    return true;
}

bool IFunWidget::isEnter()
{
    return true;
}

void IFunWidget::updateWidget()
{
    ;
}

void IFunWidget::showedWidgetDo()
{
    ;
}

void IFunWidget::setName(QString name)
{
    this->name=name;
}

QString IFunWidget::getName()
{
    return this->name;
}

void IFunWidget::slotOnClDataCome(int cmd, QVariant data)
{
    Q_UNUSED(cmd)
    Q_UNUSED(data)
}

void IFunWidget::slotOnModelUpdate(int cmd)
{
    Q_UNUSED(cmd)
}

void IFunWidget::setCL(IController *cl)
{
    this->m_pICL = cl;
    connect(this->m_pICL,SIGNAL(signalPushDataToView(int,QVariant)),this,SLOT(slotOnClDataCome(int,QVariant)));
}

IController *IFunWidget::getCL()
{
    return this->m_pICL;
}

void IFunWidget::setModel(IModel *md)
{
    this->m_pIModel = md;
    connect(this->m_pIModel,SIGNAL(signalSendModelUpdate(int)),this,SLOT(slotOnModelUpdate(int)));
}

void IFunWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void IFunWidget::keyReleaseEvent(QKeyEvent *event)
{

}
IModel *IFunWidget::getModel()
{
    return this->m_pIModel;
}
