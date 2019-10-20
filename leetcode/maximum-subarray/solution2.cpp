class Solution {
private:
    int maxSubArray(std::vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        int middle = (left + right) / 2;
        int leftSum = maxSubArray(nums, left, middle);
        int rightSum = maxSubArray(nums, middle + 1, right);
        int crossingSum = std::numeric_limits<int>::min();
        int sum = 0;
        for (int i = middle; i >= left; --i) {
            sum += nums[i];
            crossingSum = std::max(crossingSum, sum);
        }
        if (crossingSum != std::numeric_limits<int>::min()) {
            sum = crossingSum;
            for (int i = middle + 1; i <= right; ++i) {
                sum += nums[i];
                crossingSum = std::max(crossingSum, sum);
            }
        }
        return std::max(std::max(leftSum, rightSum), crossingSum);
    }
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return std::numeric_limits<int>::min();
        }
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};
