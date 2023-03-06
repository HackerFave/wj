#include "datainterfacehmi.h"

dataInterface *initInstance()
{
    return dataInterface::getInstance();
}
void setPostData(const void *payload, size_t payload_len, int id)
{
    dataInterface::getInstance()->emitPostData(payload,payload_len,id);
}
