project(leetcode_cpp_problems_arrays_k_largest_215)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/k_largest.hpp k_largest.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)