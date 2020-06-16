class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                // 0
                if (i == 0 || s[i - 1] == '0' || s[i - 1] >= '3') {
                    // Invalid string
                    return 0;
                }
                dp[i + 1] = dp[i - 1];
            }
            else {
                // 1 2 3 4 5 6 7 8 9
                dp[i + 1] = dp[i];
                if (i != 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                    dp[i + 1] += dp[i - 1];
                }
            }
        }

        return dp[s.size()];
    }
};

