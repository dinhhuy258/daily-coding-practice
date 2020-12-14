class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        // Add padding to the beginning and end of the array
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // dp[left][right] is the maximum coins you can collect by bursting the balloons from left to right 
        std::vector<std::vector<int>> dp(size + 2, std::vector<int>(size + 2, 0));
        for (int length = 1; length <= size; ++length) {
            for (int left = 1; left < size - length + 2; ++left) {
                int right = left + length - 1;
                // Assume that last is the last bursting balloon
                for (int last = left; last <= right; ++last) {
                    dp[left][right] = std::max(dp[left][right], dp[left][last - 1] + dp[last + 1][right] + nums[left - 1] * nums[last] * nums[right + 1]);
                }
            }
        }

        return dp[1][size];
    }
};
