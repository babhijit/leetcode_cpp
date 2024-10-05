#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <merge_intervals.hpp>

using namespace problems::arrays::merge_intervals;
using namespace tests::utils;

namespace merge_intervals_tests {

    class MergeIntervalsTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::vector<std::vector<int>> intervals, std::vector<std::vector<int>> expected) {
            MergeIntervals solution;
            auto actual = solution.merge(intervals);
            ASSERT_EQ(actual, expected);
        }
    };

    TEST_F(MergeIntervalsTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getNums(), tc.getExpected());
                 });
    }
}