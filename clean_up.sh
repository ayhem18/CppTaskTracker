#!/bin/sh

# Function to check if a directory exists
check_directory() {
    if [ ! -d "$1" ]; then
        return 1
    fi
    return 0
}

# remove the build directory

if check_directory "build"; then
rm -r build
fi

cd src

# remove the executable
if [ -f "taskCLi" ]; then
    rm taskCLi
fi


# remove the data.txt file
if [ -f "data.txt" ]; then
    rm data.txt
fi



