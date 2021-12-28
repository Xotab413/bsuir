cmake_minimum_required (VERSION 3.2)

project(lab_5)


file(GLOB MY_SRC "src/*")
include_directories("headers/")
add_executable(app ${MY_SRC})
add_library(lib fun.cpp)
target_link_libraries(app lib)