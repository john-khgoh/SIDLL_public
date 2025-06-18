cmake_minimum_required(VERSION 3.13)
project(SIDLL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(SIDLL src/SIDLL.cpp)
target_include_directories(SIDLL PUBLIC include)