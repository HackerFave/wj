#ifndef PUBLICINTERFACE_H
#define PUBLICINTERFACE_H

#include "publicInterface_global.h"
#include <QtCore/qglobal.h>
#include <iostream>
#include <stdlib.h>
#include "publicclass.h"
using namespace std;
#if defined(PUBLICINTERFACE_LIBRARY)
#  define PUBLICINTERFACE_EXPORT Q_DECL_EXPORT
#else
#  define PUBLICINTERFACE_EXPORT Q_DECL_IMPORT
#endif
#endif // PUBLICINTERFACE_H
