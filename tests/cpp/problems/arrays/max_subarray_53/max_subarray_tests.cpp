#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <max_subarray.hpp>

using namespace problems::array::max_subarray;
using namespace tests::utils;

namespace max_subarray_tests {

    class MaxSubarrayTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<int> nums, int expected) {
            MaxSubarray solution;
            auto actual = solution.maxSubArray(nums);
            ASSERT_EQ(actual, expected);
        }
    };

    TEST_F(MaxSubarrayTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getNums(), tc.getExpected());
                 });
    }
}