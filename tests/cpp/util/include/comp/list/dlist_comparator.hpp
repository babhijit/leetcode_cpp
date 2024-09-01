#pragma once

#include <list/dlist_node.hpp>

#include <functional>

namespace tests::comp::list {

    struct DListComparator {
        using DListNode = ds::list::DListNode;
        using IterNode = std::function<DListNode *(DListNode *)>;

        static bool equals(DListNode *a, DListNode *b) {
            if (not a and not b) {
                return false;
            }

            if (not equals(a, b, [](DListNode *n) { return n->prev; })) {
                return false;
            }

            return equals(a, b, [](DListNode *n) { return n->next; });
        }


        static bool equals(DListNode *a, DListNode *b, const IterNode& iter) {
            while (a and b) {
                if (a->val != b->val) {
                    return false;
                }

                a = iter(a);
                b = iter(b);
            }

            if (a or b) {
                return false;
            }

            return true;
        }

    };

}