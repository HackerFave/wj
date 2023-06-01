#ifndef BACKENDCAN_H
#define BACKENDCAN_H

#include "backendCan_global.h"
#include <QtCore/qglobal.h>
#include <iostream>
#include <stdlib.h>
#include "methord/funcCan.h"
using namespace std;
#if defined(BACKENDCAN_LIBRARY)
#  define BACKENDCAN_EXPORT Q_DECL_EXPORT
#else
#  define BACKENDCAN_EXPORT Q_DECL_IMPORT
#endif

extern"C"
{
BACKENDCAN_EXPORT void* init();
BACKENDCAN_EXPORT void Release(void* fun);
}

#endif // BACKENDCAN_H
