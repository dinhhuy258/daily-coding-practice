class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        std::sort(nums.begin(), nums.end());
        std::vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        int index = 1;
        for (int i = 2; i <= nums.size(); ++i) {
            dp[i] = 1;
            for (int j = i - 1; j >= 1; --j) {
                if (nums[i - 1] % nums[j - 1] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    if (dp[i] > dp[index]) {
                        index = i;
                    }
                }
            }
        }
        
        std::vector<int> result;
        while(index > 0) {
            result.push_back(nums[index - 1]);
            auto lastIndex = index;
            --index;
            while(index > 0 && (dp[index] != dp[lastIndex] - 1 || result.back() % nums[index - 1] != 0)) {
                --index;
            }
        }
        
        return result;
    }
};

