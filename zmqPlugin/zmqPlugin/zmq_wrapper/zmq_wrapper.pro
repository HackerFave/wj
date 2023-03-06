QT -= gui

TEMPLATE = lib
CONFIG += staticlib
#TEMPLATE = lib
#DEFINES += DATAINTERFACEHMI_LIBRARY
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L$$PWD/lib -lflatbuffers

LIBS += -lAdvapi32 -llibcmt
LIBS +=  -lmsvcrtd
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11


CONFIG+=debug_and_release
pclversion1=1.11.1
pclversion2=1.11
boostversion=1_74
vtkversion=8.2

SOURCES += \
    src/node.cpp \
    zmq_wrapper.cpp

HEADERS += \
    include/mdp.h \
    include/node.h \
    include/zhelpers.hpp \
    include/zmq.h \
    include/zmq_client.h \
    include/zmq_server.h \
    include/zmsg.hpp \
    zmq_wrapper.h \

    INCLUDEPATH += ./
    INCLUDEPATH += ./ZeroMQ
    INCLUDEPATH += ./include
    INCLUDEPATH += ./fbs/include

unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
