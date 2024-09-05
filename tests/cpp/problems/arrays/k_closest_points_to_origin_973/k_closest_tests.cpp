#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <k_closest.hpp>

using namespace problems::arrays::k_closest;
using namespace tests::utils;

namespace k_closest_tests {

    class KClosestTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<std::vector<int>> nums, int k, std::vector<std::vector<int>> expected) {
            KClosestPoints solution;
            auto actual = solution.kClosest(nums, k);

            // points can be returned in any order
            std::set<std::vector<int>> actualResults(actual.begin(), actual.end());
            std::set<std::vector<int>> expectedResults(expected.begin(), expected.end());

            ASSERT_EQ(actualResults, expectedResults);
        }
    };

    TEST_F(KClosestTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getPoints(), tc.getK(), tc.getExpected());
                 });
    }
}