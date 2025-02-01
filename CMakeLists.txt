cmake_minimum_required(VERSION 3.31.)

project(TaskTrackerCpp VERSION 0.1.0 LANGUAGES C CXX)

add_executable(TaskTrackerCpp src/main.cpp src/core/Task.cpp src/core/Task.h)

