class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2;
        int j = 2;
        int size = nums.size();

        while (i < size) {
            if (nums[i] != nums[j - 2]) {
                std::swap(nums[i], nums[j]);
                ++j;
            }
            ++i;
        }
        while (j < size) {
            nums.pop_back();
            ++j;
        }

        return nums.size();
    }
};

