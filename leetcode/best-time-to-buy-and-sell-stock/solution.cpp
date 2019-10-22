class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if (prices.empty()) {
            return maxProfit;
        }
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
            minPrice = std::min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
