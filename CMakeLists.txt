# as the name suggests, this is the minimum version
cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp 
        VERSION 0.1.0 
        DESCRIPTION "A simple task tracker in C++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskTrackerCpp src/main.cpp)

target_include_directories(TaskTrackerCpp PRIVATE src/core src/utils src/tests)


# add_executable(TaskTrackerCpp             

#     src/utils/string_utils.h
#     src/utils/string_utils.cpp

#     src/utils/random_utils.h
#     src/utils/random_utils.cpp

#     src/core/Task.cpp 
#     src/core/Task.h            

#     src/core/TaskManager.cpp
#     src/core/TaskManager.h

#     src/core/Display.h
#     src/core/Display.cpp

#     src/core/app.h  
#     src/core/app.cpp


#     src/tests/string_tests.h
#     src/tests/string_tests.cpp

#     src/tests/task_tests.h
#     src/tests/task_tests.cpp

#     src/tests/taskManager_tests.h
#     src/tests/taskManager_tests.cpp

#     src/main.cpp 
# )
