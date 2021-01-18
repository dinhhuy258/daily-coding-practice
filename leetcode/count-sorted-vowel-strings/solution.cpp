class Solution {
public:
    int countVowelStrings(int n) {
        std::vector<int> dp(5, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 3; j >= 0; --j) {
                dp[j] += dp[j + 1];
            }
        }
        
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};

