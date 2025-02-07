# include "string_utils.h"


vec_str splitString(const std::string& str, const std::string& del) {
    // check https://cplusplus.com/reference/string/string/find/  

    // first step: check if the delimiter exists in the given string
    if (str.find(del) == std::string::npos) {
        // make sure not to return a list whose only element in an empty list
        if (str == "") {
            return vec_str{};
        }
        
        return vec_str(1, str); // a vector with the original string as the only element
    }
    
    vec_str tokens{};
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

        // truncate the first token + the length of the delimiter
        strCopy = strCopy.substr(delIndex + del.length());
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


std::string join(const vec_str & tokens, const std::string& delimiter) {
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
    int end = s.length() - 1; 
    // first the last occurrence of a white space starting from the beginning of the string
    while (std::isspace(s[start]) != 0) {
        start ++;
    }
    while (std::isspace(s[end]) != 0) {
        end --;
    }
    std::string res = s.substr(start, end-start + 1);
    return res;
}


std::string completeWhiteSpace(const std::string& s, int length) {
    if (s.length() >= length) {
        return s;
    }

    int diff = length - s.length();

    // compute the number of white spaces on each side
    int leftSpaces = diff / 2; // integer division
    int rightSpaces = diff - leftSpaces; 
    // just to make sure everything is correct (for now)
    assert (leftSpaces + rightSpaces + s.length() == length && "make sure the final length is correct");    

    return std::string(leftSpaces, ' ') + s + std::string(rightSpaces, ' ');
}


bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }

    int i1 = suffix.length() - 1;
    int i2 = str.length() - 1;

    while ((i1 >= 0) && (str[i2] == suffix[i1])) {
        i1 --;
        i2 --;
    }

    return i1 == -1;
}
