#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QObject>
#include <QMetaObject>
#include <QMetaType>
#include <QMetaMethod>
#include <QMetaProperty>

class baseObject : public QObject
{
    Q_OBJECT
public:
    explicit baseObject(QObject *parent = nullptr);

signals:

};

#endif // BASEOBJECT_H
