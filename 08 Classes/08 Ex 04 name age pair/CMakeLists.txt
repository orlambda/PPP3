cmake_minimum_required(VERSION 3.28)
project(08_Ex_04_name_age_pair)

set(CMAKE_CXX_STANDARD 20)

add_executable(08_Ex_04_name_age_pair main.cpp
        Name_age_pairs.cpp
        Name_age_pairs.h
        Name_age_pair.cpp
        Name_age_pair.h)
