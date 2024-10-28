project(leetcode_cpp_problems_list_reorder_list_143)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/reorder_list.hpp reorder_list.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)