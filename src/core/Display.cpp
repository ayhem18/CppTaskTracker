# include "Display.h"

vec_str Display::longElementRepresentation(const std::string& str) {
    std::string strCopy {str};

    vec_str res {};

    while (strCopy.length() > this -> charsByElement) {
        res.push_back(strCopy);
        strCopy = strCopy.substr();
    }

    return res;
}


vec_str Display::elementRepresentation(const std::string& str) {
    // step1: split a string using spaces
    vec_str tokens {splitString(str, " ")};

    vec_str lines{};

    int currentLength = 0;
    std::string line;

    for (const std::string& t: tokens) {
        // define the current length
        // check if the new token + the current length exceeds the limit for each element


        currentLength += static_cast<int> (currentLength == 0) * 1 + t.length();

        if (currentLength <= this->charsByString) {
            if (currentLength != 0) {
                line += " ";
            }
            line += t;
        }
        else {
            // this means the line limit was reached 
            // before saving the current line 

        }

    }

}


std::string Display::lineRepresentation(const vec_str& elements) {

}
