class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (high >= low) {
            if (high == low) {
                return nums[high] == target ? high : -1;
            }
            int middle = (low + high) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            if (nums[low] < nums[middle]) {
                // half left is sorted
                if (nums[low] <= target &&
                    middle - 1 >= 0 &&
                    nums[middle - 1] >= target) {
                    high = middle - 1;
                }
                else {
                    low = middle + 1;
                }
            }
            else {
                // half right is sorted
                if (middle + 1 < nums.size() &&
                    nums[middle + 1] <= target && nums[high] >= target) {
                    low = middle + 1;
                }
                else {
                    high = middle - 1;
                }
            }
        }
        return -1;
    }
};

