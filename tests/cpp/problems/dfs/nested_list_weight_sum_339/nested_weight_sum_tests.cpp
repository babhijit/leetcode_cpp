#include <gtest/gtest.h>

#include <res/test_resource_utils.hpp>

#include <nested_integer.hpp>
#include <nested_sum.hpp>

using namespace problems::dfs::nested_sum;
using namespace tests::utils;

namespace min_rm_make_valid_param_tests {

    class NestedListWeightSumTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

        void runTest(std::vector<NestedInteger> nestedIntegers, int expected) {
            DepthSumOfNestedInteger nestedSum;
            auto actual = nestedSum.depthSum(nestedIntegers);
            EXPECT_EQ(expected, actual);
        }
    };

    TEST_F(NestedListWeightSumTests, Scenario1) {
        NestedInteger ni_11;
        ni_11.add(NestedInteger(1));
        ni_11.add(NestedInteger(1));

        NestedInteger ni;
        ni.add(ni_11);
        ni.add(NestedInteger(2));
        ni.add(ni_11);

        runTest({NestedInteger({ni})}, 16);
    }

    TEST_F(NestedListWeightSumTests, Scenario2) {
        NestedInteger ni6;
        ni6.add(NestedInteger(6));

        NestedInteger ni4(4);
        NestedInteger midLevel;
        midLevel.add(ni4);
        midLevel.add(ni6);

        NestedInteger topLevelNi;
        topLevelNi.add(NestedInteger(1));
        topLevelNi.add(midLevel);


        runTest({topLevelNi}, 38);
    }

    TEST_F(NestedListWeightSumTests, Scenario3) {
        NestedInteger ni(1);

        runTest({ni}, 1);
    }

    TEST_F(NestedListWeightSumTests, Scenario4) {
        NestedInteger ni;
        ni.add(NestedInteger(1));

        runTest({ni}, 2);
    }

    TEST_F(NestedListWeightSumTests, Scenario5) {
        NestedInteger ni;
        ni.add(NestedInteger(1));
        ni.add(NestedInteger(1));

        runTest({ni}, 4);
    }

    TEST_F(NestedListWeightSumTests, Scenario6) {
        NestedInteger ni;
        ni.add(NestedInteger(1));
        ni.add(NestedInteger(2));

        runTest({ni}, 6);
    }

    TEST_F(NestedListWeightSumTests, Scenario7) {
        NestedInteger ni11;
        ni11.add(NestedInteger(1));
        ni11.add(NestedInteger(1));

        NestedInteger ni2(2);

        runTest({ni11, NestedInteger(2), ni11}, 10);
    }

}