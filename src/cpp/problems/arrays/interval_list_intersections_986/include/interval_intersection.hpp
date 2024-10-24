#pragma once

#include <vector>

namespace problems::arrays::interval_intersection {

    class IntervalIntersections {
    public:
        std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& firstList,
                                                           std::vector<std::vector<int>>& secondList);
    };

}