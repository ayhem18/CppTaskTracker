/**
 * @file test_task.h
 * @author Ayhem Bouabid (ayhembouabid@yandex.com)
 * @brief a simple file to test the functionalities of the Task / TaskState and TaskSerializer classes. This is a temporary solution until I properly learn a unit-testing framework in C++ 
 * @date 2025-02-07
 */

# pragma once

# include <cassert>
# include <unistd.h> // for the sleep function

# include "../taskTracker/Task.h"
# include "../taskTracker/random_utils.h"

void test_Task_serialization();

void testTaskSetters();

void runTaskTests();

