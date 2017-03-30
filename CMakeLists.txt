cmake_minimum_required(VERSION 3.6)
project(donorSimulation)

set(CMAKE_CXX_STANDARD 11)
include_directories(lib/eigen-eigen-67e894c6cd8f)
find_package(Eigen3)
set(SOURCE_FILES
        donorClass.cpp main.cpp donorClass.h)

add_executable(donorSimulation ${SOURCE_FILES})

add_subdirectory(donorTests)