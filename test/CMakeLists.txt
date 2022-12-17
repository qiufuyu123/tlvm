cmake_minimum_required(VERSION 3.20)
project(test)
set(SRC_LIST main.c)
include_directories(../include)

add_executable(test ${SRC_LIST})
target_link_libraries(test ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libtlvm.so)