class Solution {
public:
    int minFlipsMonoIncr(std::string s) {
        int size = s.size();
        int zeroTotal = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '0') {
                ++zeroTotal;
            }
        }

        int ans = std::min(zeroTotal, size - zeroTotal);
        int zeroCount = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '0') {
                ++zeroCount;
            }
            ans = std::min(ans, (i + 1) - zeroCount + zeroTotal - zeroCount);
        }

        return ans;
    }
};

