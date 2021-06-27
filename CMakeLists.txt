cmake_minimum_required(VERSION 3.10)

project(Leetcode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND INCLUDE_DIRECTORY
    ${CMAKE_SOURCE_DIR}/dynamic-programming
    ${CMAKE_SOURCE_DIR}/greedy
    ${CMAKE_SOURCE_DIR}/bfs)

add_executable(Leetcode main.cpp)
