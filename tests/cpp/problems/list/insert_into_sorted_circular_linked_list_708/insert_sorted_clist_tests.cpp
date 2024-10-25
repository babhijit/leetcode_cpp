#include <gtest/gtest.h>

#include "test_case.hpp"

#include <loader/test_case_loader.hpp>

#include <res/test_resource_utils.hpp>

#include <sorted_circular_list.hpp>

#include <list/list_node.hpp>
#include <list/utils/list_utils.hpp>

using namespace problems::list::insert_into_sorted_clist;
using namespace tests::utils;
using namespace ds::list;

namespace insert_into_sorted_clist_tests {

    class InsertIntoSortedCircularListTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    public:
        void runTest(ListNode* head,
                     int insertVal,
                     ListNode* expected) {
            SortedCircularList solution;
            auto actual = solution.insert(head, insertVal);
            ASSERT_TRUE(ds::list::utils::circularEquals(actual, expected));
        }
    };

    TEST_F(InsertIntoSortedCircularListTests, RunTestsFromResource) {
        auto resPath = getTestResourcePath();

        TestCaseLoader tcLoader;
        tcLoader(resPath,
                 [this](auto &fileName) {
                     TestCase tc(fileName);
                     runTest(tc.getHead(), tc.getInsertVal(), tc.getExpected());
                 });
    }
}