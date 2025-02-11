# build the project

cmake -B ./build 
# create the executable and move it to the src directory
cd ./build && make 

# at this point, the current directory should be ./build
# move the executable to the src directory
mv taskCLi ../src/taskCLi 
# go the src directory
cd ../src  

# run the executable
./taskCLi
