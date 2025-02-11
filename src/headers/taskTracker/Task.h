# pragma once 

# include <string>
// time module in C++
# include <ctime> 
# include <iostream>
# include <stdexcept>
# include <chrono>
# include <vector>


# include "string_utils.h"
////////////////////////////////////////// TaskState //////////////////////////////////////////

enum TaskState {
    Todo,
    InProgress,
    Completed
};


std::string getTaskStateString(TaskState state);

TaskState getTaskState(const std::string& str);


////////////////////////////////////////// Task //////////////////////////////////////////

using namespace std::chrono; // the classes are already nested enough even when adding this statement

class Task {
    private: 
        int taskId;
        std::string description;
        TaskState state;

        // system_clock::time_point created_at;
        // system_clock::time_point last_p;

        time_t createdAt; // algthou initially set as a const, the fact that Tasks will be serialized made me remove the const keyword
        time_t lastUpdated;

        // a method to save the logic bits common across all update methods 
        void updateCommon();

    public:
        Task(int id, const std::string & desc): taskId{id}, description{desc}, state{Todo}, createdAt{time(nullptr)}, lastUpdated{time(nullptr)} {
            // just to make sure the creation time and the last update time are the same
            time_t now = time(nullptr); 
            createdAt = now;
            lastUpdated = now;  
        };

        // getters
        int getTaskID() const;

        std::string getDescription() const ;

        std::time_t getCreationTime() const;

        std::time_t getLastUpdateTime() const;

        TaskState getTaskState() const;

        // setters
        void setId(int id);

        void setDescription(const std::string& description);

        void setState(TaskState state);

        std::string to_string() const;

        // override the equal operator
        bool operator == (const Task& anotherTask) const {            
            return (anotherTask.taskId == this -> taskId) && 
                (anotherTask.createdAt == this -> createdAt) && 
                (anotherTask.description == this -> description) && 
                (anotherTask.lastUpdated == this -> lastUpdated) && 
                (anotherTask.state == this -> state) 
                ;
        } 

        // since the TaskSerializer should have access to the creation time field of the Task class 
        // without publicly exposing the field with a setter, make the TaskSerializer a friend class of the Task class.
        friend class TaskSerializer;

};


std::ostream& operator << (std::ostream& out, const Task& task);


////////////////////////////////////////// TaskSerializer //////////////////////////////////////////


class TaskSerializer {
    private:
        std::vector<std::string> verify_string_representation(const std::string& taskString) const ;

    public:
        std::string serializeTask(const Task& task) const ;
        Task deserializeTask(const std::string taskStr) const ;

};

