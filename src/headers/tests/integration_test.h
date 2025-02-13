# pragma once

# include "../taskTracker/app.h"

class TestAppIntegration: public App {
    public:
        TestAppIntegration(const std::string& filePath): App(filePath) {}

        void testAddTask() ;

        void testUpdateTask() ;

        void testDeleteTask() ;

        void testListTasks();

        void run();
        
};
