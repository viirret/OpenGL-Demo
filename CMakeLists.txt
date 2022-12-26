cmake_minimum_required(VERSION 3.16)

project(opegl-demo)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

add_definitions(-DDEBUG)

file(GLOB LIB_SOURCES src/*.cc)

add_executable(opegl-demo ${LIB_SOURCES})

target_link_libraries(opegl-demo -lSDL2 -lGL -lGLEW)
