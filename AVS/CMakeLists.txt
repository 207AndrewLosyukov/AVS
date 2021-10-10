cmake_minimum_required(VERSION 3.20)
project(AVS)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        AVS
        main.cpp
        shape.cpp
        shape.h
        triangle.cpp
        triangle.h
        circle.cpp
        circle.h
        container.cpp
        container.h
        exceptions.cpp
        exceptions.h
        point.h
        random.cpp
        random.h
        rectangle.cpp
        rectangle.h
)
