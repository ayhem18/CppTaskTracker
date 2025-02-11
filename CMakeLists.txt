# as the name suggests, this is the minimum version
cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp 
        VERSION 0.1.0 
        DESCRIPTION "A simple task tracker in C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# start by adding a library 

add_library(taskTrackerLibrary 

        src/taskTracker/utils/string_utils.cpp
        src/taskTracker/utils/random_utils.cpp
        src/taskTracker/core/Task.cpp
        src/taskTracker/core/TaskManager.cpp
        src/taskTracker/core/Display.cpp
        src/taskTracker/core/app.cpp) 

target_include_directories(taskTrackerLibrary PRIVATE src/headers) 


# create an executable
add_executable(taskCLi src/main.cpp)

target_include_directories(taskCLi PRIVATE src/headers)

# add the library as a dependency
target_link_libraries(taskCLi taskTrackerLibrary)


