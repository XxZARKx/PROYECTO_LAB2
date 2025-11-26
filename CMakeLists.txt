cmake_minimum_required(VERSION 4.0)
project(proyecto)

set(CMAKE_CXX_STANDARD 26)

add_executable(proyecto main.cpp
        CJuego.cpp
        CJuego.h
        CJugador.cpp
        CJugador.h
        CMovimientos.h
        CMovimientos.cpp
        CTablero.cpp
        CTablero.h
        CCubo.h
        CCubo.cpp)
