#ifndef VIEWSHOWFORM_H
#define VIEWSHOWFORM_H

#include <QWidget>
//#include <Windows.h>
//#include "methord/qcustomplot.h"
namespace Ui {
class viewShowForm;
}

class viewShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit viewShowForm(QWidget *parent = nullptr);
    ~viewShowForm();

private slots:
    void on_checkBox_Rpm_stateChanged(int arg1);

    void on_checkBox_Volt_stateChanged(int arg1);

    void on_checkBox_Current_stateChanged(int arg1);

private:
    Ui::viewShowForm *ui;
    //----------//
//    QMap<QString,QCPGraph*> graphMap;
};

#endif // VIEWSHOWFORM_H
