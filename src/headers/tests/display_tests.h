# pragma once

# include <cassert>

# include "../taskTracker/Display.h"
# include "../taskTracker/string_utils.h"
# include "../taskTracker/random_utils.h"


class TestDisplay: public Display {
    private:
        void test_longElementRepresentation();

        void test_singleElementRepresentation();

        void test_singleElementRepresentation_with_long_strings();

    public:
        TestDisplay(): Display(10, 2, " "){

        }

        void run() {
            test_longElementRepresentation();
            test_singleElementRepresentation();
        }        

};  