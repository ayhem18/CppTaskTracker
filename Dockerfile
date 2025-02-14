FROM ubuntu:latest

WORKDIR /usr/local/app 

# install the packages needed to run the application
# make sure to pass the -y flat to avoid the interactive mode
RUN apt update -y && apt install build-essential -y 

# install the wget tool to download the cmake installer
RUN apt install wget -y  


# install cmake using wget
RUN wget -O cmake_install.sh  https://github.com/Kitware/CMake/releases/download/v3.31.5/cmake-3.31.5-linux-x86_64.sh

RUN echo y > interactive_cmake_install.txt
RUN echo y >> interactive_cmake_install.txt

# to avoid the interactive mode, pass the interactive_cmake_install.txt file to the installer
RUN chmod +x cmake_install.sh && ./cmake_install.sh < interactive_cmake_install.txt 

RUN rm interactive_cmake_install.txt

# passing "y" twice to the installer installs the application in the working directory: which is /usr/local/app
# do not forget to add the bin directory to the path
ENV CMAKE_DIR="/usr/local/app/cmake-3.31.5-linux-x86_64/bin" 

# add cmake to the path
ENV PATH="$PATH:$CMAKE_DIR"

RUN cmake --version

# create a directory for the repo
RUN mkdir CppTaskTracker

# copy the source code into the image
COPY . ./CppTaskTracker

# create a data.txt file with the number 0
# RUN echo 0 >> ./CppTaskTracker/src/data.txt

# at this point the application is built and the binary is in the executable was moved to the ./repo/src/taskCLient
RUN chmod +x ./CppTaskTracker/src/build_script.sh && ./CppTaskTracker/src/build_script.sh

# add the executable to the path
ENV PATH="$PATH:/usr/local/app/CppTaskTracker/src"

# add the executable file to the path   
ENV PATH="/usr/local/app/repo/src:$PATH"

# run the bash shell as the default command
CMD ["/bin/bash"]   

