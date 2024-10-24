#pragma once

#include <tree/tree_parent_node.hpp>

#include <vector>

namespace problems::tree::lowest_common_ancestor {

    using namespace ds::tree;

    class LowestCommonAncestor {
    public:
        TreeParentNode *lowestCommonAncestor(TreeParentNode *p, TreeParentNode *q);
    };

}