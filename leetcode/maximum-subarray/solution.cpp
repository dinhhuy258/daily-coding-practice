class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = std::numeric_limits<int>::min();
        int currentSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            max = std::max(max, currentSum);
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return max;
    }
};
