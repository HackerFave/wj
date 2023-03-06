#ifndef IFUNWIDGET_H
#define IFUNWIDGET_H

#include <QWidget>
#include <QVariant>
#include "../Interface/IController.h"
#include "../Interface/IModel.h"
#include "../baseForm.h"
//#include "MainFile/widgetsize.h"

class IFunWidget : public /*QWidget*/baseForm
{
    Q_OBJECT
public:

    explicit IFunWidget(QWidget *parent = nullptr);
    virtual ~IFunWidget();
    virtual void initWidget();
    virtual bool isEnter();
    virtual bool isQuit();
    virtual void quit();
    virtual void updateWidget();
    virtual void showedWidgetDo();

    void setName(QString name);
    QString getName();

    IController *getCL();
    void setCL(IController *cl);

    IModel *getModel();
    void setModel(IModel *md);
protected:
    void paintEvent(QPaintEvent* event);
    virtual void keyReleaseEvent(QKeyEvent *event) ;
public slots:

    virtual void onClDataCome(int cmd, QVariant data = INT_INVALID);
    virtual void onModelUpdate(int cmd);

protected:
    IController  *m_pICL=nullptr;
    IModel     *m_pIModel=nullptr;

private:
    QString     name;

};

#endif // IFUNWIDGET_H
