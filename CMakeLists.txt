cmake_minimum_required(VERSION 3.21)
project(Zero)

set(CMAKE_CXX_STANDARD 14)

add_executable(Zero main.cpp Box.h Container.h Box.cpp Container.cpp)
