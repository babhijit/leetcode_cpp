#include "reorder_list.hpp"

#include <deque>

namespace problems::list::reorder_list {

    /**
     * Space Complexity: O(n)
     * Time Complexity: O(n)
     */

    void ReorderList::reorderList(ListNode *head) {
        std::deque<ListNode*> nodesDeque;

        for (auto it = head; it; it = it->next) {
            nodesDeque.push_back(it);
        }

        // edge case: till two nodes list no reordering is done
        if(nodesDeque.size() < 3) {
            return;
        }

        auto left = 0;
        auto right = nodesDeque.size() - 1;
        std::deque<ListNode*> newNodesOrder;
        while(left < right) {
            newNodesOrder.push_back(nodesDeque[left]);
            newNodesOrder.push_back(nodesDeque[right]);

            ++left;
            --right;
        }

        // edge case
        if (left == right) {
            newNodesOrder.push_back(nodesDeque[left]);
        }

        auto prev = newNodesOrder[0];
        for (auto i = 1; i < newNodesOrder.size(); ++i) {
            prev->next = newNodesOrder[i];
            prev = prev->next;
        }
        prev->next = nullptr;
    }
}