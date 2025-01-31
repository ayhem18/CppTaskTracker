#ifndef SRC_TASK_H
#define SRC_TASK_H


# include <string>
// time module in C++
# include <ctime> 



enum TaskState {
    Todo,
    InProgress,
    Completed
};


class Task {
    private: 
        std::string taskId;
        std::string description;
        TaskState state;
        time_t createdAt;
        time_t lastUpdated;

        // a method to save the logic bits common across all update methods 
        void updateCommon();

    public:
        Task(const std::string & id, const std::string & desc): taskId(id), description(desc), state(Todo), createdAt(time(nullptr)), lastUpdated(time(nullptr)) {
            // leaving the body empty because there is nothing else to set 
        }

        void setId(const std::string& id);

        void setDescription(const std::string& description);

        void setState(TaskState state);
};

// a friend method to display a Task object



#endif 