# include "TaskSerializer.h"
# include "../utils/string_utils.h"


std::vector<std::string> TaskSerializer::verify_string_representation(const std::string& taskString) {
    const std::string& delimiter = "||"; 
    
    std::vector<std::string> tokens = splitString(taskString, delimiter);

    // the task must have exactly 
    if (tokens.size() != 5) {
        throw std::invalid_argument( "splitting a task representation with the '||' delimiter must result in 5 tokens. Found: " + std::to_string(tokens.size()) );
    }

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
		throw std::invalid_argument("the 4th token must represent a numerical value: creation time. Found: " + tokens.at(0));
	}

    try {
        int lastUpdatedTimeInt = std::stoi(tokens.at(4));  
	}
    catch (std::invalid_argument) {
		throw std::invalid_argument("the 5h token must represent a numerical value: last update time " + tokens.at(0));
	}

    return tokens;
}




