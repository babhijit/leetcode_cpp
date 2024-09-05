project(leetcode_cpp_problems_tree_bin_tree_vert_order_traversal_314)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/vert_traversal.hpp vert_traversal.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)