# include "../headers/taskTracker/TaskManager.h"

void TaskManager::persist() const {
    // 1. open the file     
    std::ofstream file(this -> filePath);

    // 2. write the number of tasks ever created
    file << this -> lastId << "\n";
    
    // 3. serialize each task

    for (const  auto& p : this -> taskData) {
        file << this -> serializer.serializeTask(p.second) << "\n";
    }
}

void TaskManager::read(){

    // check if the file exists
    if (!std::filesystem::exists(this -> filePath)) {
        throw std::invalid_argument("The file does not exist");
    }

    std::ifstream file(this -> filePath);

    // check if the file exists
    if (!file.is_open()) {
        throw std::invalid_argument("Cannot open the file");
    }

    // check if the file is empty
    if (std::filesystem::is_empty(this -> filePath)) {
        throw std::invalid_argument("The file is empty");
    }

    std::string line;

    std::getline(file, line);

    // make sure the first line is an integer
    try {
        this -> lastId = std::stoi(line);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("The first line of the file must be an integer: the total number of tasks ever created");
    }

    // for the rest of the file, each line represents a task        
    // read it, serialize it
    // determine its state and add its id to the corresponding set   

    while (std::getline(file, line)) {  
        Task serializedTask = (this -> serializer).deserializeTask(line); 

        int taskId = serializedTask.getTaskID(); 
        TaskState taskState = serializedTask.getTaskState();

        // add the task to the taskData map
        (this -> taskData).insert({taskId, serializedTask});

        // // add the task id to the corresponding set
        (this -> stateToIds[taskState]).insert(taskId);
    }
}


vt TaskManager::listTasks() const { 
    // start by the toDo tasks
    vt toDoTasks = listTasks(TaskState::Todo);

    // then the inProgress tasks
    vt inProgressTasks = listTasks(TaskState::InProgress);

    // then the done tasks
    vt doneTasks = listTasks(TaskState::Completed);    

    // append all of them together
    vt allTasks = toDoTasks;
    allTasks.insert(allTasks.end(), inProgressTasks.begin(), inProgressTasks.end());
    allTasks.insert(allTasks.end(), doneTasks.begin(), doneTasks.end());

    return allTasks;
}   

vt TaskManager::listTasks(const TaskState& state) const {   
    // get the ids of the tasks with the given state
    std::set<int> idsByState = this -> stateToIds.at(state);
    // get the tasks from the taskData map

    vt resultTasks;

    for (int id : idsByState) {
        // add the task corresponding to the task
        resultTasks.push_back(this -> taskData.at(id));
    }   

    return resultTasks;
}

Task TaskManager::addTask(const std::string& description) {

    // 1. create a new task with the given description and the new id
    Task newTask = Task(this -> lastId, description);

    // 2. add the new task to the taskData map    
    this -> taskData.insert({this -> lastId, newTask});

    // 3. add the new task to the corresponding set: the toDo set (new tasks are always assigned the ToDo state) 
    this -> stateToIds.at(TaskState::Todo).insert(this -> lastId);

    // 4. increment the lastId field
    this -> lastId = this -> lastId + 1;

    // 5. return the new task
    return newTask;
}

Task TaskManager::deleteTask(const int& id) {
    // 1. check if the given id exists in the taskData map 
    if (this -> taskData.find(id) == this -> taskData.end()) {
        throw std::invalid_argument("The given id does not exist");
    }
    
    // 2. get the task to be deleted
    Task taskToBeDeleted = this -> taskData.at(id);

    // 3. remove the task from the taskData map
    this -> taskData.erase(id);

    // 4. remove the task from the corresponding set
    this -> stateToIds.at(taskToBeDeleted.getTaskState()).erase(id);

    // 5. return the deleted task
    return taskToBeDeleted;
}
        
Task TaskManager::updateTask(const int& id, const std::string& description) {
    // 1. check if the given id exists in the taskData map 
    if (this -> taskData.find(id) == this -> taskData.end()) {
        throw std::invalid_argument("The given id does not exist");
    }
    
    // simple update the description of the task
    this -> taskData.at(id).setDescription(description);

    // return the updated task
    return this -> taskData.at(id);
}

Task TaskManager::updateTask(const int& id, const TaskState& state) {
    // 1. check if the given id exists in the taskData map 
    if (this -> taskData.find(id) == this -> taskData.end()) {
        throw std::invalid_argument("The given id does not exist");
    }

    if (this -> taskData.at(id).getTaskState() == state) {
        return this -> taskData.at(id);
    }

    TaskState oldState = this -> taskData.at(id).getTaskState(); 

    // remove the task from the set corresponding to the old state
    this -> stateToIds.at(oldState).erase(id); 


    // set the state of the task
    this -> taskData.at(id).setState(state);

    // add the task to the set corresponding to the new state
    this -> stateToIds.at(state).insert(id);

    // return the updated task
    return this -> taskData.at(id); 
}


int TaskManager::getLastId() const {
    return this -> lastId;
}   


Task TaskManager::getTask(const int& id) const {
    // check if the given id exists in the taskData map 
    if (this -> taskData.find(id) == this -> taskData.end()) {
        throw std::invalid_argument("The given id does not exist");
    }

    return this -> taskData.at(id);
}   


std::string TaskManager::getFilePath() const {
    return this -> filePath;
}

    