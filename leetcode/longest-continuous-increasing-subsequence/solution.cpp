class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = 1;
        int index = 0;
        for (int i = 1; i < nums.size(); ++i) {
            result = nums[i] > nums[i - 1] ? std::max(i - index + 1, result) : std::max(i - index, result);
            index = nums[i] > nums[i - 1] ? index : i;
        }
        return result;
    }
};
