QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

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

   INCLUDEPATH += $$PWD/include
   LIBS +=-L$$PWD/lib -llibcurl #-lWs2_32 -lWldap32 -lwinmm -lCrypt32 -lNormaliz
#Ws2_32.lib
#Wldap32.lib
#winmm.lib
#Crypt32.lib
#Normaliz.lib


SOURCES += \
#    httpMethord.cpp \
    HttpClient.cpp \
    QtHttpForC.cpp \
    httpMethord.cpp \
    main.cpp \
    Widget.cpp

HEADERS += \
    HttpClient.h \
    QtHttpForC.h \
    Widget.h \
 \#    httpMethord.h
    httpMethord.h

FORMS += \
    QtHttpForC.ui \
    Widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
