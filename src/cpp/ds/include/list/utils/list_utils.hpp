#pragma once

#include <list/list_node.hpp>

namespace ds::list::utils {

    bool equals(ListNode* a, ListNode* b) {
        auto aIt = a;
        auto bIt = b;

        while (aIt and bIt) {
            if (aIt->val != b->val) {
                return false;
            }
            aIt = aIt->next;
            bIt = bIt->next;
        }

        return (not aIt and not bIt);
    }

    bool circularEquals(ListNode* circularA, ListNode* circularB) {
        auto bHead = circularB;
        auto aHead = circularA;
        do {
            if (aHead->val != bHead->val) {
                return false;
            }
            aHead = aHead->next;
            bHead = bHead->next;
        } while (aHead != circularA and bHead != circularB);

        return true;
    }
}