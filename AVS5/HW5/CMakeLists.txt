cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_C_FLAGS "-pthread")
set(CMAKE_C_STANDARD 99)

add_executable(untitled4 main.cpp Gentleman.cpp Gentleman.h Hotel.cpp Hotel.h Lady.cpp Lady.h Room.h Room.cpp Gentleman.cpp Gentleman.h Hotel.cpp Hotel.h Lady.cpp Lady.h Room.cpp Room.h)
