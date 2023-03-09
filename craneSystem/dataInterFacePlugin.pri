

INCLUDEPATH += $$PWD/dataInterFace/
INCLUDEPATH += $$PWD/dataInterFace/zmqmodule
INCLUDEPATH += $$PWD/dataInterFace/thread
INCLUDEPATH += $$PWD/dataInterFace/product

HEADERS += \
    $$PWD/dataInterFace/define_zmqmodule.h \
    $$PWD/dataInterFace/zmqmodule/baseObject.h \
    $$PWD/dataInterFace/zmqmodule/product/baseProduct.h \
    $$PWD/dataInterFace/zmqmodule/product/dataPub.h \
    $$PWD/dataInterFace/zmqmodule/product/dataSub.h \
    $$PWD/dataInterFace/zmqmodule/thread/IPC_Thread.h \
    $$PWD/dataInterFace/zmqmodule/thread/baseThread.h \
    $$PWD/dataInterFace/zmqmodule/thread/sqlTruncateThread.h \
    $$PWD/dataInterFace/zmqmodule/thread/subThreadPool.h \
    $$PWD/dataInterFace/zmqmodule/thread/workThread.h \
    $$PWD/dataInterFace/zmqmodule/topicCommon.h

SOURCES += \
    $$PWD/dataInterFace/zmqmodule/baseObject.cpp \
    $$PWD/dataInterFace/zmqmodule/product/baseProduct.cpp \
    $$PWD/dataInterFace/zmqmodule/product/dataPub.cpp \
    $$PWD/dataInterFace/zmqmodule/product/dataSub.cpp \
    $$PWD/dataInterFace/zmqmodule/thread/IPC_Thread.cpp \
    $$PWD/dataInterFace/zmqmodule/thread/baseThread.cpp \
    $$PWD/dataInterFace/zmqmodule/thread/sqlTruncateThread.cpp \
    $$PWD/dataInterFace/zmqmodule/thread/subThreadPool.cpp \
    $$PWD/dataInterFace/zmqmodule/thread/workThread.cpp


