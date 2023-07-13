#ifndef HEADGR_GLOBAL_H
#define HEADGR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HEADGR_LIBRARY)
#  define HEADGR_EXPORT Q_DECL_EXPORT
#else
#  define HEADGR_EXPORT Q_DECL_IMPORT
#endif

#endif // HEADGR_GLOBAL_H
