project(leetcode_cpp_gtest_setup)

find_package(GTest REQUIRED)

enable_testing()

include(GoogleTest)

add_subdirectory(cpp)