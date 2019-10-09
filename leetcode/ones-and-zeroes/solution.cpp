class Solution {
private:
    int countOnes(const std::string& str) {
        int result = 0;
        for (int i = 0; i < str.size(); ++i) {
            result += str[i] == '1';
        }
        return result;
    }
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (auto& str: strs) {
            int numberOfOnes = countOnes(str);
            int numberOfZeroes = str.length() - numberOfOnes;
            for (int i = m; i >= 0; --i) {
                if (i < numberOfZeroes) {
                    continue;
                }
                for (int j = n; j >= 0; --j) {
                    if (j < numberOfOnes) {
                        continue;
                    }
                    dp[i][j] = std::max(dp[i][j], dp[i - numberOfZeroes][j - numberOfOnes] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
