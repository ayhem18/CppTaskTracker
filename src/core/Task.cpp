# include "Task.h" // Task.h contains all other includes...

void Task::updateCommon() {
    this -> lastUpdated = std::time(nullptr);  
}

void Task::setId (int id) {
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


int Task::getTaskID() const { // the 'const' keyword here notifies the compile that this method does not modify the calling object; hence it can be called from constant types
    return this->taskId;
}

std::string Task::getDescription() const {
    return this->description;
}

std::time_t Task::getCreationTime() const {
    return this->createdAt;
}

std::time_t Task::getLastUpdateTime() const {
    return this->lastUpdated;
}


std::ostream& operator << (std::ostream& out, const Task& task) {
    out << "Task (" << task.getTaskID() << ")" << "description: " <<  task.getDescription() << " created at: " << task.getCreationTime() << "\n"; 
    return out;
}
