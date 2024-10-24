#pragma once

namespace ds::tree {

    struct TreeParentNode {
        int val;
        TreeParentNode *left;
        TreeParentNode *right;
        TreeParentNode *parent;

        explicit TreeParentNode(int val_, TreeParentNode *parent_, TreeParentNode *left_, TreeParentNode *right_) :
                val(val_), parent(parent_), left(left_), right(right_) {}

        explicit TreeParentNode(int val_, TreeParentNode *left_, TreeParentNode *right_) :
                TreeParentNode(val_, nullptr, left_, right_) {}

        explicit TreeParentNode(int val_, TreeParentNode *parent_) : TreeParentNode(val_, parent_, nullptr, nullptr) {}

        explicit TreeParentNode(int val_) : TreeParentNode(val_, nullptr, nullptr, nullptr) {}
    };

}