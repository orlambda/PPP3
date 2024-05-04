cmake_minimum_required(VERSION 3.28)
project(my_calculator_attempt)

set(CMAKE_CXX_STANDARD 26)

add_executable(my_calculator_attempt main.cpp
        headers.h
        Token.cpp
        Token.h
        TokenStream.cpp
        TokenStream.h
        Expression.cpp
        Expression.h
        Term.cpp
        Term.h
        Primary.cpp
        Primary.h)
