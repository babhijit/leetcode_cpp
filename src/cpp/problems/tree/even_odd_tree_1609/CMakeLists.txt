project(leetcode_cpp_problems_tree_even_odd_tree_1609)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/even_odd_tree.hpp even_odd_tree.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)