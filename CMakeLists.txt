set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

cmake_minimum_required(VERSION 3.21)

project(DingProject VERSION 1.0.0)


add_definitions(-std=c++11)
add_executable(cpp-compiler main.cpp)

#target_link_libraries(cpp-compiler PRIVATE say_hello)