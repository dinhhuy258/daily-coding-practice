class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        std::vector<std::pair<int, int>> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = std::make_pair(intervals[i][0], i);
        }
        std::sort(starts.begin(), starts.end());

        std::vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            int l = 0;
            int h = n - 1;
            while (l <= h) {
                auto m = (l + h) / 2;
                if (starts[m].first == intervals[i][1]) {
                    result[i] = starts[m].second;
                    break;
                }
                else if (starts[m].first < intervals[i][1]) {
                    l = m + 1;
                }
                else {
                    result[i] = starts[m].second;
                    h = m - 1;
                }
             }
        }
        return result;
    }
};

