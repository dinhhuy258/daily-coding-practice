class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int currentMin, currentMax, globalMax;
        currentMin = currentMax = globalMax = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
            auto num = nums[i];
            auto tempCurrentMax = currentMax;
            currentMax = std::max(currentMax *  num, std::max(currentMin * num, num));
            currentMin = std::min(currentMin * num, std::min(tempCurrentMax * num, num));
            globalMax = std::max(currentMax , globalMax);
        }

        return globalMax;
    }
};

