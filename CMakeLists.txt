cmake_minimum_required(VERSION 3.19)
project(lox__)

set(CMAKE_CXX_STANDARD 17)

add_executable(lox__ main.cpp token.hpp token.cpp scanner.hpp)