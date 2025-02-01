# include "string_utils.h"
# include <algorithm>
# include <cstring>
# include <numeric>


std::vector<std::string> splitString(const std::string& str, const std::string& del) {
    // check https://cplusplus.com/reference/string/string/find/  

    // first step: check if the delimiter exists in the given string
    if (str.find(del) == std::string::npos) {
        // make sure not to return a list whose only element in an empty list
        if (str == "") {
            return std::vector<std::string>{};
        }
        
        return std::vector<std::string>(1, str); // a vector with the original string as the only element
    }
    
    std::vector<std::string> tokens{};
    std::string strCopy = str;
    
    while (true) {
        std::size_t delIndex(strCopy.find(del));

        if (delIndex == std::string::npos) {
            // there are two cases: it either that strCopy is empty at this point of the program
            // in this case: 'str' ends with a delimiter and nothing should done
            // otherwise, we found a valid final token 
            if (strCopy != "") {
                tokens.push_back(strCopy);
            }            
            break;
        }

        // add the token
        tokens.push_back(strCopy.substr(0, delIndex));

        // truncate the first token + 
        strCopy = strCopy.substr(delIndex + del.size());
    }

    return tokens;
}


std::string toLowerCase(const std::string& s) {
    std::string res = s;

    for (char& c: res) {
        c = tolower(c);
    }
    return res;
}

std::string toUpperCase(const std::string& s) {
    std::string res = s;

    for (char& c: res) {
        c = toupper(c);
    }
    return res;
}


std::string join(const std::vector<std::string> & tokens, const std::string& delimiter) {
    if (tokens.empty()) {
        return "";
    }

    return std::accumulate(
            std::next(tokens.begin()), 
            tokens.end(), 
            tokens[0], 
            [delimiter](std::string a, std::string b) {
                return a + delimiter + b;
            }
    );
}

std::string trim(const std::string& s) {
    int start = 0;
    int end = s.size() - 1;
    // first the last occurrence of a white space starting from the beginning of the string
    while (std::isspace(s[start])) {
        start ++;
    }
    while (std::isspace(s[end])) {
        end --;
    }
    return s.substr(start, end + 1);
}
