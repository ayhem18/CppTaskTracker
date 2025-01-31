# include "Task.h"
# include <string>
// time module in C++
# include <ctime> 


void Task::updateCommon() {
    this -> lastUpdated = std::time(nullptr);  
}

void Task::setId (const std::string& id) {
    this -> taskId = id;
    this -> updateCommon();
}

void Task::setState(TaskState state) {
    this -> state = state;
    this -> updateCommon();
}

void Task::setDescription(const std::string& description) {
    this -> description = description;
    this -> updateCommon();
}
