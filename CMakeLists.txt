cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD_17)
set (CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_COMPILER g++-9)
set(CMAKE_C_COMPILER gcc-9)

find_package( OpenCV REQUIRED )

add_executable(Project
        main.cpp
        indexer.cpp
        comparison_algorithm.cpp Image.cpp Image.h)

target_link_libraries( Project ${OpenCV_LIBS})