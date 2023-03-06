#ifndef CAMERADISPLAYFORM_H
#define CAMERADISPLAYFORM_H

#include <QWidget>
#include "baseCameraForm.h"
#include <QMap>
#include <QEvent>
#include <QKeyEvent>
#include "cameraFullDialog.h"
namespace Ui {
class cameraDisplayForm;
}

class cameraDisplayForm : public QWidget
{
    Q_OBJECT

public:
    explicit cameraDisplayForm(QWidget *parent = nullptr);
    ~cameraDisplayForm();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
protected slots:
    void slotCameraFormId(const QString &id);
    void slotCameraMin();
signals:
private:
    void initUi();
private:
    Ui::cameraDisplayForm *ui;

    QMap<int,baseCameraForm*> _mapDisplay;
    cameraFullDialog * P_cameraFullDialog = nullptr;
};

#endif // CAMERADISPLAYFORM_H
