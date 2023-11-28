# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)

project(MyQtProject)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
SET(CMAKE_CXX_STANDARD 14)

# Find the Qt library
find_package(Qt5 COMPONENTS Core Widgets Gui OpenGL REQUIRED)

ADD_SUBDIRECTORY(tests)
