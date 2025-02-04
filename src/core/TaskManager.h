#ifndef SRC_CORE_TASK_MANAGER_H
#define SRC_CORE_TASK_MANAGER_H


# include <string> 
# include <map>
# include <set>

# include "Task.h"


// define an alias for std::vector<Task>
using vt = std::vector<Task>;


class TaskManager { 
    private:
        // the path where the file will be saved
        std::string filePath;
        
        // a serializer object to write in and read data from files 
        TaskSerializer serializer;

        // the actual in-memory storage
        std::map<int, Task> taskData;        

        // have a set of each state that saves the ids of all tasks in that state
        std::set<int> todoIds;
        std::set<int> inProgressIds;
        std::set<int> doneIds;

        // a method to read the data from the file
        void read();

        // a method to persist the data to the file
        void persist() const;

    public:
        TaskManager(const std::string& path): filePath{path}, taskData{}, serializer{}, 
                todoIds{}, inProgressIds{}, doneIds{} {
            // populate the map and sets with the data from the file
            read();
        }

        // LIST METHODS

        // list all tasks
        vt listTasks() const; 

        // list all tasks with a given state
        vt listTasks(const std::string& state) const;

        // ADD METHODS

        Task addTask(const std::string& description) const;  

        // DELETE METHODS

        Task deleteTask(const int& id) const;

        // UPDATE METHODS
        Task updateTask(const int& id, const std::string& description) const;

        Task updateTask(const int& id, const std::string& state) const;

};

#endif 