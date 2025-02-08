#ifndef SRC_TESTS_TASKMANAGER_TESTS_H
#define SRC_TESTS_TASKMANAGER_TESTS_H

# include <fstream>
# include <cassert>
# include <filesystem>

# include "../core/TaskManager.h"
# include "../utils/random_utils.h"
# include "../utils/string_utils.h"

namespace fs = std::filesystem;

void testTaskManagerReadFiles();

void runTaskManagerTests();

#endif 