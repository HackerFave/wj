#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "func.h"
#include "publicclass.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_pushButton_zhengzhuan_clicked();

    void on_pushButton_fanzhuan_clicked();

    void on_pushButton_stop_clicked();

    void slotUpdateTimer();
private:
    void initJasudu();
private:
    Ui::Widget *ui;
    func * P_func = nullptr;
    QTimer _timer;
};
#endif // WIDGET_H
