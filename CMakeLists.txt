cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD_17)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs")
set(CMAKE_CXX_COMPILER g++-9)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenCV REQUIRED )
find_package(Qt5 COMPONENTS Widgets REQUIRED)
if ( NOT Qt5_FOUND )
    message(FATAL_ERROR "Package QT not found!")
endif( )


# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}" ${Qt5Widgets_INCLUDES})

#add_definitions(${Qt5Widgets_DEFINITIONS})




add_executable(Project
        main.cpp
        indexer.cpp
        comparison_algorithm.cpp Image.cpp Window.cpp Window.h)


target_link_libraries(Project ${Qt5Widgets_LIBRARIES} ${OpenCV_LIBS} -lstdc++fs)
