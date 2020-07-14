class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        int result = 0;
        for (int i = 0; i <= 31; ++i) {
            int bitOneCount = 0;
            for (int j = 0; j < size; ++j) {
                if (nums[j] & (1 << i)) {
                    ++bitOneCount;
                }
            }
            result += bitOneCount * (size - bitOneCount);
        }

        return result;
    }
};

