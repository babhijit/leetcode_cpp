#include "k_largest.hpp"

#include <queue>

/**
 * Time Complexity: O (N log N)
 * Space Complexity: O ( N )
 */

namespace problems::array::k_largest {

    int KLargest::findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int> heap(nums.begin(), nums.end());
        while (--k > 0) {
            heap.pop();
        }

        return heap.top();
    }

}