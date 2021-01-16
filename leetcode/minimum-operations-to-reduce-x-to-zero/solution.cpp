class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        auto size = nums.size();
        // Instead of finding minimum operations of prefix + suffix
        // We will find the maximum length of subarray which has sum is equal to <nums_sum> - x
        // The answer will be size = max_length_of_subarray
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        int n = sum - x;
        if (n < 0) {
            return -1;
        }

        int currentSum = 0;
        int j = 0;
        int largestSubArrayLength = -1;
        for (int i = 0; i < size; ++i) {
            currentSum += nums[i];
            while (currentSum > n) {
                currentSum -= nums[j];
                ++j;
            }
            if (currentSum == n) {
                largestSubArrayLength = std::max(largestSubArrayLength, i  - j + 1);
            }
        }

        return largestSubArrayLength == -1 ? -1 : size - largestSubArrayLength;
    }
};

