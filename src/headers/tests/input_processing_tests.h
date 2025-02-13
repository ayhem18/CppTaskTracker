# pragma once

# include "../taskTracker/app.h"
# include "../taskTracker/random_utils.h"

class TestAppInputProcessing: public App {
    public: 

        TestAppInputProcessing(const std::string& filePath): App(filePath) {}
    
        void testVerifyList() const;

        void testVerifyAdd() const;

        void testVerifyUpdate() const;


        void testVerifyDelete() const;
        void testProcessInput() const;

        void run() const;

};
