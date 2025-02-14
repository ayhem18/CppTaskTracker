#!/bin/sh

# Function to check if a directory exists
check_directory() {
    if [ ! -d "$1" ]; then
        return 1
    fi
    return 0
}

# Check if build_script.sh is in current directory
if [ -f "build_script.sh" ]; then
    # move to the parent directory to avoid in-source builds...
    cd ..
fi


# Check if "src" directory exists in current directory
if check_directory "src"; then
    # Do nothing, we're in the right place
    :
# Check if "CppTaskTracker" exists
elif check_directory "CppTaskTracker"; then
    # Change to CppTaskTracker directory
    cd CppTaskTracker
else
    echo "Error: Neither 'src' nor 'CppTaskTracker' directory found"
    echo "Please run this script from the project root or its parent directory"
    exit 1
fi

# at this point, we know that the current directory is the project root 
if check_directory "build"; then
    # remove the build directory
    rm -rf build
fi


cmake -B ./build 
# create the executable and move it to the src directory
cd ./build && make 

# at this point, the current directory should be ./build
# move the executable to the src directory
mv taskCLi ../src/taskCLi 
# # go the src directory
# cd ../src  

# # run the executable
# ./taskCLi
