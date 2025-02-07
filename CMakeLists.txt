cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskTrackerCpp 
            src/main.cpp 
            
            src/core/Task.cpp 
            src/core/Task.h            

            src/core/TaskManager.cpp
            src/core/TaskManager.h

            src/utils/string_utils.h
            src/utils/string_utils.cpp
            
            src/utils/random_utils.h
            src/utils/random_utils.cpp

            src/tests/string_tests.h
            src/tests/string_tests.cpp

            src/tests/task_tests.h
            src/tests/task_tests.cpp
        
            src/tests/taskManager_tests.h
            src/tests/taskManager_tests.cpp
)