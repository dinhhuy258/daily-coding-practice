class Solution {
public:
    int maxUncrossedLines(std::vector<int>& A, std::vector<int>& B) {
        std::vector<std::vector<int>> dp(A.size() + 1, std::vector<int>(B.size() + 1, 0));
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[A.size()][B.size()];
    }
};

