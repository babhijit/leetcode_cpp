project(leetcode_cpp_problems_arrays_k_closest_points_to_origin_973)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/k_closest.hpp k_closest.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)