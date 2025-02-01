# include <string> 
# include <map>

# include "Task.h"
# include "TaskSerializer.h"

class TaskManager { 
    private:
        // the path where the file will be saved
        std::string filePath;
        
        // a serializer object to write in and read data from files 
        TaskSerializer serializer;

        // the actual in-memory storage where 
        std::map<int, Task> taskData;        


        // a method to read the data from the file
        void read() const ;

        // a method to persist the data to the file
        void persist() const;

    public:
        // static std::string inline defaultFileName {"database.json"};
        TaskManager(const std::string& path): filePath{path}, taskData{}, serializer(){
            read();
        }

        void run();
};

// TaskManager::defaultFileName{};
