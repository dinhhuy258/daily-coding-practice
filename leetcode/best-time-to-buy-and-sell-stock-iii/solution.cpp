class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        std::vector<int> profits = std::vector<int>(n, 0);

        auto buyPrice = prices[0];
        auto profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > buyPrice) {
                profit = std::max(prices[i] - buyPrice, profit);
                profits[i] = profit;
            }
            else {
                profits[i] = profits[i - 1];
                buyPrice = std::min(buyPrice, prices[i]);
            }
        }

        auto sellPrice = prices[n - 1];
        profit = 0;
        auto maxProfit = profits[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (prices[i] < sellPrice) {
                profit = std::max(sellPrice - prices[i], profit);
                maxProfit = i == 0 ? std::max(maxProfit, sellPrice - prices[i]) : std::max(maxProfit, profit + profits[i - 1]);
            }
            else {
                sellPrice = std::max(sellPrice, prices[i]);
            }
        }

        return maxProfit;
    }
};

