class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (nums[middle] == target || nums[low] == target || nums[high] == target) {
                return true;
            }
            if (nums[low] < nums[middle]) {
                // Left haft is already sorted
                if (nums[low] <= target && middle - 1 >= 0 && nums[middle - 1] >= target) {
                    high = middle - 1;
                }
                else {
                    low = middle + 1;
                }
            }
            else if (nums[low] > nums[middle]) {
                // Right haft is already sorted
                if (nums[high] >= target && middle + 1 < nums.size() && nums[middle + 1] <= target) {
                    low = middle + 1;
                }
                else {
                    high = middle - 1;
                }
            }
            else {
                ++low;
                --high;
            }

        }
        return false;
    }
};

