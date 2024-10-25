#include "sorted_circular_list.hpp"

/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 */


namespace problems::list::insert_into_sorted_clist {

    ListNode *SortedCircularList::insert(ListNode *node, int insertVal) {
        auto insNode = new ListNode(insertVal);

        // edge case - no nodes
        if (not node) {
            insNode->next = insNode;
            return insNode;
        }

        // find the largest node
        auto largest = node;
        while ((node != largest->next) and (largest->val <= largest->next->val)) {
            largest = largest->next;
        }

        // for a sorted circular linked list, the smallest must come immediately to the largest node
        auto smallest = largest->next;

        // Edge case: insertVal is going to be the new smallest or greatest
        //  largest -> insNode -> smallest
        if ((insertVal < smallest->val) or (insertVal > largest->val)) {
            largest->next = insNode;
            insNode->next = smallest;
        } else {
            auto it = smallest;
            while (it->next->val < insertVal) {
                it = it->next;
            }
            insNode->next = it->next;
            it->next = insNode;
        }

        return node;
    }
}