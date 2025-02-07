# include "taskManager_tests.h"

std::string createTempTxtFile(const std::string& fileName, const std::string& content) {
    std::string filePath;

    if (endsWith(fileName, ".txt")) {
        filePath = fileName;
    } else {
        filePath = fileName + ".txt";
    }

    std::ofstream file(filePath);
    if (! content.empty()) {
        file << content;
    }
    file.close();

    return filePath;
}

void deleteTempTxtFile(const std::string& filePath) {
    std::remove(filePath.c_str());
}   


void testTaskManagerReadFiles() {
    // create  an empty file
    std::string file = "temp.txt";
    const std::string filePath = createTempTxtFile(file, "");


    try{ 
        TaskManager tm {filePath};
        assert(false && "task manager should throw an exception but didn't");
    } catch (const std::invalid_argument& e) {    // create a file with the last id
        // remove the file  
        deleteTempTxtFile(filePath);
    }
    

    for (int i = 0; i < 100; i++) {

        const std::string filePathWithLastId = createTempTxtFile(file, std::to_string(i) + "\n");
        
        try {
            TaskManager manager {filePathWithLastId};
            // remove the file before the assertion 
            deleteTempTxtFile(filePathWithLastId);
            assert(manager.getLastId() == i && "task manager should have the correct last id");
            
        } catch (const std::invalid_argument& e) {
            deleteTempTxtFile(filePathWithLastId);
            assert(false && "task manager should not throw an exception");
        }
    }

}



void runTaskManagerTests() {
    testTaskManagerReadFiles();
}