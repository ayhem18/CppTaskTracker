# include <iostream>
# include <string>
# include <vector>

# include "core/Task.cpp"
# include "utils/string_utils.cpp"
# include "tests.cpp"

#include <unistd.h>

void f() {
    test_trim();
    test_split();
    test_join();
}


int main() {
    // f();
    Task t = Task(1, "description");

    std::cout << t << "\n";

    TaskSerializer ser = TaskSerializer();

    std::cout << ser.serializeTask(t) << "\n";

    // sleep for 5 seconds to see the difference in the serialization (hopefully)
    sleep(10);

    t.setState(InProgress);

    std::cout << ser.serializeTask(t) << "\n";
}