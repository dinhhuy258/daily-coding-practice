class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = std::max(i, j);
                    continue;
                }
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

