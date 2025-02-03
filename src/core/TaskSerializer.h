#ifndef SRC_CORE_TASK_SERIALIZER_H
#define SRC_CORE_TASK_SERIALIZER_H

# include <vector>
# include <string>
# include <stdexcept>

# include "Task.h"

class TaskSerializer {
    private:
        std::vector<std::string> verify_string_representation(const std::string& taskString);

    public:
        std::string serializeTask(const Task& task);
        Task deserializeTask(const std::string taskStr);

};

#endif 
