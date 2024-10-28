project(leetcode_cpp_problems_tests_list_reorder_list_143)

add_executable(${PROJECT_NAME} test_case.hpp reorder_list_tests.cpp)

target_link_libraries(${PROJECT_NAME}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        leetcode_cpp_ds
        leetcode_cpp_tests_util
        leetcode_cpp_problems_list_reorder_list_143)

gtest_discover_tests(${PROJECT_NAME})

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)
