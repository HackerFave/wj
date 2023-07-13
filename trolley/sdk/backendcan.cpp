#include "backendcan.h"
#include "methord/funcCan.h"
#include <functional>
void* init()
{
    return (void*)new funcCan(0);
}
void Release(void* fun)
{
    if (fun != NULL) {
        funcCan* fu = (funcCan*)fun;
        delete fu;
        fun = NULL;
    }
}
