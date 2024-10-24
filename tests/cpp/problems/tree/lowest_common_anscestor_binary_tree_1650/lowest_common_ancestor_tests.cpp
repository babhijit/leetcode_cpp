#include "test_case.hpp"

#include <lowest_common_ancestor.hpp>

#include <loader/test_case_loader.hpp>
#include <res/test_resource_utils.hpp>

#include <tree/tree_parent_node.hpp>

#include <gtest/gtest.h>

using namespace ds::tree;
using namespace problems::tree::lowest_common_ancestor;
using namespace tests::utils;

class LowestCommonAncestortests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(TreeParentNode *p, TreeParentNode* q, int expected) {
        LowestCommonAncestor solution;
        auto actual = solution.lowestCommonAncestor(p, q);

        ASSERT_EQ(expected, actual->val);
    }

    static void runTestCase(std::string const &root, int pVal, int qVal, int expected) {
        auto [p, q] = TestCase::loadBinaryTree(root, pVal, qVal);
        runTest(p, q, expected);
    }

    static void runTestCase(std::filesystem::path const &testcase) {
        TestCase tc(testcase);

        auto p = tc.getP();
        auto q = tc.getQ();
        auto expected = tc.getExpected();
        runTest(p, q, expected);
    }
};

TEST_F(LowestCommonAncestortests, Scenario1) {
    runTestCase("3,5,1,6,2,0,8,null,null,7,4", 5, 1, 3);
}

TEST_F(LowestCommonAncestortests, Scenario2) {
    runTestCase("3,5,1,6,2,0,8,null,null,7,4", 5, 4, 5);
}

TEST_F(LowestCommonAncestortests, Scenario3) {
    runTestCase("1,2", 1, 2, 1);
}

TEST_F(LowestCommonAncestortests, RunTestsFromResources) {
    auto resPath = getTestResourcePath();

    TestCaseLoader tcLoader;
    tcLoader(resPath,
             [this](auto &fileName) {
                 TestCase tc(fileName);
                 runTest(tc.getP(), tc.getQ(), tc.getExpected());
             });
}