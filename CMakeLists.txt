cmake_minimum_required(VERSION 3.13)
project(Keylogger)

set(CMAKE_CXX_STANDARD 14)

add_executable(Keylogger KeyRecorder.cpp main.cpp)
add_executable(Helper helper.cpp)