project(leetcode_cpp_problems_stack_min_rm_make_valid_paren_1249)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/min_rem_make_valid_paren.hpp min_rem_make_valid_paren.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)