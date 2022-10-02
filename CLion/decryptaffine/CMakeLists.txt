cmake_minimum_required(VERSION 3.20)
project(decryptaffine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


add_executable(decryptaffine main.cpp)
