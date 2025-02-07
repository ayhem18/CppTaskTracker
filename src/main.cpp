# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>

# include "core/Task.cpp"
# include "core/TaskManager.cpp"

# include "utils/string_utils.cpp"
# include "utils/random_utils.cpp"
# include "tests/string_tests.cpp"
# include "tests/task_tests.cpp"
# include "tests/taskManager_tests.cpp"

# include <filesystem>

// # include "tests/taskManager_tests.h"
// # include "tests/task_tests.h"
// # include "tests/string_tests.h"

void fun() {

}


void run_tests() {
    std::cout << "Running string tests" << std::endl;
    run_string_tests();

    std::cout << "Running task tests" << std::endl;
    runTaskTests();

    std::cout << "Running task manager tests" << std::endl;
    runTaskManagerTests();

    std::cout << "All tests passed !!" << "\n";
}  


int main(int argc, char* argv[]) {
    
}