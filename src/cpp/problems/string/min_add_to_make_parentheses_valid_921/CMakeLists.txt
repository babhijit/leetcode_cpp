project(leetcode_cpp_problems_string_min_add_valid_parentheses_921)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/min_add_make_valid_paren.hpp
        min_add_make_valid_paren.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)

