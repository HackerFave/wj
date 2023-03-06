#ifndef FACTORYOBJECT_H
#define FACTORYOBJECT_H

#include <QObject>
#include <iostream>
using namespace std;
#include <map>
#include <string>
#include <QtDebug>
typedef void* (*create_fun)();

#define REGISTER(className)                                        \
    className* objectCreator##className(){                         \
    return new className;                                          \
    }                                                              \
    RegisterAction g_creatorRegister##className(                   \
#className,(create_fun)objectCreator##className)


class factoryObject : public QObject
{
    Q_OBJECT
public:
    ~factoryObject(){}
    void *GetClassByName(string name)
    {
        std::map<string,create_fun>::iterator ite = my_class.find(name);      
        if(ite==my_class.end()){
            return NULL;
        }
        else{
            return ite->second();

        }
    }
    void RegisterClassTmp(string name,create_fun fun)//注册类
    {
        my_class[name]=fun;
    }
    static factoryObject& GetInstance()
    {
        static factoryObject f;
        return f;
    }
private:
    factoryObject();
    std::map<string,create_fun> my_class;

signals:

};

#endif // FACTORYOBJECT_H
