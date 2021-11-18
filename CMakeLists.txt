cmake_minimum_required(VERSION 3.19)
project(loxpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(loxpp main.cpp token.hpp token.cpp scanner.hpp error.cpp error.hpp scanner.cpp)