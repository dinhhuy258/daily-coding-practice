class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector<int> locations(1001, 0);
        for (auto& trip: trips) {
            for (int i = trip[1]; i < trip[2]; ++i) {
                locations[i] += trip[0];
                if (locations[i] > capacity) {
                    return false;
                }
            }
        }
        return true;
    }
};

