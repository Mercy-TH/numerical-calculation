cmake_minimum_required(VERSION 3.10)

project(numerical-calculation)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#include_directories(${PROJECT_SOURCE_DIR}/3rdparty/eigen-3.4.0)
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCE
        ${PROJECT_SOURCE_DIR}/source/*.cpp
        )


add_executable(main main.cpp ${SOURCE})





