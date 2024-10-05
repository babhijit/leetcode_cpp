#include "merge_intervals.hpp"

#include <algorithm>

/**
 * Time Complexity: n log (n) -> taken by sorting. The implementation itself is O(n).
 * Space Complexity: n (if sorting algo takes linear space) else log (n) -> min space requirements for sorting algo
 */

namespace problems::arrays::merge_intervals {

    enum {
        START = 0,
        END
    };

    std::vector<std::vector<int>> MergeIntervals::merge(std::vector<std::vector<int>> &intervals) {
        // edge case: no intervals provided
        if (intervals.empty()) {
            return {};
        }

        // sort by start interval only
        auto CoordinateComparator = [](std::vector<int>& a, std::vector<int>& b) {
            return (a[START] < b[START]);
        };

        std::sort(std::begin(intervals), std::end(intervals), CoordinateComparator);
        std::vector<std::vector<int>> mergedIntervals;

        int index = 0;
        std::vector<int> currentWindow = intervals[0];

        while (++index < intervals.size()) {
            auto& currentInterval = intervals[index];

            // overlapping interval?
            if (currentInterval[START] <= currentWindow[END]) {
                if (currentInterval[END] > currentWindow[END]) {
                    currentWindow[END] = currentInterval[END];
                }
            } else { // non overlapping window
                mergedIntervals.push_back(currentWindow);
                currentWindow = currentInterval;
            }
        }

        // add the last window interval
        mergedIntervals.push_back(currentWindow);

        return mergedIntervals;
    }
}