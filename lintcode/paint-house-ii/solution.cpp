
class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<std::vector<int>> &costs) {
        if (costs.empty()) {
            return 0;
        }
        int numberOfHouses = costs.size();
        int numberOfColors = costs[0].size();
        std::vector<std::vector<int>> dp(2, std::vector<int>(numberOfColors, std::numeric_limits<int>::max()));
        int lastMinCost = 0;
        int lastSecondMinCost = 0;
        int lastMinCostIndex = 0;
        for (int i = 0; i <= numberOfHouses; ++i) {
            int minCost = std::numeric_limits<int>::max();
            int secondMinCost = std::numeric_limits<int>::max();
            int minCostIndex = -1;
            for (int j = 0; j < numberOfColors; ++j) {
                dp[i % 2][j] = (i == 0) ? 0 : (j == lastMinCostIndex ? lastSecondMinCost : lastMinCost) + costs[i - 1][j];
                if (minCost > dp[i % 2][j]) {
                    secondMinCost = minCost;
                    minCost = dp[i % 2][j];
                    minCostIndex = j;
                }
                else {
                    secondMinCost = std::min(secondMinCost, dp[i % 2][j]);
                }
            }
            lastMinCost = minCost;
            lastSecondMinCost = secondMinCost;
            lastMinCostIndex = minCostIndex;
        }
        
        return *std::min_element(dp[numberOfHouses % 2].begin(), dp[numberOfHouses % 2].end());
    }
};
