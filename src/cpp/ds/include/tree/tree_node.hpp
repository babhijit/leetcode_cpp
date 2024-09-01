#pragma once

namespace ds::tree {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit TreeNode(int val_, TreeNode *left_, TreeNode *right_) :
                val(val_), left(left_), right(right_) {}

        explicit TreeNode(int val_, TreeNode *left_) : TreeNode(val_, left_, nullptr) {}

        explicit TreeNode(int val_) : TreeNode(val_, nullptr, nullptr) {}
    };

}