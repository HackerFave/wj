QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql  opengl gui network webenginewidgets concurrent charts serialport serialbus

CONFIG += c++11
include($$PWD/dataInterFacePlugin.pri)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS



DEFINES += QT_MESSAGELOGCONTEXT



#    /NODEFAULTLIB:msvcrt.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base/StreamThread.cpp \
    base/OpenGLWidget.cpp \
    base/TGFrame.cpp \
    base/webEngie.cpp \
#    driver/burglarAlarm485.cpp \
    driver/Net485.cpp \
    driver/burglarAlarm485.cpp \
    main.cpp \
    message/outputForm.cpp \
    public/httpMethord.cpp \
    sql/SqlMethod.cpp \
    sql/sqlOperation.cpp \
    ui/Interface/IController.cpp \
    ui/Interface/IFunWidget.cpp \
    ui/Interface/IModel.cpp \
    ui/Interface/System.cpp \
    ui/Interface/WgtFactory.cpp \
    ui/baseCameraForm.cpp \
    ui/baseForm.cpp \
    ui/cameraDisplayForm.cpp \
    ui/cameraFullDialog.cpp \
    ui/widget/DataShow/backendDataControl.cpp \
    ui/widget/DataShow/backendDataForm.cpp \
    ui/widget/DataShow/backendDataModel.cpp \
    ui/widget/DataShow/tableView.cpp \
    ui/widget/TestForm/testCl.cpp \
    ui/widget/TestForm/testModel.cpp \
    ui/widget/TestForm/testWgt.cpp \
    widget.cpp

HEADERS += \
    base/StreamThread.h \
    base/StreamThread.h \
    base/OpenGLWidget.h \
    base/TGFrame.h \
    base/jt808.hpp \
    base/webEngie.h \
#    driver/burglarAlarm485.h \
    driver/Net485.h \
    driver/burglarAlarm485.h \
    message/outputForm.h \
    public/fbsstructure.h \
    public/httpMethord.h \
    public/publicclass.h \
    sql/SqlMethod.h \
    sql/sqlOperation.h \
    ui/Interface/IController.h \
    ui/Interface/IFunWidget.h \
    ui/Interface/IModel.h \
    ui/Interface/System.h \
    ui/Interface/WgtFactory.h \
    ui/baseCameraForm.h \
    ui/baseForm.h \
    ui/cameraDisplayForm.h \
    ui/cameraFullDialog.h \
    ui/widget/DataShow/backendDataControl.h \
    ui/widget/DataShow/backendDataForm.h \
    ui/widget/DataShow/backendDataModel.h \
    ui/widget/DataShow/tableView.h \
    ui/widget/TestForm/testCl.h \
    ui/widget/TestForm/testModel.h \
    ui/widget/TestForm/testWgt.h \
    widget.h

FORMS += \
    base/webEngie.ui \
    message/outputForm.ui \
    ui/baseCameraForm.ui \
    ui/baseForm.ui \
    ui/cameraDisplayForm.ui \
    ui/cameraFullDialog.ui \
    ui/widget/DataShow/backendDataForm.ui \
    ui/widget/TestForm/testWgt.ui \
    widget.ui




#unix{
#    target.path = /usr/lib
#    INCLUDEPATH += $$PWD/../../public/baseWidget
#    LIBS +=-L$$PWD/../../LINUX/lib -lbaseWidget #-lsqlModule
#    INCLUDEPATH += $$PWD/../../LINUX/include
#    LIBS +=-L$$PWD/.././LINUX/lib -lfastrtps
#    CONFIG(debug, debug|release){
#            DESTDIR =$$PWD/../../build/debug
#           }else{
#            DESTDIR =$$PWD/../../build/release
#    }
#}
win32{

        INCLUDEPATH += $$PWD/ffmpeg/include
        LIBS += -L$$PWD/ffmpeg/lib -lavcodec -lavformat -lavutil -lavdevice -lavfilter -lpostproc -lswresample -lswscale
        INCLUDEPATH += $$PWD/include
        LIBS += -L$$PWD/lib/curl -llibcurl
    CONFIG(debug, debug|release){
            DESTDIR =$$PWD/build/debug
        LIBS += -L$$PWD/lib/debug  -lqBreakpad -lflatbuffers
        LIBS += -L$$PWD/lib/zmq/debug -lzmq_wrapper
           }else{
            DESTDIR =$$PWD/build/release
        LIBS += -L$$PWD/lib/release -lqBreakpad -lflatbuffers
        LIBS += -L$$PWD/lib/zmq/release -lzmq_wrapper
       }

        LIBS += -L$$PWD/ZeroMQ -lzmq -llibzmq -llibzmq-v141-mt-4_3_2
        LIBS += -L$$PWD/lib -lPlayCtrl -lHCNetSDK -lHCCore -lGdiPlus -lHCAlarm -lHCGeneralCfgMgr -lHCPreview
        LIBS += -L$$PWD/lib/HCNetSDKCom  -lHCAlarm -lHCGeneralCfgMgr -lHCPreview
        LIBS += -lAdvapi32
#        LIBS +=  -lmsvcrtd //造成dump 模块崩溃的问题

        INCLUDEPATH += $$PWD/include
        INCLUDEPATH += $$PWD/fbs/include
        INCLUDEPATH += $$PWD/ZeroMQ

        CONFIG+=debug_and_release
        pclversion1=1.11.1
        pclversion2=1.11
        boostversion=1_74
        vtkversion=8.2

        QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
        QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO


}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
