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
# include "utils/string_utils.h"

int getRandomNumber(int low, int high) {
    // the following seed is copied from: 
    // https://www.geeksforgeeks.org/random-header-c-set-1generators/ 

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed); // different seed every time this function is called
    return low + rand() % (high - low);
}


std::string generateRandomString(int length) {
    const std::string& CHARACTERS
        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
          "wxyz0123456789";
    std::string res(length, 'a');

    for (char &c : res) {
        c = CHARACTERS.at(getRandomNumber(0, CHARACTERS.length()));
    }    

    return res;
}

void test_trim() {
    for (int i = 1; i <= 1000; i++) {
        std::string s = generateRandomString(i);
        // add random whitespaces before and after the original string
        assert(trim(s) == s && "The trim function should return the same string for a string with no trailing whitespaces");

        int num_spaces = getRandomNumber(2, 10);
        std::string s_space = std::string(num_spaces, ' ') + s + std::string(num_spaces, '\t');

        assert(trim(s_space) == s && "the trim function fails !!!");
    }
}


void test_split() {
    std::string s1 = "I am a piece of text";
    std::vector<std::string> v1 {"I", "am", "a", "piece", "of", "text"};
    assert(v1 == splitString(s1, " ") && "assert fails with simple case");

    std::string s2 = "bbbabbaaab";
    std::vector<std::string> v2 {"bbb", "bb", "", "", "b"};
    assert(v2 == splitString(s2, "a") && "assert fails with empty tokens");

    std::string s3 = "aabaab";
    std::vector<std::string> v3 {"aa", "aa"};
    assert(v3 == splitString(s3, "b") && "assert fails when string ends with the delimiter");
}


void test_join() {
    std::vector<std::string> v1 {"a", "b", "c", "d"};
    std::string s1 {"a_b_c_d"};
    assert (s1 == join(v1, "_") && "join fails with basic cases");

    std::vector<std::string> v2 {"a", "b", "c", "d"};
    std::string s2 {"a__b__c__d"};
    assert (s2 == join(v2, "__") && "join fails with basic cases");

    std::vector<std::string> v3 {"a"};
    std::string s3 {"a"};
    assert (s3 == join(v3, "__") && "join fails with basic cases");
}


void run_string_tests() {
    test_trim();
    test_split();
    test_join();
}