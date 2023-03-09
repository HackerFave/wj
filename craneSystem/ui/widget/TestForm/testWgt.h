#ifndef TESTWGT_H
#define TESTWGT_H

#include <QWidget>
#include "../../Interface/IFunWidget.h"
#include <QResizeEvent>
#include "testCl.h"
#include "testModel.h"
#include <QTimer>
namespace Ui {
class testWgt;
}

class testWgt : public IFunWidget
{
    Q_OBJECT

public:
    explicit testWgt(QWidget *parent = nullptr);
    ~testWgt() override;

    static testWgt* GetInstance();
    virtual bool isQuit() override;
    virtual void initWidget() override;
    virtual void updateWidget() override;
//    void setFrameType(int small);

protected:
//    virtual void keyPressEvent(QKeyEvent *event) ;
    virtual void resizeEvent(QResizeEvent *event) override;

public slots:

    virtual void slotOnClDataCome(int cmd, QVariant data = INT_INVALID) override;
    virtual void slotOnModelUpdate(int cmd) override;

private slots:

private:
    Ui::testWgt *ui;
    static testWgt        *s_pInstance;
    testCl                *m_pCL;
    testModel             *m_pModel;
};


#endif // TESTWGT_H
