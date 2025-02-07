# include "taskManager_tests.h"


std::string createTempTxtFile(const std::string& fileName, const std::string& content) {
    std::string filePath;

    if (endsWith(fileName, ".txt")) {
        filePath = fileName;
    } else {
        filePath = fileName + ".txt";
    }

    std::ofstream file(filePath);
    if (! content.empty()) {
        file << content;
    }
    file.close();

    return filePath;
}

void deleteTempTxtFile(const std::string& filePath) {
    std::remove(filePath.c_str());
}   


void testTaskManagerReadFiles1() {
    // create  an empty file
    std::string file = "temp.txt";
    const std::string filePath = createTempTxtFile(file, "");


    try{ 
        TaskManager tm {filePath};
        assert(false && "task manager should throw an exception but didn't");
    } catch (const std::invalid_argument& e) {    // create a file with the last id
        // remove the file  
        deleteTempTxtFile(filePath);
    }
    

    for (int i = 0; i < 100; i++) {

        const std::string filePathWithLastId = createTempTxtFile(file, std::to_string(i) + "\n");
        
        try {
            TaskManager manager {filePathWithLastId};
            // remove the file before the assertion 
            deleteTempTxtFile(filePathWithLastId);
            assert(manager.getLastId() == i && "task manager should have the correct last id");
            
        } catch (const std::invalid_argument& e) {
            deleteTempTxtFile(filePathWithLastId);
            assert(false && "task manager should not throw an exception");
        }
    }

}

void testTaskManagerReadFiles2() {
    vt tasks;

    time_t t1 = time(nullptr); // save the time before creating the toDo tasks

    // the first 5 tasks are in the toDo state      
    for (int i = 0; i < 5; i++) {
        tasks.push_back(Task(i, "task_" + std::to_string(i)));
    }

    time_t t2 = time(nullptr); // save the time before creating the Inprogress tasks

    // the next 5 tasks are in the inProgress state
    for (int i = 5; i < 10; i++) {
        Task t = Task(i, "task_" + std::to_string(i));
        t.setState(TaskState::InProgress);
        tasks.push_back(t);
    }

    time_t t3 = time(nullptr); // save the time before creating the completed tasks

    // the next 5 tasks are in the done state
    for (int i = 10; i < 15; i++) { 
        Task t = Task(i, "task_" + std::to_string(i));
        t.setState(TaskState::Completed);
        tasks.push_back(t);
    }

    TaskSerializer ser = TaskSerializer();

    vec_str lines {"15"}; // the first line

    for (Task t : tasks) {
        lines.push_back(ser.serializeTask(t));
    }

    std::string content = join(lines, "\n");

    fs::path path = fs::current_path().append("tests/fileSamples/sample1.txt");

    // create a file with the tasks
    std::string filePath = createTempTxtFile(path.string(), content);

    // read the file
    TaskManager m {filePath};


    // make sure the manager loaded the tasks correctly
    vt ts = m.listTasks();
    
    assert (ts.size() == 15 && "task manager should have the correct number of tasks");

    // sort tasks by id 
    std::sort(ts.begin(), ts.end(), [](Task a, Task b) {
        return a.getTaskID() < b.getTaskID();
    });

    for (int i = 0; i < ts.size(); i ++ ){
        assert(ts[i].getTaskID() == i && "task manager should have the correct id");
    }

    // check the tasks by state
    for (int i = 0; i < 5; i++) {
        assert(ts[i].getTaskState() == TaskState::Todo && "task should be in the toDo state");
    }

    for (int i = 5; i < 10; i++) {
        assert(ts[i].getTaskState() == TaskState::InProgress && "task should be in the inProgress state");
    }

    for (int i = 10; i < 15; i++) {
        assert(ts[i].getTaskState() == TaskState::Completed && "task should be in the completed state");
    }   
    
    // make sure the creation times are reasonable
    Task lastTodoTask = *(std::max_element(ts.begin(), ts.begin() + 5, [](Task a, Task b) {
        return a.getCreationTime() < b.getCreationTime();
    }));

    Task firstToDoTask = *(std::min_element(ts.begin(), ts.begin() + 5, [](Task a, Task b) {
        return a.getCreationTime() < b.getCreationTime();
    }));

    assert(lastTodoTask.getCreationTime() - firstToDoTask.getCreationTime() <= t2 - t1 && "the difference in the creation time of the tasks should be within a certain range");

    // similar checks for the inProgress tasks
    Task lastInProgressTask = *(std::max_element(ts.begin() + 5, ts.begin() + 10, [](Task a, Task b) {
        return a.getCreationTime() < b.getCreationTime();
    }));

    Task firstInProgressTask = *(std::min_element(ts.begin() + 5, ts.begin() + 10, [](Task a, Task b) {
        return a.getCreationTime() < b.getCreationTime();
    }));

    assert(lastInProgressTask.getCreationTime() - firstInProgressTask.getCreationTime() <= t3 - t2 && "the difference in the creation time of the tasks should be within a certain range");

    // similar checks for the completed tasks
    Task lastCompletedTask = *(std::max_element(ts.begin() + 10, ts.end(), [](Task a, Task b) {
        return a.getCreationTime() < b.getCreationTime();
    }));

    Task firstCompletedTask = *(std::min_element(ts.begin() + 10, ts.end(), [](Task a, Task b) {
        return a.getCreationTime() < b.getCreationTime();
    }));

    assert(lastCompletedTask.getCreationTime() - firstCompletedTask.getCreationTime() <= t3 - t2 && "the difference in the creation time of the tasks should be within a certain range");

    // at this point delete the file
    deleteTempTxtFile(filePath);

}


void testTaskManagerReadPersist() {
    // create a file to save the tasks
    vt tasks;

    // the first 5 tasks are in the toDo state      
    for (int i = 0; i < 10; i++) {
        tasks.push_back(Task(i, "task_" + std::to_string(i)));
    }

    TaskSerializer ser = TaskSerializer();

    vec_str lines {"10"}; // the first line

    for (Task t : tasks) {
        lines.push_back(ser.serializeTask(t));
    }

    std::string content = join(lines, "\n");

    fs::path path = fs::current_path().append("tests/fileSamples/sample2.txt");

    // create a file with the tasks
    std::string filePath = createTempTxtFile(path.string(), content);
    
    { 
        TaskManager m {filePath};
        // delete the file  
        deleteTempTxtFile(filePath); 
        // make sure it is deleted
        assert(! fs::exists(filePath) && "file should be deleted");

        // at the end of this block the task manager will be destroyed calling the persist method
        // which should save the tasks to the file
    }


    // make sure the file was created
    assert(fs::exists(filePath) && "file should be created");

    // create a new task manager to read the file
    TaskManager m {filePath};

    // get the tasks
    vt ts = m.listTasks();

    // make sure the tasks are the same
    assert(ts.size() == 10 && "task manager should have the correct number of tasks");

    // sort the tasks by id and make sure they are the same as the original tasks
    std::sort(ts.begin(), ts.end(), [](Task a, Task b) {
        return a.getTaskID() < b.getTaskID();
    });

    for (int i = 0; i < ts.size(); i++) {
        assert(ts[i] == tasks[i] && "task manager should have the correct id");
    }

    // delete the file
    deleteTempTxtFile(filePath);
}


void runTaskManagerTests() {
    testTaskManagerReadFiles1();
    testTaskManagerReadFiles2();
    testTaskManagerReadPersist();
}