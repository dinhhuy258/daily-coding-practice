class Solution {
private:
   int binarySearch(std::vector<int>& nums, int target, bool findFirst) {
       int low = 0;
       int high = nums.size();
       while (low < high) {
           int middle = (low + high) / 2;
           if (nums[middle] > target || (findFirst && nums[middle] == target)) {
               high = middle;
           }
           else {
               low = middle + 1;
           }
       }
       return low;
   }
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> range = {-1, -1};
        int firstPosition = binarySearch(nums, target, true);
        if (firstPosition == nums.size() || nums[firstPosition] != target) {
            return range;
        }
        range[0] = firstPosition;
        int secondPosition = binarySearch(nums, target, false) - 1;
        range[1] = secondPosition;
        return range;
    }
};