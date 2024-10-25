project(leetcode_cpp_problems_list_insert_into_sorted_clist_708)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/sorted_circular_list.hpp sorted_circular_list.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)