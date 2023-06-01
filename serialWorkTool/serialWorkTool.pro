QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++11
QT += charts
QT += serialport
QT += serialbus
win32:CONFIG += console
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#QMAKE_CXXFLAGS += -O0
#QMAKE_CXXFLAGS -= -O1
#QMAKE_CXXFLAGS -= -O2
#QMAKE_CXXFLAGS -= -O3
#QMAKE_CXXFLAGS_RELEASE_WITH_DEBUGINFO += -Od

QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

SOURCES += \
    canDataRecvThread.cpp \
    canDataSendThread.cpp \
    canDataShowForm.cpp \
    datashowform.cpp \
    lingChaCanform.cpp \
    main.cpp \
    mainwindow.cpp \
    methord/qcustomplot.cpp \
    methord/qserialwork.cpp \
    multipleMotorTestForm.cpp \
    network/clientwidget.cpp \
    public/publicclass.cpp \
    rmdSettingForm.cpp \
    serialWorkThreadPool.cpp \
    canDataRecvThread.cpp \
    thread/baseThread.cpp \
    thread/basethreadpool.cpp \
    viewShowForm.cpp \
    xintuoCanForm.cpp \
    yankongDataForm.cpp

HEADERS += \
    canDataRecvThread.h \
    canDataSendThread.h \
    canDataShowForm.h \
    datashowform.h \
    lingChaCanform.h \
    mainwindow.h \
    methord/qcustomplot.h \
    methord/qserialwork.h \
    multipleMotorTestForm.h \
    network/clientwidget.h \
    public/publicclass.h \
    rmdSettingForm.h \
    serialWorkThreadPool.h \
    canDataRecvThread.h \
    thread/baseThread.h \
    thread/basethreadpool.h \
    viewShowForm.h \
    xintuoCanForm.h \
    yankongDataForm.h

FORMS += \
    canDataShowForm.ui \
    datashowform.ui \
    lingChaCanform.ui \
    mainwindow.ui \
    multipleMotorTestForm.ui \
    network/clientwidget.ui \
    rmdSettingForm.ui \
    viewShowForm.ui \
    xintuoCanForm.ui \
    yankongDataForm.ui

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/include/chassis
  contains(QT_ARCH, i386) {
         message("32-bit")
     LIBS +=-L$$PWD/lib/x32 -lControlCAN
     } else {
         message("64-bit")
     LIBS +=-L$$PWD/lib/x64 -lControlCAN -lchassis
     }
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32:msvc{
#QMAKE_CXXFLAGS += /source-charset:utf-8 /execution-charset:utf-8
#}

RESOURCES += \
    source.qrc
