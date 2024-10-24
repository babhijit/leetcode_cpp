#include "interval_intersection.hpp"

/**
 * Space Complexity: O(n)
 * Time Complexity: O(n)
 */

namespace problems::arrays::interval_intersection {

    template<typename T>
    using Vector2D = std::vector<std::vector<T>>;

    enum Index {
        START = 0,
        END
    };

    bool isNotOverlapping(std::vector<int> const& a, std::vector<int> const& b) {
        return (a[START] > b[END]) or (b[START] > a[END]);
    }

    bool isIntervalEmpty(std::vector<std::vector<int>> const& interval) {
        if (interval.empty()) {
            return true;
        }

        if (interval.size() == 1 and interval[0].empty()) {
            return true;
        }

        return false;
    }

    Vector2D<int> IntervalIntersections::intervalIntersection(Vector2D<int> &firstList,
                                                              Vector2D<int> &secondList) {
        if (isIntervalEmpty(firstList) or isIntervalEmpty(secondList)) {
            return {{}};
        }

        Vector2D<int> intersections;

        auto firstItr = firstList.begin();
        auto secondItr = secondList.begin();

        while ((firstItr != firstList.end()) and (secondItr != secondList.end())) {
            auto& first = *firstItr;
            auto& second = *secondItr;

            if (not isNotOverlapping(first, second)) {
                int start = std::max(first[START], second[START]);
                int end = std::min(first[END], second[END]);
                intersections.push_back({start, end});
            }

            if (first[END] < second[END]) {
                ++firstItr;
            } else if (first[END] > second[END]) {
                ++secondItr;
            } else { // this block will not execute as the intervals are disjoint
                ++firstItr;
                ++secondItr;
            }
        }


        return intersections;
    }

}