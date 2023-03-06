#ifndef BASEFORM_H
#define BASEFORM_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include "Interface/System.h"
#include <QVariant>
namespace Ui {
class baseForm;
}

class baseForm : public QWidget
{
    Q_OBJECT

public:
    explicit baseForm(QWidget *parent = nullptr);
    ~baseForm();
protected:
    virtual void changeEvent(QEvent *) ;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) ;
    virtual void enterEvent(QEvent *event) ;
    virtual void moveEvent(QMoveEvent *event) ;
    virtual void showEvent(QShowEvent *event) ;
    virtual void closeEvent(QCloseEvent *event) ;
    virtual void hideEvent(QHideEvent *event) ;
    virtual void mouseMoveEvent(QMouseEvent *event) ;
    virtual void keyReleaseEvent(QKeyEvent *event) ;
    virtual void keyPressEvent(QKeyEvent *event) ;
    virtual void mousePressEvent(QMouseEvent *event) ;
    virtual void mouseReleaseEvent(QMouseEvent *event) ;
    virtual void wheelEvent(QWheelEvent *event) ;
signals :
    void signalKeyEvent(ModuleDir,int ,QVariant);
private:
    Ui::baseForm *ui;
};

#endif // BASEFORM_H
