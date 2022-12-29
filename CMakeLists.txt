cmake_minimum_required(VERSION 3.16)

project(opengl-demo)

set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

add_definitions(-DDEBUG)

file(GLOB LIB_SOURCES src/*.cc)

add_executable(opengl-demo ${LIB_SOURCES})

target_link_libraries(opengl-demo -lSDL2 -lGL -lGLEW)
