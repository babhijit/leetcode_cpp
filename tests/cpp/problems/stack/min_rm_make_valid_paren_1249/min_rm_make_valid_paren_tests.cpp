#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <min_rem_make_valid_paren.hpp>

using namespace problems::stack::min_rm_valid_paren;
using namespace tests::utils;

namespace min_rm_make_valid_param_tests {

    class MinRemValidParamTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(std::string s, const std::set<std::string>& expected) {
            MinRemMakeValidParen solution;
            auto actual = solution.minRemoveToMakeValid(s);
            ASSERT_TRUE(expected.contains(actual));
        }
    };

    TEST_F(MinRemValidParamTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getS(), tc.getExpected());
                 });
    }


}