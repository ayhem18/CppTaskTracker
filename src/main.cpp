# include <iostream>
# include <string>
# include <vector>

# include "core/Task.cpp"
# include "utils/string_utils.cpp"
# include "tests.cpp"

#include <unistd.h>


void fun() {
    Task t = Task(1, "description");

    std::cout << t << "\n";

    TaskSerializer ser = TaskSerializer();

    std::cout << ser.serializeTask(t) << "\n";

    // sleep for 5 seconds to see the difference in the serialization (hopefully)

    sleep(5);

    t.setState(InProgress);

    std::string taskRep = ser.serializeTask(t);

    std::cout << taskRep << "\n";

    Task newTask{ser.deserializeTask(taskRep)};

    std::cout << std::boolalpha << (t == newTask) << "\n";

}



int main() {

}