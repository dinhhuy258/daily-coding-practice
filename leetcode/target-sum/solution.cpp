class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int S) {
        int maxSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxSum += nums[i];
        }
        if (nums.size() == 0 || std::abs(S) > maxSum) {
            return 0;
        }
        
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(maxSum * 2 + 1, 0));
        ++dp[0][nums[0] + maxSum];
        ++dp[0][-nums[0] + maxSum];

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = -maxSum; j <= maxSum; ++j) {
                if (j - nums[i] <= maxSum && j - nums[i] >= -maxSum && dp[i - 1][j - nums[i] + maxSum] != 0) {
                    dp[i][j + maxSum] += dp[i - 1][j - nums[i] + maxSum];
                }
                if (j + nums[i] <= maxSum && j + nums[i] >= -maxSum && dp[i - 1][j + nums[i] + maxSum] != 0) {
                    dp[i][j + maxSum] += dp[i - 1][j + nums[i] + maxSum];
                }
            }
        }

        return dp[nums.size()  - 1][S + maxSum];
    }
};
