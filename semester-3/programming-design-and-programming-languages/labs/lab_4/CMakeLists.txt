cmake_minimum_required (VERSION 3.2)

project(lab4)

set(SOURCES  main.cpp IntArray.cpp)
include_directories("headers/")
add_library(lib fun.cpp)
add_executable(app ${SOURCES})
target_link_libraries(app lib)