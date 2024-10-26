#include "rotated_sorted_array.hpp"

/**
 * Space Complexity: O(1)
 * Time Complexity: O(n)
 */

namespace problems::arrays::min_in_rotated_sorted_array {

    int RotatedSortedArray::findMin(std::vector<int> &nums) {
        auto begin = 0;
        auto end = nums.size() - 1;

        while (begin < end) {
            auto mid = begin + (end - begin) / 2;

            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }

        return nums[begin];
    }
}