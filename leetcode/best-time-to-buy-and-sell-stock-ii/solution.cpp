class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = std::numeric_limits<int>::max();
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] <= minPrice) {
                minPrice = prices[i];
            }
            else if ((i == prices.size() - 1) || (prices[i] > prices[i + 1])) {
                maxProfit += prices[i] - minPrice;
                minPrice = std::numeric_limits<int>::max();
            }
        }
        return maxProfit;
    }
};
