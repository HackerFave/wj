QT -= gui

TEMPLATE = lib
DEFINES += PUBLICINTERFACE_LIBRARY

CONFIG += c++11

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
    publicclass.cpp \

HEADERS += \
    publicInterface_global.h \
    publicclass.h

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
  contains(QT_ARCH, i386) {
         message("32-bit")
#     LIBS +=-L$$PWD/lib/x32 -lControlCAN
     } else {
         message("64-bit")
#     LIBS +=-L$$PWD/lib/x64 -lControlCAN
     }
    CONFIG(debug, debug|release){
            DESTDIR =$$PWD/../../lib
           }else{
            DESTDIR =$$PWD/../../lib
    }
}


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
