#include "even_odd_tree.hpp"

#include <vector>

/**
 * Space Complexity: O(N)
 * Time Complexity: O(N)
 */

namespace problems::tree::even_odd_tree {

    bool isOdd(int value) {
        return static_cast<bool>(value & 1);
    }

    bool isEven(int value) {
        return not isOdd(value);
    }

    bool validateNodeLevelValue(TreeNode* node, int level) {
        if (isOdd(level)) {
            return isOdd(node->val);
        }
        return isEven(node->val);
    }

    bool hasCorrectSequence(int lastGoodValue,
                            int currentValue,
                            int level) {
        if (isOdd(level)) {
            return lastGoodValue < currentValue;
        } else {
            return lastGoodValue > currentValue;
        }

        return false;
    }

    bool hasOddEvenSequence(std::vector<int> &latestLevelValues,
                            int level,
                            TreeNode *node) {
        // validation check for node value at level
        if (not validateNodeLevelValue(node, level)) {
            return false;
        }

        if (latestLevelValues.size() < level) {
            latestLevelValues.resize(level);
            latestLevelValues[level - 1] = node->val;
            return true;
        }

        auto &latestLevelValue = latestLevelValues[level - 1];
        if (not hasCorrectSequence(latestLevelValue, node->val, level)) {
            return false;
        }
        latestLevelValue = node->val;
        return true;
    }

    bool isEvenOddBranch(TreeNode *node,
                         std::vector<int> &levelLatestValues,
                         int level) {
        if (not node) {
            return true;
        }

        if (not hasOddEvenSequence(levelLatestValues, level, node)) {
            return false;
        }

        return isEvenOddBranch(node->left, levelLatestValues, level + 1) and
               isEvenOddBranch(node->right, levelLatestValues, level + 1);
    }

    bool EvenOddTree::isEvenOdd(TreeNode *root) {
        std::vector<int> latestLevelValues;
        return isEvenOddBranch(root, latestLevelValues, 1);
    }
}