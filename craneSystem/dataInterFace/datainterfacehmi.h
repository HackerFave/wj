#ifndef DATAINTERFACEHMI_H
#define DATAINTERFACEHMI_H

#include "dataInterfaceHmi_global.h"
#include "define_zmqmodule.h"

extern "C"
{
DATAINTERFACEHMI_EXPORT dataInterface * initInstance();
DATAINTERFACEHMI_EXPORT void setPostData(const void *payload, size_t payload_len, int id);
}


#endif // DATAINTERFACEHMI_H
