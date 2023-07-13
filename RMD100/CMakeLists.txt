cmake_minimum_required(VERSION 3.5)

project(RMD100 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS SerialPort Widgets REQUIRED)
find_package(Qt5Widgets)
find_package(Qt5Network)
if(ANDROID)
  add_library(RMD100 SHARED WIN32
    main.cpp
    widget.cpp
    widget.h
    widget.ui
  )
else()
  add_executable(RMD100 WIN32
    main.cpp
    widget.cpp
    widget.h
    widget.ui
  )
endif()
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h *.ui)
target_sources(RMD100 PUBLIC ${sources})
target_link_libraries(RMD100 PRIVATE Qt5::Widgets Qt5::Core Qt5::SerialPort Qt5::Network)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
