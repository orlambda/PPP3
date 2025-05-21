cmake_minimum_required(VERSION 3.28)
project(08_Ex_05_09_Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(08_Ex_05_09_Library main.cpp
        Book.cpp
        Book.h
        Patron.cpp
        Patron.h)
