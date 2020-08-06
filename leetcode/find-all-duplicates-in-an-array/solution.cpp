class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[std::abs(nums[i]) - 1] < 0) {
                result.push_back(std::abs(nums[i]));
            }
            else {
                nums[std::abs(nums[i]) - 1] *= -1;
            }
        }

        return result;
    }
};

