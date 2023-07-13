QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
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

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

unix{
    target.path = /usr/lib
    INCLUDEPATH += $$PWD/../../public/baseWidget
    LIBS +=-L$$PWD/../../LINUX/lib -lbaseWidget #-lsqlModule
    INCLUDEPATH += $$PWD/../../LINUX/include
    LIBS +=-L$$PWD/.././LINUX/lib -lfastrtps
    CONFIG(debug, debug|release){
            DESTDIR =$$PWD/../../build/debug/Plugins
           }else{
            DESTDIR =$$PWD/../../build/release/Plugins
    }
}
win32{

  INCLUDEPATH += $$PWD/../include
  contains(QT_ARCH, i386) {
         message("32-bit")
     LIBS +=-L$$PWD/../lib/x32 -lControlCAN
     LIBS +=-L$$PWD/../lib/ -lpublicInterface
     } else {
         message("64-bit")
     LIBS +=-L$$PWD/../lib/x64 -lControlCAN -lECanVci64
     LIBS +=-L$$PWD/../lib/ -lpublicInterface -lchassis -lbackendCan
     }
    CONFIG(debug, debug|release){
            DESTDIR =$$PWD/build/debug
            LIBS +=-L$$PWD/lib/x64 -lControlCAN -lECanVci64
            LIBS +=-L$$PWD/lib/ -lbackendCan -lpublicInterface -lchassis

           }else{
            DESTDIR =$$PWD/build/release
            LIBS +=-L$$PWD/lib/x64 -lControlCAN -lECanVci64
            LIBS +=-L$$PWD/lib/ -lbackendCan -lpublicInterface -lchassis
    }
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
