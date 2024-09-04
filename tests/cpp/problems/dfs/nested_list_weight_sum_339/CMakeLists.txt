project(leetcode_cpp_problems_tests_stack_dfs_nested_list_weight_sum_339)

add_executable(${PROJECT_NAME} nested_weight_sum_tests.cpp)

target_link_libraries(${PROJECT_NAME}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        leetcode_cpp_ds
        leetcode_cpp_tests_util
        leetcode_cpp_problems_dfs_nested_list_weight_sum_339)

gtest_discover_tests(${PROJECT_NAME})


