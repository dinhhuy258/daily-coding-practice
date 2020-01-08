class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(std::vector<std::vector<int>> &costs) {
        int numberOfHouses = costs.size();
        std::vector<std::vector<int>> dp(numberOfHouses + 1, std::vector<int>(3, std::numeric_limits<int>::max()));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i <= numberOfHouses; ++i) {
            dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        
        return std::min(dp[numberOfHouses][0], std::min(dp[numberOfHouses][1], dp[numberOfHouses][2]));
    }
};
