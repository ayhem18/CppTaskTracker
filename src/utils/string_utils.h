#ifndef SRC_UTILS_STRING_UTILS_H
#define SRC_UTILS_STRING_UTILS_H

# include <string>
# include <vector>

std::vector<std::string> splitString(const std::string& str, const std::string& del);

std::string toLowerCase(const std::string& str);

std::string toUpperCase(const std::string& str);

std::string join(const std::vector<std::string> & tokens);

std::string trim(const std::string& s);

#endif 

