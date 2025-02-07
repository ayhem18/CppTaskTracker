/**
 * @file tests.cpp
 * @author Ayhem Bouabid (ayhembouabid@yandex.com)
 * @brief a simple file to verify the correctness of the single functionalities across the program. This is a temporary solution until I properly learn a unit-testing framework in C++ 
 * @date 2025-02-03
 */

# include <string>
# include <cstdlib>
# include <chrono>
#include <cassert> // for the assert function
# include "../utils/string_utils.h"

const std::string& CHARACTERS
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
        "wxyz0123456789";

const std::string& ALPHABET = "abcdefghijklmnopqrstuvwxyz";

const std::string& DELIMITERS = ".,!?:;";

int getRandomNumber(int low, int high);

std::string generateRandomString(int length, const std::string& characters);

void test_trim();

void test_split();

void test_join();   

void run_string_tests();