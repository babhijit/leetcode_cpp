#include "test_case.hpp"

#include <even_odd_tree.hpp>

#include <loader/test_case_loader.hpp>
#include <res/test_resource_utils.hpp>

#include <tree/tree_node.hpp>

#include <gtest/gtest.h>

using namespace ds::tree;
using namespace problems::tree::even_odd_tree;
using namespace tests::utils;

namespace even_odd_tree_tests {

    class EvenOddTreeTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void runTest(TreeNode *root, bool expected) {
            EvenOddTree solution;
            auto actual = solution.isEvenOdd(root);

            ASSERT_EQ(expected, actual);
        }

        static void runTestCase(std::string const &input, bool expected) {
            auto root = TestCase::loadBinaryTree(input);
            runTest(root, expected);
        }

        static void runTestCase(std::filesystem::path const &testcase) {
            TestCase tc(testcase);

            auto root = tc.getRoot();
            auto expected = tc.getExpected();
            runTest(root, expected);
        }
    };

    TEST_F(EvenOddTreeTests, Scenario1) {
        runTestCase("1,10,4,3,null,7,9,12,8,6,null,null,2", true);
    }

    TEST_F(EvenOddTreeTests, Scenario2) {
        runTestCase("5,4,2,3,3,7", false);
    }

    TEST_F(EvenOddTreeTests, Scenario3) {
        runTestCase("5,9,1,3,5,7", false);
    }

    TEST_F(EvenOddTreeTests, Scenario4) {
        runTestCase("2,12,8,5,9,null,null,18,16", false);
    }

    TEST_F(EvenOddTreeTests, RunTestsFromResources) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getRoot(), tc.getExpected());
                 });
    }

}