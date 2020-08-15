class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[0] < b[0];
        });

        int result = 0;
        int lastEnding = std::numeric_limits<int>::min();
        for (auto& interval: intervals) {
            if (interval[0] >= lastEnding) {
                // Non-overlap
                lastEnding = interval[1];
            }
            else {
                // Overlap
                ++result;
                lastEnding = std::min(lastEnding, interval[1]);
            }
        }

        return result;
    }
};

