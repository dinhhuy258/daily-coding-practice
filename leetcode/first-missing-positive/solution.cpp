class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        auto n = nums.size();
        // We just only need to find the smallest missing POSITIVE integer
        // The result should be in the range [1, n + 1]
        int i = 0;
        while (i < n) {
            if (nums[i] <= 0 || nums[i] > n) {
                ++i;
                continue;
            }
            // nums[i] is in range [1, n]
            int index = nums[i] - 1;
            std::swap(nums[i], nums[index]);
            if (index <= i || nums[i] == nums[index]) {
                ++i;
            }
        }

        // Traversal the array again to find the result
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

