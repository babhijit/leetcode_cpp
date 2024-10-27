#pragma once

#include <unordered_set>
#include <vector>

namespace problems::arrays::longest_common_prefix {

    /**
     * m = len(arr1)  M = max(arr1)
     * n = len(arr2)  N = max(arr2)
     * Space Complexity: O( m * log10(M) )
     * Time Complexity: O ( n*log10(M) + n*log10(N) )
     */

    class LCPUnorderedSet {
    public:
        int longestCommonPrefix(std::vector<int> &arr1, std::vector<int> &arr2) {
            std::unordered_set<int> arr1Prefixes;
            // Step 1: Build all possible prefixes from arr1
            for (int val: arr1) {
                buildPrefixes(arr1Prefixes, val);
            }

            int longestPrefix = 0;

            // Step 2: Check each number in arr2 for the longest matching prefix
            for (int val: arr2) {
                auto prefix = getLargestPrefix(arr1Prefixes, val);
                if (val > 0) {
                    longestPrefix = std::max(
                            static_cast<int>(log10(prefix)) + 1,
                            longestPrefix);
                }
            }

            return longestPrefix;
        }

    private:
        static void buildPrefixes(std::unordered_set<int> &prefixes, int val) {
            while ((prefixes.count(val) == 0) and
                   (val > 0)) {
                // insert current value as prefix
                prefixes.insert(val);
                // Generate the next shorted prefix by removing the last digit
                val /= 10;
            }
        }

        static int getLargestPrefix(std::unordered_set<int> &prefixes, int val) {
            while ((prefixes.contains(val) == 0) and (val > 0)) {
                val /= 10;
            }
            return val;
        }
    };

}