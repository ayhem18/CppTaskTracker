# include "../headers/tests/input_processing_tests.h"

void TestAppInputProcessing::testVerifyList() const {

    // throw an error is the command is not "list"

    for (int i = 0; i < 10; i++) {
        std::string s = generateRandomString(10, string_utils::ALPHABET);
        // generate a random float between 0 and 1
        int n = getRandomNumber(0, 1);
        vec_str input = {s};
        
        if (n == 0) {
            input.push_back("some word");
        }

        try {
            this -> verifyListInput(input);
            assert(false && "The input should be flagged as invalid");
        } catch (const std::exception& e) {
            
        }
    }

    // work for any list 

    for (int i = 0; i < 100; i++) {
        // random input
        vec_str input = {"list", generateRandomString(20, string_utils::ALPHABET)};

        try {
            this -> verifyListInput(input);
            assert(false && "the `list` command with an invalid state should be flagged as invalid");
        } catch (const std::exception& e) {
        }
    }

    vec_str tasksStates = {"todo", "inprogress", "completed"};

    for (const auto& state : tasksStates) {
        vec_str input = {"file_name", "list", state};
        try {
            this -> verifyListInput(input);
        } catch (const std::exception& e) {
            assert(false && "The input should be flagged as invalid");
        }
    }

    // make sure the command work with only the "list"
    vec_str input = {"file_name", "list"};
    try {
        this -> verifyListInput(input);
    } catch (const std::exception& e) {
        assert(false && "The input should not be flagged as invalid");
    }
} 

void TestAppInputProcessing::testVerifyAdd() const {
    // let's verify add

    // throw an error if the command is not "add"
    for (int i = 0; i < 10; i++) {
        vec_str input = {"file_name", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyAddInput(input);
            assert(false && "The input should be flagged as invalid");
        } catch (const std::exception& e) {
        }
    }
    
    vec_str input = {"file_name", "add"};
    try {
        this -> verifyAddInput(input);
        assert(false && "The input should be flagged as invalid");
    } catch (const std::exception& e) {
    }

    for (int i = 0; i < 10; i++) {
        vec_str input = {"file_name", "add", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyAddInput(input);
        } catch (const std::exception& e) {
            assert(false && "The input should not be flagged as invalid");
        }
    }    
    
}


void TestAppInputProcessing::testVerifyUpdate() const {
    // throw an error if the command is not "update"
    for (int i = 0; i < 10; i++) {
        vec_str input = {"file_name", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyUpdateInput(input);
        } catch (const std::exception& e) {}
    }   

    // make sure an error is thrown if the task id passed is not numerical
    for(int i = 0; i < 10; i++) {
        vec_str input = {"file_name", "update", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyUpdateInput(input);
            assert(false && "The input should be flagged as invalid");
        } catch (const std::exception& e) {
        }
    }

    //make sure it works with task states
    vec_str taskStates = {"todo", "inprogress", "completed"};
    for (const auto& state : taskStates) {
        vec_str input = {"file_name", "update", "1", state};
        try {
            this -> verifyUpdateInput(input);
        } catch (const std::exception& e) {
            assert(false && "The input should not be flagged as invalid");
        }
    }

    // make sure the command does not work without a task state or a task description
    vec_str input = {"file_name", "update", "1"};
    try {
        this -> verifyUpdateInput(input);
        assert(false && "The input should not be flagged as invalid");
    } catch (const std::exception& e) {
    }


    input = {"file_name", "update"};
    try {
        this -> verifyUpdateInput(input);
        assert(false && "The input should not be flagged as invalid");
    } catch (const std::exception& e) {
    }

    // make sure it works with updating a new description
    for (int i = 0; i < 10; i++) {
        input = {"file_name", "update", "1", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyUpdateInput(input);
        } catch (const std::exception& e) {
            assert(false && "The input should not be flagged as invalid");
        }
    }   
}


void TestAppInputProcessing::testVerifyDelete() const {
    // it has to work only with the delete command
    for (int i = 0; i < 10; i++) {
        vec_str input = {"file_name", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyDeleteInput(input);
            assert(false && "The input should be flagged as invalid");
        } catch (const std::exception& e) {
        }
    }   

    // make sure it accepts only a task id and nothing more
    for (int i = 0; i < 10; i++) {
        vec_str input = {"file_name", "delete", generateRandomString(10, string_utils::ALPHABET)};
        try {
            this -> verifyDeleteInput(input);
            assert(false && "The input should be flagged as invalid");
        } catch (const std::exception& e) {
        }
    }

    // make sure it works with deleting a task
    for (int i = 0; i < 10; i++) {
        vec_str input = {"file_name", "delete", std::to_string(i)};
        try {
            this -> verifyDeleteInput(input);
        } catch (const std::exception& e) {
            assert(false && "The input should not be flagged as invalid");
        }
    }
}


void TestAppInputProcessing::run() const {
    this -> testVerifyList();
    this -> testVerifyAdd();
    this -> testVerifyUpdate();
    this -> testVerifyDelete(); 
}
