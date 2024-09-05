#include "test_case.hpp"

#include <vert_traversal.hpp>
#include <tree/tree_node.hpp>

#include <loader/test_case_loader.hpp>
#include <res/test_resource_utils.hpp>

#include <gtest/gtest.h>

using namespace ds::tree;
using namespace problems::tree::vert_order_traversal;
using namespace tests::utils;

class BinaryTreeVertOrderTraversalTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(TreeNode *root, std::vector<std::vector<int>> const &expected) {
        VertTraversal solution;
        auto actual = solution.verticalOrder(root);

        ASSERT_EQ(expected, actual);
    }

    static void runTestCase(std::string const &input, std::vector<std::vector<int>> const &expected) {
        TreeNode *root = TestCase::loadBst(input);
        runTest(root, expected);
    }

    static void runTestCase(std::filesystem::path const &testcase) {
        TestCase tc(testcase);

        TreeNode *root = tc.getInput();
        auto expected = tc.getExpected();
        runTest(root, expected);
    }
};

TEST_F(BinaryTreeVertOrderTraversalTests, Scenario1) {
    runTestCase("3,9,20,null,null,15,7", {{9},
                                            {3, 15},
                                            {20},
                                            {7}});
}

TEST_F(BinaryTreeVertOrderTraversalTests, Scenario2) {
    runTestCase("3,9,8,4,0,1,7", {{4},
                                    {9},
                                    {3, 0, 1},
                                    {8},
                                    {7}});
}

TEST_F(BinaryTreeVertOrderTraversalTests, RunTestsFromResources) {
    auto resPath = getTestResourcePath();

    TestCaseLoader tcLoader;
    tcLoader(resPath,
             [this](auto &fileName) {
                 TestCase tc(fileName);
                 runTest(tc.getInput(), tc.getExpected());
             });
}