#ifndef CHASSIS_H
#define CHASSIS_H

#include "chassis_global.h"
#include <QtCore/qglobal.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#if defined(CHASSIS_LIBRARY)
#  define CHASSIS_EXPORT Q_DECL_EXPORT
#else
#  define CHASSIS_EXPORT Q_DECL_IMPORT
#endif

extern"C"
{
CHASSIS_EXPORT void* initchassis();
CHASSIS_EXPORT void Release(void* fun);
}

#endif // CHASSIS_H
