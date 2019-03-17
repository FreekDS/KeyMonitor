cmake_minimum_required(VERSION 3.13)
project(KeyRecorder)

set(CMAKE_CXX_STANDARD 14)

add_executable(KeyRecorder KeyRecorder.cpp Keyboard.cpp main.cpp)
add_executable(Helper helper.cpp)