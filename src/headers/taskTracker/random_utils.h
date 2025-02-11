# pragma once

# include <string>
# include <cstdlib>
# include <chrono>
# include <cassert> // for the assert function

# include "string_utils.h"

int getRandomNumber(int low, int high);

std::string generateRandomString(int length, const std::string& characters);
