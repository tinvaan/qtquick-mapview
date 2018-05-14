project(mapview)
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_MIN_VERSION "5.5.0")
find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS Core Quick Widgets Positioning)

option(BUILD_TESTS "Build a basic unit test to check the funtioning of the interpolation module" OFF)

add_subdirectory(src)
