#include "nested_sum.hpp"


/**
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 */

namespace problems::dfs::nested_sum {

    int getNestedSum(NestedInteger const &ni, int depth = 1) {
        if (ni.isInteger()) {
            return depth * ni.getInteger();
        }

        int sum = 0;

        for (auto &element: ni.getList()) {
            sum += getNestedSum(element, depth + 1);
        }

        return sum;
    }

    int DepthSumOfNestedInteger::depthSum(std::vector<NestedInteger> &nestedList) {
        int sum = 0;

        for (auto &ni: nestedList) {
            sum += getNestedSum(ni);
        }

        return sum;
    }

}