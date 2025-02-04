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
    // this -> last_updated = system_clock::now();
    this -> lastUpdated = time(nullptr);  
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

TaskState Task::getTaskState() const {
    return this -> state;
}


std::ostream& operator << (std::ostream& out, const Task& task) {
    out << "Task (" << task.getTaskID() << ")" << "description: " <<  task.getDescription() << " created at: " << task.getCreationTime() << "\n"; 
    return out;
}




////////////////////////////////////////// Task Serializer //////////////////////////////////////////

std::vector<std::string> TaskSerializer::verify_string_representation(const std::string& taskString) {
    const std::string& delimiter = "||"; 
    
    std::vector<std::string> tokens = splitString(taskString, delimiter);

    // the task must have exactly 
    if (tokens.size() != 5) {
        throw std::invalid_argument( "splitting a task representation with the '||' delimiter must result in 5 tokens. Found: " + std::to_string(tokens.size()) );
    }

    // make sure to trim the tokens before further processing

    for (std::string& t : tokens) {
        t = trim(t);
    }

    // tokens = std::transform(tokens.begin(), tokens.end(), std::vector<std::string>{}, trim);
    
    // the first one must be an integer

    try {
        std::string t = tokens[0];
        // trim the token 

        int taskId = std::stoi(tokens.at(0));  
	}
    catch (std::invalid_argument) {
		throw std::invalid_argument("the first token must represent a numerical id: integer. Found: " + tokens.at(0));
	}

    try {
        int creationTimeInt = std::stoi(tokens.at(3));  
	}
    catch (std::invalid_argument) {
		throw std::invalid_argument("the 4th token must represent a numerical value: the creation time. Found: " + tokens.at(0));
	}

    try {
        int lastUpdatedTimeInt = std::stoi(tokens.at(4));  
	}
    catch (std::invalid_argument) {
		throw std::invalid_argument("the 5h token must represent a numerical value: the last update time " + tokens.at(0));
	}

    return tokens;
}

Task TaskSerializer::deserializeTask(const std::string taskStr) {
    // extract the tokens after format verification
    std::vector<std::string> tokens = this -> verify_string_representation(taskStr);

    int taskId = std::stoi(tokens.at(0));
    int creationTime = std::stoi(tokens.at(3));
    int updateTime = std::stoi(tokens.at(4));

    std::string description = tokens.at(1);
    TaskState state = getTaskState(tokens.at(2));

    // set the task id 
    Task res = Task(taskId, description);
    // set the state with 
    res.setState(state);

    // set the private fields using the field class privileges
    res.createdAt = time_t(creationTime);
    res.lastUpdated = time_t(updateTime);

    // return the serialize object
    return res;
}



std::string TaskSerializer::serializeTask(const Task& task) {
    std::string idString = std::to_string(task.getTaskID());

    std::string creationTime = std::to_string(task.getCreationTime());
    std::string updateTime = std::to_string(task.getLastUpdateTime());

    std::string state = getTaskStateString(task.getTaskState()); 
    
    // wrap up all the fields in a std::vector

    std::vector<std::string> tokens {idString, task.getDescription(), state, creationTime, updateTime};

    return join(tokens, " || ");
}
