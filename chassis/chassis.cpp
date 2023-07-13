#include "chassis.h"
#include "func.h"
void* initchassis()
{
    return (void*)new func(0);
}
void Release(void* fun)
{
    if (fun != NULL) {
        func* fu = (func*)fun;
        delete fu;
        fun = NULL;
    }
}
