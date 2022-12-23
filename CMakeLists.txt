cmake_minimum_required(VERSION 3.16)

project(example)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

add_definitions(-DDEBUG)

file(GLOB LIB_SOURCES src/*.cc)

add_executable(example ${LIB_SOURCES})

target_link_libraries(example -lSDL2 -lGL -lGLEW)
