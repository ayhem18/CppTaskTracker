/**
 * @file tests.cpp
 * @author Ayhem Bouabid (ayhembouabid@yandex.com)
 * @brief a simple file to verify the correctness of the single functionalities across the program. This is a temporary solution until I properly learn a unit-testing framework in C++ 
 * @date 2025-02-03
 */

# pragma once

# include <string>
# include <cstdlib>
# include <chrono>
# include <cassert> // for the assert function

# include "../taskTracker/string_utils.h"
# include "../taskTracker/random_utils.h"

void test_trim();

void test_split();

void test_join();   

void runStringTests();

