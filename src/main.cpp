# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>
# include <filesystem>

// # include "core/TaskManager.h"
# include "core/app.h"


namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    // the default file name 
    fs::path defaultFileName = fs::current_path().append("data.txt");

    App app(defaultFileName.string());

    // until I figure out how to make the executable, use the following code 
    std::vector<std::string> arguments = {"list"};

    app.runCommand(arguments);
}