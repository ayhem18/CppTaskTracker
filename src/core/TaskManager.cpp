# include "TaskManager.h"

void TaskManager::persist() const{
    // 1. open the file

    // update the first block: the number of tasks ever created 

    // rewrite the rest of the file: serialize each task    

}

void TaskManager::read(){
    // 1. open the file

    // update the first block: the number of tasks ever created 
    // rewrite the rest of the file: serialize each task   

}


vt TaskManager::listTasks() const { 
    // start by the toDo tasks
    vt toDoTasks = listTasks("todo");

    // then the inProgress tasks
    vt inProgressTasks = listTasks("inProgress");

    // then the done tasks
    vt doneTasks = listTasks("done");    

    // append all of them together
    vt allTasks = toDoTasks;
    allTasks.insert(allTasks.end(), inProgressTasks.begin(), inProgressTasks.end());
    allTasks.insert(allTasks.end(), doneTasks.begin(), doneTasks.end());

    return allTasks;
}   

vt TaskManager::listTasks(const std::string& state) const {
}

Task TaskManager::addTask(const std::string& description) const {
}

Task TaskManager::deleteTask(const int& id) const {
}

Task TaskManager::updateTask(const int& id, const std::string& description) const {
}

Task TaskManager::updateTask(const int& id, const std::string& state) const {
}
