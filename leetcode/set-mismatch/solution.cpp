class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        int sum1 = (size * (size + 1)) / 2;
        int sum2 = std::accumulate(nums.begin(), nums.end(), 0);
        int duplicateNumber = -1;
        for (int i = 0; i < size; ++i) {
            auto index = std::abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
            else {
                duplicateNumber = index + 1;
            }
        }

        return {duplicateNumber, duplicateNumber + sum1 - sum2};
    }
};

