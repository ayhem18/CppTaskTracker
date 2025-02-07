# include "task_tests.h"

void test_Task_initialization() {
    for (int i = 0; i < 1000; i++) {
        std::string desc = generateRandomString(getRandomNumber(2, 100), ALPHABET);
        
        int taskId = getRandomNumber(1, 1000);
        Task t = Task(taskId, desc);

        assert(t.getTaskID() == taskId && "assert fails with task id");
        assert(t.getDescription() == desc && "assert fails with task description");
        assert(t.getTaskState() == TaskState::Todo && "assert fails with task state");
        assert(t.getCreationTime() == t.getLastUpdateTime() && "the creation time and the last update time must be the same");
    }
}


void testTaskSetters() {
    // this test might run for around a minute or so 
    for (int i = 0; i < 10; i++) {
        std::string desc = generateRandomString(getRandomNumber(2, 100), ALPHABET);
        
        int taskId = getRandomNumber(1, 1000);
        Task t = Task(taskId, desc);

        time_t creationTime = t.getCreationTime(); 

        // sleep for between (1, and 5) seconds
        int sleepTime = getRandomNumber(1, 5);
        sleep(sleepTime);

        t.setState(TaskState::InProgress);
        assert(t.getTaskState() == TaskState::InProgress && "assert fails with task state");


        double diff= difftime(t.getLastUpdateTime(), creationTime);        

        // make sure the difference is close to the sleep time
        assert(abs(diff - sleepTime) < 0.1 && "the last update time must be close to the sleep time");

        // test the setDescription method
        std::string newDesc = generateRandomString(getRandomNumber(2, 100), ALPHABET);

        // sleep again
        int sleepTime2 = getRandomNumber(1, 5); 
        sleep(sleepTime2);

        t.setDescription(newDesc);
        assert(t.getDescription() == newDesc && "assert fails with task description");

        diff= difftime(t.getLastUpdateTime(), creationTime);        
        // make sure the difference is close to the sleep time
        assert(abs(diff - (sleepTime + sleepTime2)) < 0.1 && "make sure the last update is consistent even with multiple calls to the setters");
    }
}

void testTaskSerialization() {
    for (int i = 0; i < 100; i++) {
        std::string desc = generateRandomString(getRandomNumber(2, 100), CHARACTERS);
        int taskId = getRandomNumber(1, 1000);
        Task t = Task(taskId, desc);

        TaskSerializer ser = TaskSerializer();

        std::string serialized = ser.serializeTask(t);

        Task t2 = ser.deserializeTask(serialized);

        assert(t == t2 && "assert fails with either serialization or deserialization");
    }
}


void runTaskTests() {
    test_Task_initialization();
    testTaskSetters(); 
    testTaskSerialization();
}


