#pragma once

namespace ds::list {

    struct ListNode {
        int val;
        ListNode *next;

        explicit ListNode(int val_, ListNode *next_) :
                val(val_), next(next_) {}

        explicit ListNode(int val_) : ListNode(val_, nullptr) {}

    };
}