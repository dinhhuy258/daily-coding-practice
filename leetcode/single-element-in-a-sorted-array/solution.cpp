class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high) {
            int middle = (high + low) / 2;
            if (middle == 0 || middle == nums.size() - 1 || (nums[middle - 1] != nums[middle] && nums[middle + 1] != nums[middle])) {
                return nums[middle];
            }
            high = (nums[middle] == nums[middle - 1]) ? ((middle - low) % 2 == 0 ? middle : high) : ((high - middle) % 2 == 0 ? high : middle - 1);
            low  = (nums[middle] == nums[middle - 1]) ? ((middle - low) % 2 == 0 ? low : middle + 1) : ((high - middle) % 2 == 0 ? middle : low);
        }
        
        return nums[low];
    }
};
