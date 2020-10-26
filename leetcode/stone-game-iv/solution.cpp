class Solution {
public:
    bool winnerSquareGame(int n) {
        std::vector<int> squareNumbers;
        for (int i = 1; i <= n; ++i) {
            if (i * i > n) {
                break;
            }
            squareNumbers.push_back(i * i);
        }

        std::vector<bool> dp(n + 1, false);
        dp[1] = true;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < squareNumbers.size(); ++j) {
                if (i < squareNumbers[j]) {
                    break;
                }
                dp[i] = !dp[i - squareNumbers[j]];
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[n];
    }
};

