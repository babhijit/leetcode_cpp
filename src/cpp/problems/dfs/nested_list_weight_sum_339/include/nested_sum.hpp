#pragma once

#include "nested_integer.hpp"

#include <vector>

namespace problems::dfs::nested_sum {

    class DepthSumOfNestedInteger {
    public:
        int depthSum(std::vector<NestedInteger>& nestedList);
    };

}