#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <rotated_sorted_array.hpp>

using namespace problems::arrays::min_in_rotated_sorted_array;
using namespace tests::utils;

namespace min_in_rotated_sorted_array_tests {

    class FindMinInSortedRotatedArray : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<int> nums, int expected) {
            RotatedSortedArray solution;
            auto actual = solution.findMin(nums);
            ASSERT_EQ(actual, expected);
        }
    };

    TEST_F(FindMinInSortedRotatedArray, LeetCodeExample1) {
        runTest({3, 4, 5, 1, 2}, 1);
    }

    TEST_F(FindMinInSortedRotatedArray, LeetCodeExample2) {
        runTest({4, 5, 6, 7, 0, 1, 2}, 0);
    }

    TEST_F(FindMinInSortedRotatedArray, LeetCodeExample3) {
        runTest({11, 13, 15, 17}, 11);
    }

    TEST_F(FindMinInSortedRotatedArray, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getNums(), tc.getExpected());
                 });
    }
}