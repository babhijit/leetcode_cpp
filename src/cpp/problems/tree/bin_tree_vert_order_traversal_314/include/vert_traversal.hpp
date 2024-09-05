#pragma once

#include <tree/tree_node.hpp>

#include <vector>

namespace problems::tree::vert_order_traversal {

    class VertTraversal {
    public:
        std::vector<std::vector<int>> verticalOrder(ds::tree::TreeNode* root);
    };

}