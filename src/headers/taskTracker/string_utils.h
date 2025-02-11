# pragma once

# include <string>
# include <vector>
# include <algorithm>
# include <cstring>
# include <numeric>
# include <cmath> // used for floor and ceil functions
# include <cassert>

const std::string& CHARACTERS
    = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
        "wxyz0123456789";

const std::string& ALPHABET = "abcdefghijklmnopqrstuvwxyz";

const std::string& DELIMITERS = ".,!?:;";


using vec_str = std::vector<std::string>;

vec_str splitString(const std::string& str, const std::string& del);

std::string toLowerCase(const std::string& str);

std::string toUpperCase(const std::string& str);

std::string join(const vec_str & tokens, const std::string& delimiter);

std::string trim(const std::string& s);

std::string completeWhiteSpace(const std::string& s, int length);

bool endsWith(const std::string& str, const std::string& suffix);
