# include "Display.h"

vec_str Display::longElementRepresentation(const std::string& str) const {
    std::string strCopy {str};

    vec_str res {};

    // denoting this -> charsByElement as "n"
    while (strCopy.length() > this -> charsByElement) {
        // add the first n - 1 characters of the string + a dash
        res.push_back(strCopy.substr(0, this -> charsByElement - 1) + "-");
        // update the string by truncating the first n - 1 characters
        strCopy = strCopy.substr(this -> charsByElement - 1);
    }

    // at this point, the string strCopy is less than n characters long
    // if not empty, then add it to the lines
    if (! strCopy.empty()) {
        res.push_back(strCopy);
    }

    return res;
}


vec_str Display::elementRepresentation(const std::string& str) const {
    // step1: split a string using spaces
    vec_str tokens {splitString(str, " ")};

    vec_str lines{};

    int currentLength = 0;
    std::string line;

    for (const std::string& t: tokens) {
        // define the current length
        // check if the new token + the current length exceeds the limit for each element

        currentLength += static_cast<int> (currentLength == 0) * 1 + t.length();

        if (currentLength <= this->charsByElement) {
            if (currentLength != 0) {
                line += " ";
            }
            line += t;
        }

        else {
            // this means the limit was reached 
            lines.push_back(line);
            // check if the length of the new token is greater than the limit 
            if (t.length() > this -> charsByElement) {
                // if it is, split the token by calling the longElementRepresentation function
                vec_str tokenSplit =  this->longElementRepresentation(t);
                lines.insert(lines.end(), tokenSplit.begin(), tokenSplit.end() - 1);
                // set the new "line" to the last element of the vector (because it is known to have less than n characters)
                line = *(tokenSplit.end() - 1);
                // update the current length
                currentLength = line.length();
            }

            else {
                line = t;
                currentLength = t.length();
            }
        }
    }

    lines.push_back(line);

    return lines;   
}


std::string Display::displayLine(const vec_str& elements) const {
    // step1: prepare the lines for each element
    std::vector<vec_str> elementLines {};
    for (const std::string& e: elements) {
        elementLines.push_back(this -> elementRepresentation(e));
    }

    // step2: find the element with the maximum number of lines
    size_t maxLength = 0; // Variable to store the maximum length
    for (const auto& lineVec : elementLines) {
        maxLength = std::max(maxLength, lineVec.size()); // Update maxLength if current vector is longer
    }

    vec_str displayLines {};

    for (int i = 0; i < maxLength; i ++ ) {
    
        // the ith displayed line is the result of extracting the i-th element from each of the vectors in elementLines
        vec_str ithLine {};

        for (const auto& lineVec : elementLines) {
            if (lineVec.size() > i) {
                ithLine.push_back(lineVec[i]);
            } 
            else {
                ithLine.push_back(" ");
            }
        }

        displayLines.push_back(join(ithLine, this -> delimiter));
    }

    return join(displayLines, "\n");    
}


std::string Display::getFormattedTime(const time_t& time) const {
    std::tm* tm = std::localtime(&time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);
    return std::string(buffer); 
}