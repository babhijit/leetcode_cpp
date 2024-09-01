#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <k_largest.hpp>

using namespace problems::array::k_largest;
using namespace tests::utils;

namespace k_largest_tests {

    class KLargestTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<int> nums, int k, int expected) {
            KLargest solution;
            auto actual = solution.findKthLargest(nums, k);
            ASSERT_EQ(actual, expected);
        }
    };

    TEST_F(KLargestTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getNums(), tc.getK(), tc.getExpected());
                 });
    }
}