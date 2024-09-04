project(leetcode_cpp_problems_dfs_nested_list_weight_sum_339)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/nested_sum.hpp nested_sum.cpp
        include/nested_integer.hpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)