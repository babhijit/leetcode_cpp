project(leetcode_cpp_problems_arrays_maxsubarray_53)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/max_subarray.hpp max_subarray.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)