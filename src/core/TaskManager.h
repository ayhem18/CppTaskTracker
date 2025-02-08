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

        // // define a static string field that represents the delimiter between the task representations in the field 
        // static const inline std::string serializationDelimiter = "--------------------------------";

        // a field to save the total number of tasks ever created
        // useful for id uniqueness
        int lastId;

        // the actual in-memory storage
        std::map<int, Task> taskData;        

        // have a set of each state that saves the ids of all tasks in that state
        std::set<int> todoIds;
        std::set<int> inProgressIds;
        std::set<int> doneIds;

        // a simple std::map mapping each state to the corresponding set
        std::map<TaskState, std::set<int>> stateToIds;


        // a method to read the data from the file
        void read();

        // a method to persist the data to the file
        void persist() const;

    public:
        TaskManager(const std::string& path): filePath{path}, taskData{}, serializer{}, 
                todoIds{}, inProgressIds{}, doneIds{}, stateToIds{}, lastId{0} {
            // populate the map                
            stateToIds[TaskState::Todo] = todoIds;
            stateToIds[TaskState::InProgress] = inProgressIds;
            stateToIds[TaskState::Completed] = doneIds;
            // populate the map and sets with the data from the file
            // and update the lastId attribute
            read();
        }

        TaskManager(): filePath{}, taskData{}, serializer{}, 
                todoIds{}, inProgressIds{}, doneIds{}, stateToIds{}, lastId{0} {
            // populate the map                
            stateToIds[TaskState::Todo] = todoIds;
            stateToIds[TaskState::InProgress] = inProgressIds;
            stateToIds[TaskState::Completed] = doneIds;
        }   

        // Destructor to persist data before destruction
        ~TaskManager() {
            persist(); // Call the persist method
        }

        // LIST METHODS

        // list all tasks
        vt listTasks() const; 

        // list all tasks with a given state
        vt listTasks(const TaskState& state) const;

        // ADD METHODS
        Task addTask(const std::string& description);  

        // DELETE METHODS
        Task deleteTask(const int& id);

        // UPDATE METHODS
        Task updateTask(const int& id, const std::string& description) ;

        Task updateTask(const int& id, const TaskState& state) ;

        // GETTERS 
        int getLastId() const; 
        
        Task getTask(const int& id) const;

};

#endif 