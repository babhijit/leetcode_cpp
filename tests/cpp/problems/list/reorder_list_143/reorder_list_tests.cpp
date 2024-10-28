#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <reorder_list.hpp>

#include <list/list_node.hpp>
#include <list/utils/list_utils.hpp>

using namespace problems::list::reorder_list;
using namespace tests::utils;
using namespace ds::list;

namespace reorder_list_tests {

    class ReorderListTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(ListNode* head,
                     ListNode* expected) {
            ReorderList solution;
            solution.reorderList(head);
            ASSERT_TRUE(ds::list::utils::equals(head, expected));
        }

        void runTestFromResource(std::filesystem::path const &testCaseFileName) {
            auto resPath = getTestResourcePath();
            auto tcPath = resPath / testCaseFileName;
            TestCase tc(tcPath);
            runTest(tc.getHead(), tc.getExpected());

        }
    };

    TEST_F(ReorderListTests, LCScenario1) {
        runTestFromResource("lc_1.json");
    }

    TEST_F(ReorderListTests, LCScenario2) {
        runTestFromResource("lc_2.json");
    }

    TEST_F(ReorderListTests, OneNodeList) {
        runTestFromResource("lc_3.json");
    }

    TEST_F(ReorderListTests, TwoNodesList) {
        runTestFromResource("lc_4.json");
    }

    TEST_F(ReorderListTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getHead(), tc.getExpected());
                 });
    }
}