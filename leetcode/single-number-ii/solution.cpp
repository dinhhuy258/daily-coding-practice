class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Contains bits which appeared 1, 4, 7... times
        int one = 0;
        // Contains bits which appeared 2, 5, 8... times
        int two = 0;
        int oldOne = 0;
        for (auto& num: nums) {
            oldOne = one;
            one = (one ^ num) & ((one ^ num) ^ two);
            two ^= (two & num) ^ (oldOne & num);
        }
        return one;
    }
};