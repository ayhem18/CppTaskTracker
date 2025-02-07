# include <string>
# include <iostream>
# include <vector>
# include <unistd.h>

# include "core/Task.cpp"
# include "utils/string_utils.cpp"
# include "utils/random_utils.cpp"
# include "tests/string_tests.cpp"
# include "tests/task_tests.cpp"

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


void run_tests() {
    run_string_tests();
    runTaskTests();
}




int main() {
    run_tests();
}