class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, 
                                         std::vector<int>& newInterval) {
        std::vector<std::vector<int>> result;
        int start = newInterval[0];
        int end = newInterval[1];
        bool added = false;
        for (auto& interval: intervals) {
            if (interval[1] < start) {
                result.push_back(interval);
            }
            else if (interval[0] > end) {
                if (!added) {
                    result.push_back({start, end});
                    added = true;  
                }
                result.push_back(interval);      
            }
            else {
                start = std::min(interval[0], start);
                end = std::max(interval[1], end);
            }
        }
        if (!added) {
            result.push_back({start, end});
        }
        return result;
    }
};
