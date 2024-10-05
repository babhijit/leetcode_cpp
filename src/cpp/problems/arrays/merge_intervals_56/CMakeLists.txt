project(leetcode_cpp_problems_arrays_merge_intervals_56)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/merge_intervals.hpp merge_intervals.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)