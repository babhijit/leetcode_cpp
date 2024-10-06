#include "max_subarray.hpp"


/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

namespace problems::array::max_subarray {

    int MaxSubarray::maxSubArray(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int runningSum = nums[0];
        int maxSum = runningSum;

        for (int i = 1; i < nums.size(); ++i) {
            auto no = nums[i];

            if (runningSum < 0) {
                runningSum = no;
            } else {
                runningSum += no;
            }

            maxSum = std::max(runningSum, maxSum);
        }

        return maxSum;
    }
}