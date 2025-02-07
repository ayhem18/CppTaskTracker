cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskTrackerCpp 
            src/main.cpp 
            
            src/core/Task.cpp 
            src/core/Task.h            
            
            src/utils/string_utils.h
            src/utils/string_utils.cpp
            
            src/tests/string_tests.h
            src/tests/string_tests.cpp
            )