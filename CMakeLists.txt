cmake_minimum_required(VERSION 3.14)
project(Project)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )

add_executable(Project
        main.cpp
        image_loader.cpp
        comparison_algorithm.cpp)

target_link_libraries( Project ${OpenCV_LIBS})