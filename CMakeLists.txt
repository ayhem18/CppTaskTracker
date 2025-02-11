# as the name suggests, this is the minimum version
cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp 
        VERSION 0.1.0 
        DESCRIPTION "A simple task tracker in C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# start by adding a library 


add_executable(TaskTrackerCpp 
        src/utils/string_utils.cpp
        src/utils/random_utils.cpp
        src/core/Task.cpp
        src/core/TaskManager.cpp
        src/core/Display.cpp
        src/core/app.cpp
        src/main.cpp
        )


target_include_directories(TaskTrackerCpp PRIVATE src/core src/utils src/tests)
