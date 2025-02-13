# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>
# include <filesystem>

# include "headers/taskTracker/app.h"
# include "headers/tests/test_suit.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    // if (argc > 1 && std::string(argv[1]) == "test") {
    //     runAllTests();
    //     return 0;
    // }

    runAllTests();

    // std::cout << "running some code" << std::endl;

    // // the default file name 
    // fs::path filePath = fs::current_path().append("data.txt");


    // if (!fs::exists(filePath)) {
    //     std::ofstream file(filePath, std::ios::app);
    //     file << "0" << std::endl;
    //     file.close();
    // }

    // std::cout << filePath.string() << std::endl; 

    // App app(filePath.string());


    // std::vector<std::string> arguments = {"file_name", "list"};
    // app.runCommand(arguments);

    // arguments  =  {"file_name", "add", "test task"};
    // app.runCommand(arguments);

    // arguments  =  {"file_name", "list"};
    // app.runCommand(arguments);
    // arguments  =  {"file_name", "update", "1", "test task 2"};

    // app.runCommand(arguments);

    // arguments  =  {"file_name", "list"};
    // app.runCommand(arguments);

    // arguments  =  {"file_name", "delete", "1"};
    // app.runCommand(arguments);

    // arguments  =  {"file_name", "list"};
    // app.runCommand(arguments);


}