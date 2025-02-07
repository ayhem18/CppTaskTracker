# include "app.h"

vec_str App::verifyListInput(const vec_str& input) {
    std::string command = toLowerCase(trim(input[0]));

    if (command != "list") {
        return vec_str();
    }

    // either list all of list by state
    if (input.size() > 2) {
        return vec_str();
    }
    
    if (input.size() == 1) {
        return vec_str{command};
    }

    // this function automatically checks if the string is a valid state
    getTaskState(input[1]);

    return vec_str{command, input[1]};
}    


vec_str App::verifyAddInput(const vec_str& input) {
    
}       

vec_str App::verifyUpdateInput(const vec_str& input) {

    if (input.size() != 2) {
        throw std::invalid_argument("Invalid input");
    }

    std::string id = toLowerCase(trim(input[0]));
    
}   

vec_str App::verifyDeleteInput(const vec_str& input) {
    if (input.size() != 1) {
        throw std::invalid_argument("Invalid input");
    }
}






void App::processInput(const vec_str& input) {  
    
    if (input[0] == "list") {
        vec_str verifiedInput = verifyListInput(input);
    }
}           