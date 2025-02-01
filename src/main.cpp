# include <iostream>
# include <string>
# include <vector>

# include "core/Task.cpp"
# include "utils/string_utils.cpp"


int main() {
    std::string s1 = "aaa";

    std::string del = "bb";

    std::vector<std::string> tokens = splitString(s1, del);
    
    std::cout << "output start" << "\n";

    for (std::string & s: tokens) {
        std::cout << s << "\n";
    }
}