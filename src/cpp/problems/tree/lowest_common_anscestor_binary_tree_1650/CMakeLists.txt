project(leetcode_cpp_problems_tree_lowest_common_ancestor_binary_tree)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/lowest_common_ancestor.hpp lowest_common_ancestor.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)