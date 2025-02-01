# include "Task.h"
    
class TaskSerializer {
    private:
        void verify_string_representation(const std::string& taskString);

    public:
        void serializeTask(const Task& task);
        Task deserializeTask(const std::string taskStr);


};