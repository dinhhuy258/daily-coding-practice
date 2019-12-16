class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int largestSquare = 0;
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') {
                    continue;
                }
                dp[i][j] = (i == 0 || j == 0) ? 1 : (std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1);
                largestSquare = std::max(largestSquare, dp[i][j] * dp[i][j]);
            }
        }
        return largestSquare;
    }
};
