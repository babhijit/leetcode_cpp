project(leetcode_cpp_problems_arrays_interval_intersection_986)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/interval_intersection.hpp interval_intersections.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)