QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += charts
QT += serialport
QT += serialbus
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    canDataSendThread.cpp \
    canDataShowForm.cpp \
    datashowform.cpp \
    main.cpp \
    mainwindow.cpp \
    methord/qcustomplot.cpp \
    methord/qserialwork.cpp \
    public/publicclass.cpp \
    rmdSettingForm.cpp \
    serialWorkThreadPool.cpp \
    testDataThread.cpp \
    thread/baseThread.cpp \
    thread/basethreadpool.cpp \
    viewShowForm.cpp

HEADERS += \
    canDataSendThread.h \
    canDataShowForm.h \
    datashowform.h \
    mainwindow.h \
    methord/qcustomplot.h \
    methord/qserialwork.h \
    public/publicclass.h \
    rmdSettingForm.h \
    serialWorkThreadPool.h \
    testDataThread.h \
    thread/baseThread.h \
    thread/basethreadpool.h \
    viewShowForm.h

FORMS += \
    canDataShowForm.ui \
    datashowform.ui \
    mainwindow.ui \
    rmdSettingForm.ui \
    viewShowForm.ui

INCLUDEPATH += $$PWD/include

  contains(QT_ARCH, i386) {
         message("32-bit")
     LIBS +=-L$$PWD/lib/x32 -lControlCAN
     } else {
         message("64-bit")
     LIBS +=-L$$PWD/lib/x64 -lControlCAN
     }
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    source.qrc
