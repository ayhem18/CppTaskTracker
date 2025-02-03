# include "Task.h" // Task.h contains all other includes...
# include "../utils/string_utils.h"

////////////////////////////////////////// TaskState //////////////////////////////////////////

std::string getTaskStateString(TaskState state) {
    switch (state)
    {
    case Todo: return "todo";
    case InProgress:   return "inProgress";
    case Completed: return "completed";
    default:        throw std::invalid_argument("invalid value for a TaskState enum");
    }
}

TaskState getTaskState(const std::string& str) {

    const std::string& s = trim(toLowerCase(str));


    if (s == "todo") {
        return Todo;
    }

    if (s == "inprogress") {
        return InProgress;
    }


    if (s != "completed") {
        throw std::invalid_argument("invalid value for a TaskState enum");
    }

    return Completed;

}


////////////////////////////////////////// Task //////////////////////////////////////////
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
