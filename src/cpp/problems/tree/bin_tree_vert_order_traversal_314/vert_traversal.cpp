#include "vert_traversal.hpp"

#include <queue>
#include <unordered_map>
#include <vector>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace problems::tree::vert_order_traversal {

    std::vector<std::vector<int>> VertTraversal::verticalOrder(ds::tree::TreeNode *root) {
        if (not root) {
            return {};
        }

        std::unordered_map<int, std::vector<int>> columnMap;
        std::queue<std::pair<int, ds::tree::TreeNode*>> queue;

        queue.emplace(0, root);
        int minColumn{}, maxColumn{};

        while (not queue.empty()) {
            auto [colIndex, node] = queue.front();
            queue.pop();

            if (not node) {
                continue;
            }

            auto& columnValues = columnMap[colIndex];
            columnValues.push_back(node->val);

            minColumn = std::min(minColumn, colIndex);
            maxColumn = std::max(maxColumn, colIndex);

            queue.emplace(colIndex - 1, node->left);
            queue.emplace(colIndex + 1, node->right);
        }

        std::vector<std::vector<int>> result;
        result.reserve(columnMap.size());

        for (int i = minColumn; i <= maxColumn; ++i) {
            result.push_back(std::move(columnMap[i]));
        }

        return result;
    }
}