# include "random_utils.h"

int getRandomNumber(int low, int high) {
    // the following seed is copied from: 
    // https://www.geeksforgeeks.org/random-header-c-set-1generators/ 
    
    high = std::max(low, high);
    low = std::min(low, high);

    if (high == low) {
        throw std::invalid_argument("high and low are equal");
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed); // different seed every time this function is called
    return low + rand() % (high - low);
}


std::string generateRandomString(int length, const std::string& characters) {
    std::string res(length, 'a');

    for (char &c : res) {
        c = characters.at(getRandomNumber(0, characters.length()));
    }    

    return res;
}
