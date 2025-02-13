# include "../headers/tests/display_tests.h"


void TestDisplay::test_longElementRepresentation() {
    for (int l = 20; l <= 100; l++) {
        this -> charsByElement = l;
        // generate a random string of length less or equal to l
        for (int i = 1; i <= l; i++) {
            std::string str = generateRandomString(i, string_utils::ALPHABET);
            vec_str res = this -> longElementRepresentation(str);

            // assert that the size of the vector is 1
            assert(res.size() == 1 && "The longElementRepresentation should return the same element if the string is not longer than the limit");

            // assert that the size of the vector is 2
            assert(res[0] == str && "The longElementRepresentation should return the same element if the string is not longer than the limit");
        }

        for (int i = 0; i <= 100; i++) {
            int n = getRandomNumber(l + 1, 10 * l + 1);
            std::string str = generateRandomString(n, string_utils::ALPHABET);

            vec_str res = this -> longElementRepresentation(str);
            std::string res_str = "";

            for (auto iter = res.begin(); iter != res.end() - 1; iter++) {
                res_str += (*iter).substr(0, this -> charsByElement - 1);
                // make sure the last character is a hyphen
                assert((*iter).back() == '-' && "The last character of the element should be a hyphen");
            }

            assert(res.back().back() != '-' && "The last element should not have a hyphen");

            res_str += *(res.end() - 1);

            assert(res_str == str && "it must be possible to construct the input from the output of the longElementRepresentation");
        }
    }

}


void TestDisplay::test_singleElementRepresentation() {
 
    for (int l = 20; l <= 100; l++) {
        this -> charsByElement = l;


        for (int num_trials = 10; num_trials <= 100; num_trials++) {

            // generate a random number of strings each of a length less than l
            int n = getRandomNumber(1, 10);
            vec_str strs {};
            for (int i = 0; i < n; i++) {
                std::string str = generateRandomString(getRandomNumber(l / 2 + 1, l), string_utils::ALPHABET);
                strs.push_back(str);
            }

            // join them with a white space
            std::string input = join(strs, " ");

            // get the output
            vec_str output = this -> singleElementRepresentation(input);

            // each element in the output mushc match its corresponding string in the strs vector
            for (int i = 0; i < n; i++) {
                assert(output[i] == strs[i] && "The output should match the input");
            }

        }
    }

    // the previous loop generated random strings of length between l / 2 + 1 and l 
    // guaranteeing that each string will be displayed on its own line

    // now generate random strings of length less than l 

    for (int l = 20; l <= 100; l++) {
        this -> charsByElement = l;

        for (int num_trials = 10; num_trials <= 100; num_trials++) {

            // generate a random number of strings each of a length less than l
            int n = getRandomNumber(1, 10);
            vec_str strs {};
            for (int i = 0; i < n; i++) {
                std::string str = generateRandomString(getRandomNumber(1, l), string_utils::ALPHABET);
                strs.push_back(str);
            }

            // join them with a white space
            std::string input = join(strs, " ");

            // get the output
            vec_str output = this -> singleElementRepresentation(input);

            std::string output_str = join(output, " ");

            assert(output_str == input && "The output should be the same as the input");
        }
    }

}


void TestDisplay::test_singleElementRepresentation_with_long_strings() {
    // test the case where some of the strings are longer than l
    for (int l = 20; l <= 100; l++) {
        this -> charsByElement = l;

        // generate a random number of strings each of a length less than l
        int num_strings = getRandomNumber(1, 10);

        vec_str strs {};
        vec_str flattened_strs {};


        for (int i = 0; i < num_strings; i++) {
            int str_len = getRandomNumber(2, l * 3);
            std::string str = generateRandomString(str_len, string_utils::ALPHABET);

            strs.push_back(str);
        
            vec_str string_split = this -> longElementRepresentation(str);
        
            // all all the elements in the vector to the strs vector
            flattened_strs.insert(flattened_strs.end(), string_split.begin(), string_split.end());
        }

        // join the strings with a white space
        std::string input = join(strs, " ");

        std::string flattened_input = join(flattened_strs, " ");

        // the output for both must be the same
        vec_str output = this -> singleElementRepresentation(input);
        vec_str flattened_output = this -> singleElementRepresentation(flattened_input);

        assert (output.size() == flattened_output.size() && "The output of the flattened and standard input should be the same");

        for (int i = 0; i < output.size(); i++) {
            assert(output[i] == flattened_output[i] && "The output of the flattened and standard input should be the same");
        }
    }
}