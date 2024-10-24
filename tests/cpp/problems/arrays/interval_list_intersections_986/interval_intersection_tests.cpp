#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <interval_intersection.hpp>

using namespace problems::arrays::interval_intersection;
using namespace tests::utils;

namespace interval_intersection_tests {

    class IntervalIntersectionTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<std::vector<int>> firstList,
                     std::vector<std::vector<int>> secondList,
                     std::vector<std::vector<int>> expected) {
            IntervalIntersections solution;
            auto actual = solution.intervalIntersection(firstList, secondList);
            ASSERT_EQ(actual, expected);
        }
    };

    TEST_F(IntervalIntersectionTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getFirstList(), tc.getSecondList(), tc.getExpected());
                 });
    }
}