#pragma once

#include <list/list_node.hpp>

namespace tests::comp::list {

    struct ListComparator {
        using ListNode = ds::list::ListNode;

        static bool equals(ListNode* a, ListNode* b) {
            if (not a and not b) {
                return false;
            }

            if (not a)      return false;
            if (not b)      return false;

            while (a and b) {
                if (a->val != b->val) {
                    return false;
                }

                a = a->next;
                b = b->next;
            }

            if (a or b) {
                return false;
            }

            return true;
        }

    };

}