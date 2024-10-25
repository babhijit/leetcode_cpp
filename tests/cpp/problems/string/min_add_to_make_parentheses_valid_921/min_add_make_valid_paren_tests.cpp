#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <min_add_make_valid_paren.hpp>

using namespace problems::string::min_add_make_valid_paren;
using namespace tests::utils;

namespace min_add_make_valid_param_tests {

    class MinAddMakeValidParamTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::string s, int expected) {
            MinAddToMakeValidParen solution;
            auto actual = solution.minAddToMakeValid(s);
            ASSERT_EQ(expected, actual);
        }
    };

    TEST_F(MinAddMakeValidParamTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getS(), tc.getExpected());
                 });
    }


}