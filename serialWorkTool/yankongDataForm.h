#ifndef YANKONGDATAFORM_H
#define YANKONGDATAFORM_H

#include <QWidget>
#include "ControlCAN.h"
#include "chassis/chassis.h"
#include "chassis/func.h"
#include <queue>
#include <QQueue>
#include <QButtonGroup>
namespace Ui {
class yankongDataForm;
}

class yankongDataForm : public QWidget
{
    Q_OBJECT

public:
    explicit yankongDataForm(QWidget *parent = nullptr);
    ~yankongDataForm();
public slots:
    void slotRecvData(UINT id, BYTE *data);
private slots:
    void on_pushButton_zhengzhuan_clicked();

    void on_pushButton_fanzhuan_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_2_clicked();

    void on_horizontalSlider_sliderMoved(int position);

//    void on_horizontalSlider_actionTriggered(int action);

    void on_radioButton_up_clicked();

    void on_radioButton_back_clicked();

private:
    Ui::yankongDataForm *ui;
    func *p_func;
    QQueue<QString> _data485;
    std::mutex _mutex;
    QButtonGroup _groupBtn;
};

#endif // YANKONGDATAFORM_H
