class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.size()];
    }
};
