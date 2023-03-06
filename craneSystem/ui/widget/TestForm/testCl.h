#ifndef TESTCL_H
#define TESTCL_H

#include <QObject>
#include "../../Interface/IController.h"
#include "testModel.h"
class testCl : public IController
{
    Q_OBJECT
public:
    explicit testCl(QObject *parent = nullptr);
     ~testCl() override;

    void doInit() override;
    void doUnInit() override;
    bool intoAction() override;
    bool exitAction() override;
    void getFromAny(ModuleDir moduleDir,int cmd,QVariant data ) override;

    void getButton(int numb);
    void setModel(testModel *model);
private:

    testModel *m_pModel;
};

#endif // TESTCL_H
