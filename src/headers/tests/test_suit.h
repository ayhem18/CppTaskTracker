# pragma once

# include "string_tests.h"
# include "task_tests.h"
# include "taskManager_tests.h"

void runAllTests() {
    std::cout << "Running string tests" << std::endl;   
    runStringTests();
    
    // std::cout << "Running task tests" << std::endl;
    // runTaskTests();
    
    std::cout << "Running task manager tests" << std::endl;
    runTaskManagerTests();  

    std::cout << "All tests passed" << std::endl;
}