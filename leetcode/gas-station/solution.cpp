class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int tank = 0;
        int oweGas = 0;
        for (int i = 0; i < n; ++i) {
            tank += (gas[i] - cost[i]);
            if (tank < 0) {
                start = i == n - 1 ? -1 : i + 1;
                oweGas += tank;
                tank = 0;
            }
        }
        return oweGas + tank < 0 ? -1 : start;
    }
};
