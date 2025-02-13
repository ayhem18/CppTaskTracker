# include "../headers/taskTracker/app.h"
//////////////////////////////////////////// input processing functions ////////////////////////////////////////////

vec_str App::verifyListInput(const vec_str& input) const {
    // every input passed to this function has at least 2 arguments
    // first check the command !!

    std::string command = toLowerCase(trim(input[1]));

    if (command != "list") {
        throw InvalidCommandException("Invalid command");
    }


    if ((input.size() != 2) && (input.size() != 3)) {
        throw InvalidFormatException("List command requires 1 or 2 arguments");
    }

    // the input can have at most 3 arguments: fileName, command, state    
    if (input.size() == 2) {
        return vec_str{command};
    }

    try {
        getTaskState(input[2]);
    } catch (const std::exception& e) {
        throw InvalidSemanticsException(input[2] + " is not a valid task state.");
    }

    return vec_str{command, trim(input[2])};
}    


vec_str App::verifyAddInput(const vec_str& input) const {
    std::string command = toLowerCase(trim(input[1]));

    if (command != "add") {
        throw InvalidCommandException("Invalid command");
    }

    // the add task expects 2 arguments: fileName, add command, task description
    if (input.size() != 3) {
        throw InvalidFormatException("the Add command requires 2 arguments");
    }

    return vec_str{command, trim(input[2])};
}       


vec_str App::verifyUpdateInput(const vec_str& input) const {
    // start with the command

    std::string command = toLowerCase(trim(input[1]));

    if (command != "update") {
        throw InvalidCommandException("Invalid command");
    }

    if (input.size() != 4) {
        throw InvalidFormatException("the Update command requires 3 arguments: update taskId (taskState / description)");
    }

    // task id is an integer 
    try {
        std::stoi(input[2]);
    } catch (const std::exception& e) {
        throw InvalidSemanticsException("Keep in mind that task ids are integers ))");
    }

    return vec_str{command, trim(input[2]), trim(input[3])};
}   


vec_str App::verifyDeleteInput(const vec_str& input) const {
    std::string command = toLowerCase(trim(input[1]));

    if (command != "delete") {
        throw InvalidCommandException("Invalid command");
    }

    if (input.size() != 3) {
        throw InvalidFormatException("the delete command is of the format: delete taskId");
    }

    // make sure the taskId is an integer   
    try {
        std::stoi(input[2]);
    } catch (const std::exception& e) {
        throw InvalidSemanticsException("Keep in mind that task ids are integers ))");
    }

    return vec_str{command, input[2]};
}


void App::verifyCommonFormat(const vec_str& input) const {
    if (input.size() <= 1 || input.size() > 4) {
        throw InvalidGeneralInputException ("TaskTracker expects between 1 and 3 arguments");
    }    
    // might add other general checks afterward
}


vec_str App::processInput(const vec_str& input) const {  
    try {   
        verifyCommonFormat(input);

        // Vector of verification functions
        std::vector<std::function<vec_str(const vec_str&)>> verifiers = {
            [this](const vec_str& i) { return verifyListInput(i); },
            [this](const vec_str& i) { return verifyAddInput(i); },
            [this](const vec_str& i) { return verifyUpdateInput(i); },
            [this](const vec_str& i) { return verifyDeleteInput(i); }
        };

        // Try each verifier until one succeeds
        for (const auto& verifier : verifiers) {
            try {
                vec_str verifiedInput{verifier(input)};
                return verifiedInput;
            }
            catch (const InvalidCommandException& e) {
                continue; // consider the next command
            }
            catch (const InvalidFormatException& e) {
                // the command is valid but the format isn't; throw the error again !!
                throw e;
            } 
            catch (const InvalidSemanticsException& e) {
                // the command is valid but the semantics aren't; throw the error again !!
                throw e;
            }
        }
        
        // at this point, we know the command cannot be processed by the application
        throw InvalidCommandException("The passed command is not valid");

    } 

    catch (const InvalidSemanticsException& e) {
        std::cout << "Invalid Semantics: " << e.what() << std::endl;
    }

    catch (const InvalidFormatException& e) {
        std::cout << "Invalid Format: " << e.what() << std::endl;
    }

    catch (const InvalidCommandException& e) {
        std::cout << "Invalid Command: " << e.what() << std::endl;
    }   

    // added to quiet the compiler
    return vec_str();
}            

//////////////////////////////////////////// command execution functions ////////////////////////////////////////////

vec_str App::getTaskRepresentation(const Task& task) const {
    // get the creation time and last update time in human readable format
    // get the task id, description and state   

    std::string taskId = std::to_string(task.getTaskID());
    std::string description = task.getDescription();
    std::string state = getTaskStateString(task.getTaskState());

    std::string creationTime = this -> display.getFormattedTime(task.getCreationTime());
    std::string lastUpdateTime = this -> display.getFormattedTime(task.getLastUpdateTime());

    return vec_str{taskId, description, state, creationTime, lastUpdateTime};
}


void App::runAddCommand(const vec_str& input) {
    // keep in mind that the input here does not include the fileName

    std::string description = input[1]; 
    Task newTask = this -> manager.addTask(description); 

    std::cout << "New Task added successfully" << std::endl; 

    std::cout << this -> display.displayLine(this -> getTaskRepresentation(newTask)) << std::endl; 
}


void App::runUpdateCommand(const vec_str& input) {
    // the input is assume to be of the form: update taskId (taskState / description)
    int taskId = std::stoi(input[1]);
    std::string arg = input[2];
    
    // in the update command: updating the state is prioritized over updating the description 
    // so check if the last argument is a valid state
    
    try {
        try {
            TaskState newState = getTaskState(arg);
            this -> manager.updateTask(taskId, newState);

        } catch (const std::invalid_argument& e) {
            // the new state is not valid; so the new description is valid
            // so update the description
            this -> manager.updateTask(taskId, arg);    
        }

    } catch (const  std::invalid_argument& e) {
        throw InvalidCommandException(e.what());
    }

    std::cout << "Task updated successfully" << std::endl;
    this -> display.displayLine(this -> getTaskRepresentation(this -> manager.getTask(taskId)));
}       


void App::runDeleteCommand(const vec_str& input) {
    // the input is assume to be of the form: delete taskId
    int taskId = std::stoi(input[1]);
    
    try {
        Task deletedTask = this -> manager.getTask(taskId);
        this -> manager.deleteTask(taskId);
        std::cout << "Task deleted successfully" << std::endl;
        this -> display.displayLine(this -> getTaskRepresentation(deletedTask));
    } catch (const std::invalid_argument& e) {
        throw InvalidSemanticsException(e.what());
    }
}


void App::runListCommand(const vec_str& input) {
    // the input is assume to be of the form: list [state]  
    vt tasks;

    if (input.size() == 1) {
        // list all tasks
        tasks = this -> manager.listTasks();
    }
    else {
        tasks = this -> manager.listTasks(getTaskState(input[1]));
    }
    
    if (tasks.empty()) {
        std:: cout << "No Tasks added yet " << std::endl;
        return;
    }
    
    vec_str header = {"ID", "Description", "State", "Creation Time", "Last Update Time"}; 
    std::cout << this -> display.displayLine(header) << std::endl;

    // build a vector of task representations   
    for (const auto& task : tasks) {
        std::cout << this -> display.displayLine(this -> getTaskRepresentation(task)) << std::endl;
    }
} 



void App::runCommand(const vec_str& input) {
    vec_str verifiedInput = processInput(input);

    if (verifiedInput.empty()) {
        return;
    }

    const std::string& listCommand{"list"};
    const std::string& addCommand{"add"};
    const std::string& updateCommand{"update"};
    const std::string& deleteCommand{"delete"};

    // Create command map that associates command strings with member functions
    std::map<std::string, std::function<void(const vec_str&)>> commandMap = {
        {listCommand, [this](const vec_str& i) { this -> runListCommand(i); }},
        {addCommand, [this](const vec_str& i) { this -> runAddCommand(i); }},
        {updateCommand, [this](const vec_str& i) { this -> runUpdateCommand(i); }},
        {deleteCommand, [this](const vec_str& i) { this -> runDeleteCommand(i); }},
    };

    // call the corresponding function
    try {
        commandMap[verifiedInput[0]](verifiedInput); // make sure to access the element at index 0 and not 1 (because the filename was discarded in the input processing)
    } catch (const InvalidSemanticsException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const InvalidFormatException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const InvalidCommandException& e) {
        std::cout << e.what() << std::endl;
    }
}