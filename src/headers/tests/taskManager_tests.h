# pragma once

# include <fstream>
# include <cassert>
# include <filesystem>

# include "../taskTracker/TaskManager.h"
# include "../taskTracker/random_utils.h"
# include "../taskTracker/string_utils.h"

namespace fs = std::filesystem;

void testTaskManagerReadFiles();

void runTaskManagerTests();

