# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>
# include <filesystem>

# include "headers/taskTracker/app.h"
# include "headers/tests/test_suit.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    if (argc > 1 && std::string(argv[1]) == "test") {
        runAllTests();
        return 0;
    }

    
    // the default file name 
    fs::path filePath = fs::path(__FILE__).parent_path().append("data.txt");

    if (!fs::exists(filePath)) {
        std::ofstream file(filePath, std::ios::app);
        file << "0" << std::endl;
        file.close();
    }

    App app(filePath.string());

    vec_str args {argv, argv + argc};

    app.runCommand(args);
}