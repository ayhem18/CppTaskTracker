# include <iostream>

# include "core/Task.cpp"
# include "core/Task.h"


int main() {
    // let's create a Task object
    Task t = Task("first task", "some_task_description");

    std::cout << t ;
}