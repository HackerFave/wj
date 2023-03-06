#ifndef OUTPUTFORM_H
#define OUTPUTFORM_H

#include <QWidget>
#include "../ui/Interface/IFunWidget.h"
namespace Ui {
class outputForm;
}
class outputForm : public QWidget
{
    Q_OBJECT

public:
    explicit outputForm(QWidget *parent = nullptr);
    ~outputForm();
    void showOutPut(const QString &text);
signals:
    void AppendText(const QString &text);
private slots:
    void SlotAppendText(const QString &text);
private:
    Ui::outputForm *ui;
};


#endif // OUTPUTFORM_H
