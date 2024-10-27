project(leetcode_cpp_problems_arrays_find_len_longest_common_prefix_3043)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/longest_common_prefix.hpp
        lcp_unordered_set.hpp
        lcp_trie.hpp
        longest_common_prefix.cpp)

target_link_libraries(${PROJECT_NAME} leetcode_cpp_ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)