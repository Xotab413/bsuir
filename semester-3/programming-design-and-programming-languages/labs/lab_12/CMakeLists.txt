cmake_minimum_required (VERSION 3.2)

project(lab_12)

file(GLOB MY_SRC "src/*")
add_executable(app ${MY_SRC})
include_directories("headers/")
add_library(lib Library.cpp)
target_link_libraries(app lib)
