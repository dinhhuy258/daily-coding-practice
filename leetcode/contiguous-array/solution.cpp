class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return 0;
        }
        
        std::unordered_map<int, int> sumMap;
        sumMap[0] = -1;
        int currentSum = 0;
        int maxLength = 0;
        for (int i = 0; i < size; ++i) {
            currentSum += nums[i] ? 1 : -1;
            if (sumMap.find(currentSum) != sumMap.end()) {
                maxLength = std::max(maxLength, i - sumMap[currentSum]);
            }
            else {
                sumMap[currentSum] = i;
            }
        }
        
        return maxLength;
    }
};