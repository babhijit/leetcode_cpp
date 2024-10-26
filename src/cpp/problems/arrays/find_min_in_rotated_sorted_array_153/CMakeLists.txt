project(leetcode_cpp_problems_arrays_find_min_in_sorted_array_153)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/rotated_sorted_array.hpp rotated_sorted_array.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)