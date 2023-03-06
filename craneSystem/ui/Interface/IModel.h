#ifndef IMODEL_H
#define IMODEL_H

#include <QObject>

class IModel : public QObject
{
    Q_OBJECT
public:
    IModel(QObject *parent);
    ~IModel();



signals:

    void sendModelUpdate(int cmd);

};

#endif // IMODEL_H
