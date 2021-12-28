cmake_minimum_required (VERSION 3.2)

project(lab_9)

file(GLOB MY_SRC "src/*")
add_executable(app ${MY_SRC})
include_directories("headers/")
add_library(lib fun.cpp)
target_link_libraries(app lib)