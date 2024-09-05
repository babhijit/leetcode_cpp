#pragma once

#include <vector>

namespace problems::arrays::k_closest {

    class KClosestPoints {
    public:
        std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k);
    };

}