QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
\
QT  += axcontainer
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L$$PWD/lib -lflatbuffers -lzmq_wrapper
LIBS += -L$$PWD/ZeroMQ -lzmq -llibzmq -llibzmq-v141-mt-4_3_2

LIBS += -lAdvapi32
LIBS +=  -lmsvcrtd
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/fbs/include
INCLUDEPATH += $$PWD/ZeroMQ


CONFIG+=debug_and_release
pclversion1=1.11.1
pclversion2=1.11
boostversion=1_74
vtkversion=8.2

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h


FORMS += \
    mainwindow.ui



LIBS += -L$$PWD/Boost/lib \
    -llibboost_atomic-vc142-mt-gd-x64-$$boostversion\
    -llibboost_bzip2-vc142-mt-gd-x64-$$boostversion\
    -llibboost_chrono-vc142-mt-gd-x64-$$boostversion\
    -llibboost_container-vc142-mt-gd-x64-$$boostversion\
    -llibboost_context-vc142-mt-gd-x64-$$boostversion\
    -llibboost_contract-vc142-mt-gd-x64-$$boostversion\
    -llibboost_coroutine-vc142-mt-gd-x64-$$boostversion\
    -llibboost_date_time-vc142-mt-gd-x64-$$boostversion\
    -llibboost_exception-vc142-mt-gd-x64-$$boostversion\
    -llibboost_fiber-vc142-mt-gd-x64-$$boostversion\
    -llibboost_filesystem-vc142-mt-gd-x64-$$boostversion\
    -llibboost_graph-vc142-mt-gd-x64-$$boostversion\
    -llibboost_graph_parallel-vc142-mt-gd-x64-$$boostversion\
    -llibboost_iostreams-vc142-mt-gd-x64-$$boostversion\
    -llibboost_locale-vc142-mt-gd-x64-$$boostversion\
    -llibboost_log-vc142-mt-gd-x64-$$boostversion\
    -llibboost_log_setup-vc142-mt-gd-x64-$$boostversion\
    -llibboost_math_c99-vc142-mt-gd-x64-$$boostversion\
    -llibboost_math_c99f-vc142-mt-gd-x64-$$boostversion\
    -llibboost_math_c99l-vc142-mt-gd-x64-$$boostversion\
    -llibboost_math_tr1-vc142-mt-gd-x64-$$boostversion\
    -llibboost_math_tr1f-vc142-mt-gd-x64-$$boostversion\
    -llibboost_math_tr1l-vc142-mt-gd-x64-$$boostversion\
    -llibboost_mpi-vc142-mt-gd-x64-$$boostversion\
    -llibboost_numpy38-vc142-mt-gd-x64-$$boostversion\
    -llibboost_prg_exec_monitor-vc142-mt-gd-x64-$$boostversion\
    -llibboost_program_options-vc142-mt-gd-x64-$$boostversion\
    -llibboost_python38-vc142-mt-gd-x64-$$boostversion\
    -llibboost_random-vc142-mt-gd-x64-$$boostversion\
    -llibboost_regex-vc142-mt-gd-x64-$$boostversion\
    -llibboost_serialization-vc142-mt-gd-x64-$$boostversion\
    -llibboost_stacktrace_noop-vc142-mt-gd-x64-$$boostversion\
    -llibboost_stacktrace_windbg-vc142-mt-gd-x64-$$boostversion\
    -llibboost_stacktrace_windbg_cached-vc142-mt-gd-x64-$$boostversion\
    -llibboost_system-vc142-mt-gd-x64-$$boostversion\
    -llibboost_test_exec_monitor-vc142-mt-gd-x64-$$boostversion\
    -llibboost_thread-vc142-mt-gd-x64-$$boostversion\
    -llibboost_timer-vc142-mt-gd-x64-$$boostversion\
    -llibboost_type_erasure-vc142-mt-gd-x64-$$boostversion\
    -llibboost_unit_test_framework-vc142-mt-gd-x64-$$boostversion\
    -llibboost_wave-vc142-mt-gd-x64-$$boostversion\
    -llibboost_wserialization-vc142-mt-gd-x64-$$boostversion\
    -llibboost_zlib-vc142-mt-gd-x64-$$boostversion \
#LIBS += -lzmq_wrapper
#INCLUDEPATH += $$PWD/lib/Boost/include/boost-1_74/boost

#LIBS += -l ./../lib/libzmq_wrapper.so
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += $$PWD/Boost/include/boost-1_74/boost



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
