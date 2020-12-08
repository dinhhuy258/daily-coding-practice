class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        std::vector<int> remainders(60, 0);
        for (int i = 0; i < time.size(); ++i) {
            ++remainders[time[i] % 60];
        }
        int ans = 0;
        for (int i = 1; i <= remainders[0] - 1; ++i) {
            ans += i;
        }
        for (int i = 1; i <= remainders[30] - 1; ++i) {
            ans += i;
        }
        for (int i = 1; i <= 29; ++i) {
            ans += (remainders[i] * remainders[60 - i]);
        }

        return ans;
    }
};

