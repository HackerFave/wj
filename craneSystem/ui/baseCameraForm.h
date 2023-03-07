#ifndef BASECAMERAFORM_H
#define BASECAMERAFORM_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
//#include "../ui/Interface/IFunWidget.h"
#include "baseForm.h"
namespace Ui {
class baseCameraForm;
}

class baseCameraForm : public baseForm
{
    Q_OBJECT

public:
    explicit baseCameraForm(QWidget *parent = nullptr);
    ~baseCameraForm();
    void setCameraTitle(const QString &camera);
    void setClassName(const QString &name);
    void setCameraShowStatus(bool status)
    {
        _cameraShowStatus = status;
    };
    bool getCameraShowStatus() const
    {
        return _cameraShowStatus;
    };
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

protected slots:
    void slotSender();
signals:
    void signalCameraFormId(const QString &id);
    void signalCameraMin();
private:
    Ui::baseCameraForm *ui;
    bool _cameraShowStatus = false;
};

#endif // BASECAMERAFORM_H
