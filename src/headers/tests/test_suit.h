# pragma once

# include "string_tests.h"
# include "task_tests.h"
# include "taskManager_tests.h"
# include "display_tests.h"
# include "input_processing_tests.h"

# include <filesystem>

void runAllTests() {
    // std::cout << "Running string tests" << std::endl;   
    // runStringTests();
    
    // std::cout << "Running task tests" << std::endl;
    // runTaskTests();
    
    // std::cout << "Running task manager tests" << std::endl;
    // runTaskManagerTests();  

    
    TestDisplay d {};
    d.run();

    std::string file = std::filesystem::path(__FILE__).parent_path().append("data.txt").string();

    // create file if it does not exist
    if (!std::filesystem::exists(file)) {
        std::ofstream f(file);
        f << "0" << std::endl;
        f.close();
    }

    TestAppInputProcessing appInputProcessing {file};
    appInputProcessing.run();

    std::cout << "All tests passed" << std::endl;

    std::filesystem::remove(file);
}