cmake_minimum_required(VERSION 2.6)
project(container_print_est)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(container_print SHARED container_print.cpp)

add_executable(test container_print_test.cpp)
target_link_libraries(test container_print)
