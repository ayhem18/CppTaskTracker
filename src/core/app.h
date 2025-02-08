#ifndef SRC_CORE_APP_H
#define SRC_CORE_APP_H


# include <filesystem>
# include <stdexcept>
# include <iostream>
# include <vector>
# include <functional>


# include "TaskManager.h"   
# include "Display.h"
# include "../utils/string_utils.h"


// here is the exception handling flow: 
// 1. check if the input satisfies a general common requirements 
//    if not, throw InvalidGeneralInputException
// 3. if yes, check if the command is valid
// 4. if not, throw InvalidCommandException
// 5. if is possible that an input with a valid input might not semantically valid: 
// for example deleting / updating a non-existent task  
// or update a task to an invalid state 
// in such cases throw InvalidSemanticsException: a general wrap up to any exception thrown by inner objects (Task, TaskManager)


class InvalidGeneralInputException : public std::runtime_error {
public:
    explicit InvalidGeneralInputException(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidCommandException : public std::runtime_error {
public:
    explicit InvalidCommandException(const std::string& message)
        : std::runtime_error(message) {}
};


class InvalidFormatException : public std::runtime_error {
public:
    explicit InvalidFormatException(const std::string& message)
        : std::runtime_error(message) {}
};


class InvalidSemanticsException : public std::runtime_error {
public:
    explicit InvalidSemanticsException(const std::string& message)
        : std::runtime_error(message) {}
};  


class App {
    private:
        TaskManager manager;
        Display display;
    
        vec_str verifyListInput(const vec_str& input) const;

        vec_str verifyAddInput(const vec_str& input) const;

        vec_str verifyUpdateInput(const vec_str& input) const;

        vec_str verifyDeleteInput(const vec_str& input) const;    

        void verifyCommonFormat(const vec_str& input) const;


        vec_str getTaskRepresentation(const Task& task) const;

        void runAddCommand(const vec_str& input);

        void runUpdateCommand(const vec_str& input);

        void runDeleteCommand(const vec_str& input);    
        
        void runListCommand(const vec_str& input);

        void runExitCommand(const vec_str& input);


        // static inline std::string defaultFileName {(fs::current_path().append("data.txt")).string()};
    public: 
        App(const std::string& filePath): manager{filePath}, display{25, 5, " | "} {
            
        }

        vec_str processInput(const vec_str& input) const;

        void runCommand(const vec_str& input);
};


#endif 