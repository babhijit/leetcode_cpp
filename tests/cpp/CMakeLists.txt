project(leetcode_cpp_tests)

set(TEST_BINARY sanity_tests)

add_subdirectory(util)

add_executable(${TEST_BINARY} sanity_test.cpp)

target_link_libraries(
        ${TEST_BINARY}
        GTest::gtest_main
        leetcode_cpp_ds
        leetcode_cpp_tests_util
)

gtest_discover_tests(${TEST_BINARY})


add_custom_command(
        TARGET ${TEST_BINARY}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/../resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)

add_subdirectory(problems)