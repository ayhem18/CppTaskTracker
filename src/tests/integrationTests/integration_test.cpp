# include "../headers/tests/integration_test.h"

void TestAppIntegration::testListTasks() {

}


void TestAppIntegration::testAddTask() {  
    // a view cases to test
    int i = manager.getLastId();


    // add a task
    for (int j = 0; j < 10; j++) {
        vec_str input = {"file_name", "add", "test task"};
    
        this -> runAddCommand(input);

        // check if the task was added
        assert(manager.getTask(i + j).getDescription() == "test task");
    }       
}
    
void TestAppIntegration::testUpdateTask() {

}

void TestAppIntegration::testDeleteTask() {

}


void TestAppIntegration::run() {
    testAddTask();
    testUpdateTask();
    testDeleteTask();
    testListTasks();
}