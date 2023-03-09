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

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    inline int getPage(int count)
    {
        if(count%20 == 0){
            return count/20;
        }
        else if (count<=20) {
            return 1;
        }
        else {
            return  count/20 +1 ;
        }
    }
    inline int getRemainder(int count)
    {
        return  count%20  ;
    }
public slots:

    virtual void slotOnClDataCome(int cmd, QVariant data = INT_INVALID) override;
    virtual void slotOnModelUpdate(int cmd) override;

private slots:
    void slotPushButton_find();
    void on_pushButton_up_page_clicked();

    void on_pushButton_down_page_clicked();

    void on_pushButton_on_page_clicked();

private:
    Ui::backendDataForm *ui;
    static backendDataForm  *s_pInstance;
    backendDataControl      *m_pCL;
    backendDataModel        *m_pModel;
    tableView *P_tableView = nullptr;
};

#endif // BACKENDDATAFORM_H
