class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int currentSum = 0;
        std::unordered_map<int, int> map; 
        for (auto num: nums) {
            currentSum += num;
            if (currentSum == k) {
                result += map.find(0) != map.end() ? (map[0] + 1) : 1;
            }
            else if (map.find(currentSum - k) != map.end()) {
                result += map[currentSum - k];
            }
          
            map[currentSum] = map.find(currentSum) == map.end() ? 1 : (map[currentSum] + 1);
        }
        
        return result;
    }
};
