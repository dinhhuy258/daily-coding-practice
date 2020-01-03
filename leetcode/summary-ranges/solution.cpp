class Solution {
public:
    std::vector<string> summaryRanges(std::vector<int>& nums) {
        std::vector<string> ranges;
        if (nums.empty()) {
            return ranges;
        }
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                ranges.push_back(nums[i - 1] == start ? 
                                 std::to_string(start) : 
                                 std::to_string(start) + "->" + std::to_string(nums[i - 1]));
                start = nums[i];
            }
        }
        ranges.push_back(nums[nums.size() - 1] == start ? 
                                 std::to_string(start) : 
                                 std::to_string(start) + "->" + std::to_string(nums[nums.size() - 1]));
        
        return ranges;
    }
};
