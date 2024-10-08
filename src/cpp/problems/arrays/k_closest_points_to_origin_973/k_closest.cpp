#include "k_closest.hpp"

#include <queue>

/**
 * Time Complexity: O (N log K)
 * Space Complexity: O (K)
 */

namespace problems::arrays::k_closest {

    enum COORDINATE {
        X = 0, Y = 1
    };

    long distance(std::vector<int> const &point) {
        return (point[X] * point[X]) + (point[Y] * point[Y]);
    }

    struct PointComparator {
        bool operator()(std::vector<int>& ptA, std::vector<int>& ptB) {
            long distA = distance(ptA);
            long distB = distance(ptB);

            return distA < distB;
        }
    };

    std::vector<std::vector<int>> KClosestPoints::kClosest(std::vector<std::vector<int>> &points, int k) {
        using Point = std::vector<int>;
        using Matrix = std::vector<Point>;

        std::priority_queue<Point, Matrix, PointComparator> heap;
        for (auto& pt: points) {
            heap.push(pt);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        Matrix result;
        result.reserve(k);
        while (not heap.empty()) {
            result.push_back(heap.top());
            heap.pop();
        }

        return result;
    }
}