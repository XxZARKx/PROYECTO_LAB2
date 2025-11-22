cmake_minimum_required(VERSION 4.0)
project(Dots_and_Boxes)

set(CMAKE_CXX_STANDARD 26)

add_executable(Dots_and_Boxes main.cpp
        CMovimientos.cpp
        CMovimientos.h
        CJuego.cpp
        CJuego.h)
