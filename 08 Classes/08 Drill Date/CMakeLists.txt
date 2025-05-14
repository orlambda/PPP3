cmake_minimum_required(VERSION 3.28)
project(08_Drill_Date)

set(CMAKE_CXX_STANDARD 20)

add_executable(08_Drill_Date main.cpp
        Day.cpp
        Day.h
        Month.cpp
        Month.h
        Year.cpp
        Year.h
        Date.cpp
        Date.h)
