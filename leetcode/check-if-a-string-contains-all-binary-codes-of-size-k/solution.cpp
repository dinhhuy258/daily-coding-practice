class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() <= k) {
            return false;
        }
        std::unordered_set<int> set;
        int num = 0;
        for (int i = 0; i < k; ++i) {
            num = num << 1;
            num |= (s[i] - '0');
        }
        set.insert(num);

        for (int i = k; i < s.size(); ++i) {
            num = num & ~(1 << (k - 1));
            num = num << 1;
            num |= (s[i] - '0');
            set.insert(num);
        }

        return std::pow(2, k) == set.size();
    }
};

