cmake_minimum_required(VERSION 3.29)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(leetcode_cpp main.cpp)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_subdirectory(src)
add_subdirectory(tests)
