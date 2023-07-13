cmake_minimum_required(VERSION 3.5)

project(encoder LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)
find_package(Qt5Widgets)
find_package(Qt5Network)
add_executable(encoder WIN32
  main.cpp
  func.h
  func.cpp
  basethreadpool.h
  basethreadpool.cpp
  serialWorkThreadPool.h
  serialWorkThreadPool.cpp
  publicclass.h
  publicclass.cpp
)
target_link_libraries(encoder Qt5::Core Qt5::Widgets Qt5::SerialPort Qt5::Network)

