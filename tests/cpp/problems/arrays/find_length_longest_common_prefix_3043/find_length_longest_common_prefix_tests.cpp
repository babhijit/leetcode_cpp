#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <longest_common_prefix.hpp>

using namespace problems::arrays::longest_common_prefix;
using namespace tests::utils;

namespace length_longest_common_prefix_tests {

    class FindLengthOfLongestCommonPrefixTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<int> arr1, std::vector<int> arr2, int expected) {
            LongestCommonPrefix solution;
            auto actual = solution.longestCommonPrefix(arr1, arr2);
            ASSERT_EQ(actual, expected);
        }
    };

    TEST_F(FindLengthOfLongestCommonPrefixTests, LeetCodeExample1) {
        runTest({1, 10, 100}, {1000}, 3);
    }

    TEST_F(FindLengthOfLongestCommonPrefixTests, LeetCodeExample2) {
        runTest({1, 2, 3}, {4, 4, 4}, 0);
    }

    TEST_F(FindLengthOfLongestCommonPrefixTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getArr1(), tc.getArr2(), tc.getExpected());
                 });
    }
}