class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        auto numsSize = nums.size();
        for (int i = 0; i < numsSize - 1; ++i) {
            if (nums[i] == 0 && nums[i + 1] == 0) {
                return true;
            }
        }
        if (k == 0) {
            return false;
        }
        int currentSum = nums[0] % k;
        std::unordered_map<int, int> prefixSumMap;
        prefixSumMap[nums[0]] = 0;
        for (int i = 1; i < numsSize; ++i) {
            currentSum += nums[i];
            currentSum %= k;
            if (currentSum == 0) {
                return true;
            }
            if (prefixSumMap.find(currentSum) != prefixSumMap.end()) {
                if (i - prefixSumMap[currentSum] >= 2) {
                    return true;
                }
            }
            else {
                prefixSumMap[currentSum] = i;
            }
        }
        return false;
    }
};
