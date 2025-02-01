# include <string>
# include <vector>

# include "string_utils.h"


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
        int delIndex{strCopy.find(del)};

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
        strCopy = strCopy.substr(0, delIndex + del.size());
    }

    return tokens;
}


