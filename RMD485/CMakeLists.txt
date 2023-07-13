cmake_minimum_required(VERSION 3.5)

project(RMD485 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
find_package(Qt5 COMPONENTS SerialPort Widgets REQUIRED)
find_package(Qt5Widgets)
find_package(Qt5Network)
add_executable(RMD485 WIN32
  main.cpp
)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h *.ui)
target_sources(RMD485  PUBLIC ${sources})
target_link_libraries(RMD485 Qt5::Core Qt5::Widgets Qt5::SerialPort Qt5::Network)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)



