/**
 * @file tests.cpp
 * @author Ayhem Bouabid (ayhembouabid@yandex.com)
 * @brief a simple file to verify the correctness of the single functionalities across the program. This is a temporary solution until I properly learn a unit-testing framework in C++ 
 * @date 2025-02-03
 */

# include "../headers/tests/string_tests.h"


void test_trim() {
    for (int i = 1; i <= 1000; i++) {
        std::string s = generateRandomString(i, string_utils::CHARACTERS);
        // add random whitespaces before and after the original string
        assert(trim(s) == s && "The trim function should return the same string for a string with no trailing whitespaces");

        int num_spaces = getRandomNumber(2, 10);
        std::string s_space = std::string(num_spaces, ' ') + s + std::string(num_spaces, '\t');

        assert(trim(s_space) == s && "the trim function fails !!!");
    }
}


void test_split() {
    // a few manual tests

    std::string s1 = "I am a piece of text";
    vec_str v1 {"I", "am", "a", "piece", "of", "text"};
    assert(v1 == splitString(s1, " ") && "assert fails with simple case");

    std::string s2 = "bbbabbaaab";
    vec_str v2 {"bbb", "bb", "", "", "b"};
    assert(v2 == splitString(s2, "a") && "assert fails with empty tokens");

    std::string s3 = "aabaab";
    vec_str v3 {"aa", "aa"};
    assert(v3 == splitString(s3, "b") && "assert fails when string ends with the delimiter");

}


void test_join() {
    vec_str v1 {"a", "b", "c", "d"};
    std::string s1 {"a_b_c_d"};
    assert (s1 == join(v1, "_") && "join fails with basic cases");

    vec_str v2 {"a", "b", "c", "d"};
    std::string s2 {"a__b__c__d"};
    assert (s2 == join(v2, "__") && "join fails with basic cases");

    vec_str v3 {"a"};
    std::string s3 {"a"};
    assert (s3 == join(v3, "__") && "join fails with basic cases");
}


void test_join_and_split() {
        // some more semi-automated tests
    
    for (int i = 1; i <= 1000; i++) {
        int n = getRandomNumber(3, 100);
        vec_str tokens(n); // generate a vector with 'n' elements 

        for (std::string& t : tokens) {
            t = generateRandomString(getRandomNumber(2, 10), string_utils::ALPHABET);
        }
        
        // join the tokens with a non-alphanumeric character
        // instead of using a single character, use a string of a random length 
        int delimiter_length = getRandomNumber(1, 5);

        // generate a random delimiter with the length specified above
        std::string delimiter = generateRandomString(delimiter_length, string_utils::DELIMITERS);

        // join the tokens with the delimiter
        std::string s = join(tokens, delimiter);

        // split the string using the delimiter
        vec_str v = splitString(s, delimiter);

        // assert the v is the same as the original tokens
        assert(v == tokens && "assert fails with random string"); 
    }
}

void test_complete_white_space() {
    for (int i = 1; i <= 1000; i++) {

        int n = getRandomNumber(5, 100);
        int n_greater = getRandomNumber(n + 1, 2 * n);
        int n_less = getRandomNumber(1, n - 1);

        // generate a random string with n characters
        std::string s = generateRandomString(n, string_utils::ALPHABET);
        std::string s_greater = completeWhiteSpace(s, n_greater);
        std::string s_less = completeWhiteSpace(s, n_less);

        assert(s_less == s && "assert must return the same string if the length is less than that of the original string");

        // assert the length of the completed strings are the same as the length specified
        assert(s_greater.length() == n_greater && "assert fails with complete white space");

        // count the number of white spaces in the completed string
        int count_greater = std::count(s_greater.begin(), s_greater.end(), ' ');

        assert (count_greater == n_greater - n && "assert fails with complete white space"); 
    }
}


void runStringTests() {
    test_trim();
    test_split();
    test_join();
    test_join_and_split();
    test_complete_white_space();
}