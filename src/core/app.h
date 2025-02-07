# include "TaskManager.h"   
# include "Task.h"
# include "Display.h"
# include "../utils/string_utils.h"

# include <filesystem>

class App {
    private:
        TaskManager manager;
        Display display;
    
        vec_str verifyListInput(const vec_str& input);

        vec_str verifyAddInput(const vec_str& input);

        vec_str verifyUpdateInput(const vec_str& input);

        vec_str verifyDeleteInput(const vec_str& input);    


        // static inline std::string defaultFileName {(fs::current_path().append("data.txt")).string()};
    public: 
        App(const std::string& filePath): manager{filePath}, display{16, 5, " | "} {
            
        }

        void processInput(const vec_str& input);
};