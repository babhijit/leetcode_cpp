#pragma once

namespace ds::list {

    struct DListNode {
        int val;
        DListNode *prev;
        DListNode *next;

        explicit DListNode(int val_, DListNode *prev_, DListNode *next_) :
                val(val_), prev(prev_), next(next_) {}

        explicit DListNode(int val_, DListNode *next_) :
                DListNode(val_, nullptr, next_) {}

        explicit DListNode(int val_) :
                DListNode(val_, nullptr) {}
    };

}