# include <iostream>
# include <string>
# include <vector>

# include "core/Task.cpp"
# include "utils/string_utils.cpp"
# include "tests.cpp"


void f() {
    for (int i = 0; i <= 10; i++) {
        std::cout << generateRandomString(i) << "\n";
    }
}



int main() {
    f();
    // std::string s1 = "aaa";

    // std::string del = "bb";

    // std::cout << s1 << "\n";
 
    // std::vector<std::string> tokens = splitString(s1, del);
    
    // std::cout << "output start" << "\n";

    // for (std::string & s: tokens) {
    //     std::cout << s << "\n";
    // }
}