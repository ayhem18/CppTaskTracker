# as the name suggests, this is the minimum version
cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp 
        VERSION 0.1.0 
        DESCRIPTION "A simple task tracker in C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# add the library with the main source code
add_library(taskTrackerLibrary 

        src/taskTracker/utils/string_utils.cpp
        src/taskTracker/utils/random_utils.cpp
        src/taskTracker/core/Task.cpp
        src/taskTracker/core/TaskManager.cpp
        src/taskTracker/core/Display.cpp
        src/taskTracker/core/app.cpp
        
        src/tests/string_tests.cpp
        src/tests/task_tests.cpp
        src/tests/taskManager_tests.cpp
        )


# the library depends on the headers defined in the src/headers directory 
# include them in the compilation of the library
target_include_directories(taskTrackerLibrary PRIVATE src/headers) 

# there is only one executable: the src/main.cpp
add_executable(taskCLi src/main.cpp)

# the executable depends on the headers defined in the src/headers directory 
# include them in the compilation of the executable
target_include_directories(taskCLi PRIVATE src/headers)

# for the executable to actually run, the linker should know about the library target
target_link_libraries(taskCLi taskTrackerLibrary)


