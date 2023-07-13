QT -= gui
QT += serialport network

TEMPLATE = lib
DEFINES += HEADGR_LIBRARY

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
    func.cpp \
    headgr.cpp \
    publicclass.cpp

HEADERS += \
    func.h \
    headGR_global.h \
    headgr.h \
    publicclass.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}

win32{

  INCLUDEPATH += $$PWD/../include
  contains(QT_ARCH, i386) {
         message("32-bit")
#     LIBS +=-L$$PWD/../lib/ -lpublicInterface
     } else {
         message("64-bit")
#     LIBS +=-L$$PWD/../lib/ -lpublicInterface
     }
    CONFIG(debug, debug|release){
            DESTDIR =$$PWD/../testGR/build/debug
           }else{
            DESTDIR =$$PWD/../testGR/build/release
    }
}

!isEmpty(target.path): INSTALLS += target
