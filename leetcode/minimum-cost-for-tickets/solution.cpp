class Solution {
private:
    bool travelDays[366];
    int memo[366];

    int mincostTickets(int day, vector<int>& costs) {
        if (day > 365) {
            return 0;
        }
        if (memo[day] != -1) {
            return memo[day];
        }
        if (!travelDays[day]) {
            return mincostTickets(day + 1, costs);
        }

        auto cost = std::min(std::min(costs[0] + mincostTickets(day + 1, costs),
                        costs[1] + mincostTickets(day + 7, costs)), costs[2] + mincostTickets(day + 30, costs));
        memo[day] = cost;
        return cost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        std::fill(std::begin(travelDays), std::end(travelDays), false);
        std::fill(std::begin(memo), std::end(memo), -1);
        for (auto day: days) {
            travelDays[day] = true;
        }

        return mincostTickets(1, costs);
    }
};

