class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high - 1) {
            int middle = (low + high) / 2;
            if (nums[middle] < nums[high]) {
                high = middle;
            }
            else {
                low = middle;
            }
        }
        return low == high ? nums[low] : std::min(nums[low], nums[high]);
    }
};