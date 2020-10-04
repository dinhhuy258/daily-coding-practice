class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto& a, auto &b) {
            return a[0] < b[0];
        });
        int count = 1;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] == intervals[i - 1][0] ||
                intervals[i][1] <= intervals[i - 1][1]) {
                if (intervals[i][1] < intervals[i - 1][1]) {
                    std::swap(intervals[i], intervals[i - 1]);
                }

                continue;
            }

            ++count;
        }

        return count;
    }
};

