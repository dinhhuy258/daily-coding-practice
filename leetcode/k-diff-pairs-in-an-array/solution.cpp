class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        int result = 0;

        for (auto& num: nums) {
            ++count[num];
        }

        for (auto [num, _] : cnt) {
            if (k != 0 && count.count(num + k) || (k == 0 && count[num] > 1)) {
                ++result;
            }
        }

        return result;
    }
};

