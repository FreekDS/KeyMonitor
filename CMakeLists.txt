cmake_minimum_required(VERSION 3.13)
project(KeyRecorder)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")
set(SFML_ROOT C:/Libs/SFML)

set(SRC
        src/main.cpp
        src/KeyRecorder.cpp
        src/Keyboard.cpp
        src/Application.cpp
        src/UI/Button.cpp)

find_package(SFML 2 COMPONENTS graphics window audio system)
find_package(PostgreSQL REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${SFML_INCLUDE_DIR})

add_executable(KeyRecorder WIN32 ${SRC})
add_executable(Helper src/helper.cpp)

target_link_libraries(KeyRecorder ${SFML_LIBRARIES})

file(COPY "${PROJECT_SOURCE_DIR}/res" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")