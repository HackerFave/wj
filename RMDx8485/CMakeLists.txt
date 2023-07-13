cmake_minimum_required(VERSION 3.5)

project(RMDx8485 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(RMDx8485
  main.cpp
)
file(GLOB sources CONFIGURE_DEPENDS *.cpp *.h)
target_sources(RMDx8485 PUBLIC ${sources})
target_link_libraries(RMDx8485 Qt5::Core)
