cmake_minimum_required(VERSION 2.6)
project(container_print)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(INCLUDE_DIR "include")
set(SRC_DIR "src")
include_directories(${INCLUDE_DIR} ${SRC_DIR})

set(SOURCES ${SRC_DIR}/container_print.cpp ${INCLUDE_DIR}/container_print.hpp)
add_library(container_print STATIC ${SOURCES})

add_executable(container_print_test ${SRC_DIR}/container_print_test.cpp)
target_link_libraries(container_print_test container_print)
