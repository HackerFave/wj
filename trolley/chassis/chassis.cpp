#include "chassis.h"
#include "func.h"
void* initchassis(QByteArray &com)
{
    return (void*)new func(com);
}
void Release(void* fun)
{
    if (fun != NULL) {
        func* fu = (func*)fun;
        delete fu;
        fun = NULL;
    }
}
