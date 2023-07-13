#ifndef YANKONGDATAFORM_H
#define YANKONGDATAFORM_H

#include <QWidget>
#include "define.h"
#include <queue>
#include <QQueue>
#include <QButtonGroup>
#include <mutex>
#include "chassis.h"
#include "func.h"
namespace Ui {
class yankongDataForm;
}

class yankongDataForm : public QWidget
{
    Q_OBJECT

public:
    explicit yankongDataForm(QWidget *parent = nullptr);
    ~yankongDataForm();
    void setValue(int32_t value);
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
    QQueue<QString> _data485;
    QButtonGroup _groupBtn;
    std::mutex _mutex;
    func *p_func = nullptr;
};

#endif // YANKONGDATAFORM_H
