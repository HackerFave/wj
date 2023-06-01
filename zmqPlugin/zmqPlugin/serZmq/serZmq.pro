QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L$$PWD/lib -lflatbuffers -lzmq_wrapper
LIBS += -L$$PWD/ZeroMQ -llibzmq-v141-mt-4_3_2  -lzmq -llibzmq

LIBS += -lAdvapi32
#LIBS +=  -lmsvcrtd
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/fbs/include
INCLUDEPATH += $$PWD/ZeroMQ




CONFIG+=debug_and_release
#pclversion1=1.11.1
#pclversion2=1.11
#boostversion=1_74
#vtkversion=8.2

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
