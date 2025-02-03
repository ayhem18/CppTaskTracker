/**
 * @file tests.cpp
 * @author Ayhem Bouabid (ayhembouabid@yandex.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-03
 * 
 * This is a simple file to verify the correctness of the single functionalities across the program. This is a temporary solution until I properly learn a unit-testing framework in C++ 
 */

# include <string>
# include <cstdlib>
# include <time.h>
# include <algorithm>


int getRandomNumber(int low, int high) {
    srand(time(0)); // different seed every time this function is called
    return low + rand() % (high - low);
}


std::string generateRandomString(int length) {
    const std::string& CHARACTERS
        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
          "wxyz0123456789";

    std::string res(length, 'a');
    // return res;
    return std::transform(res.begin(), res.end(), std::string{}, [CHARACTERS] (char c) {
        return CHARACTERS.at(getRandomNumber(0, CHARACTERS.length()));
        }
    );
}


void test_split() {
    
}