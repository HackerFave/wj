#ifndef CAMERAFULLDIALOG_H
#define CAMERAFULLDIALOG_H

#include <QDialog>
#include <QEvent>
#include <QKeyEvent>
namespace Ui {
class cameraFullDialog;
}

class cameraFullDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cameraFullDialog(QWidget *parent = nullptr);
    ~cameraFullDialog();
    void addWin(QWidget * w);
protected:
    void closeEvent(QCloseEvent *) override;
signals:
    void signalCameraMin();
private:
    Ui::cameraFullDialog *ui;
};

#endif // CAMERAFULLDIALOG_H
