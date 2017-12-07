cmake_minimum_required(VERSION 2.6)
project(colorprint)

set(INCLUDE_DIR "include")
set(SRC_DIR "src")
include_directories(${INCLUDE_DIR} ${SRC_DIR})

set(SOURCES ${SRC_DIR}/colorprint.cpp ${INCLUDE_DIR}/colorprint.h)
add_library(colorprint STATIC ${SOURCES})

add_executable(colorprint_test ${SRC_DIR}/colorprint_test.cpp)
target_link_libraries(colorprint_test colorprint)
