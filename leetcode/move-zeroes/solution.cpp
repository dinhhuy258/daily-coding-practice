class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto size = nums.size();
        int zeroIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0 && zeroIndex == -1) {
                zeroIndex = i;
            }
            else if (nums[i] != 0 && zeroIndex != -1) {
                std::swap(nums[i], nums[zeroIndex]);
                ++zeroIndex;
            } 
        }
        
    }
};
