# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>
# include <filesystem>

# include "headers/taskTracker/app.h"


namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    std::cout << "running some code" << std::endl;

    // the default file name 
    fs::path filePath = fs::current_path().append("data.txt");


    std::ofstream file(filePath, std::ios::app);
    if (!file) {
        throw std::runtime_error("Could not create or open file: " + filePath.string());
    }
    file.close(); 


    std::cout << filePath.string() << std::endl; 

    App app(filePath.string());

    // until I figure out how to make the executable, use the following code 
    std::vector<std::string> arguments = {"file_name", "list"};

    app.runCommand(arguments);
}