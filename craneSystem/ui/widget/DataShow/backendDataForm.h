#ifndef BACKENDDATAFORM_H
#define BACKENDDATAFORM_H

#include <QWidget>
#include "../../sql/SqlMethod.h"
#include "../../ui/Interface/IFunWidget.h"
#include "backendDataControl.h"
#include "backendDataModel.h"
#include "tableView.h"
namespace Ui {
class backendDataForm;
}

class backendDataForm : public IFunWidget
{
    Q_OBJECT

public:
    explicit backendDataForm(QWidget *parent = nullptr);
    ~backendDataForm();

    static backendDataForm* GetInstance();
    virtual bool isQuit() override;
    virtual void initWidget() override;
    virtual void updateWidget() override;
    //    void setFrameType(int small);

protected:
    //    virtual void keyPressEvent(QKeyEvent *event) ;
    virtual void resizeEvent(QResizeEvent *event) override;

public slots:

    virtual void onClDataCome(int cmd, QVariant data = INT_INVALID) override;
    virtual void onModelUpdate(int cmd) override;

private slots:
    void slotPushButton_find();
private:
    Ui::backendDataForm *ui;
    static backendDataForm  *s_pInstance;
    backendDataControl      *m_pCL;
    backendDataModel        *m_pModel;
    tableView *P_tableView = nullptr;
};

#endif // BACKENDDATAFORM_H
