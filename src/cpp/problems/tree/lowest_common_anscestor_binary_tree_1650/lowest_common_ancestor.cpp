#include "lowest_common_ancestor.hpp"

/**
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 */

namespace problems::tree::lowest_common_ancestor {

    std::vector<TreeParentNode*> getAncestors(TreeParentNode* node) {
        std::vector<TreeParentNode*> ancestors;
        while(node) {
            ancestors.push_back(node);
            // move up the hierarchy
            node = node->parent;
        }
        return ancestors;
    }


    TreeParentNode *LowestCommonAncestor::lowestCommonAncestor(TreeParentNode *p, TreeParentNode *q) {
        auto pParents = getAncestors(p);
        auto qParents = getAncestors(q);

        auto itP = pParents.rbegin();
        auto itQ = qParents.rbegin();

        TreeParentNode* lca {};
        while ((itP != pParents.rend()) and (itQ != qParents.rend())) {
            if (*itP != *itQ) {
                break;
            }
            lca = *itP;
            ++itP;
            ++itQ;
        }
        return lca;
    }
}