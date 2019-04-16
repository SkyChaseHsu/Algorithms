cmake_minimum_required(VERSION 3.9)
project(8sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(8sort main.cpp sortClass.cpp sortClass.h testSort.cpp testSort.h csvProcess.cpp csvProcess.h)