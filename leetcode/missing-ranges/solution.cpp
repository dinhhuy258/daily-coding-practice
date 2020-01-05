class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    std::vector<std::string> findMissingRanges(std::vector<int> &nums, int lower, int upper) {
        std::vector<std::string> result;
        int n = nums.size();
        if (nums.empty()) {
            result.push_back(lower == upper ? std::to_string(lower) : std::to_string(lower) + "->" + std::to_string(upper));
            return result;
        }
        if (lower < nums[0]) {
            result.push_back(nums[0] - 1 == lower ? 
                             std::to_string(lower) : 
                             std::to_string(lower) + "->" + std::to_string(nums[0] - 1));
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i - 1] + 1) {
                int start = nums[i - 1] + 1;
                if (start > upper) {
                    return result;
                }
                int end = std::min(nums[i] - 1, upper);
                result.push_back(start == end ? 
                                 std::to_string(start) : 
                                 std::to_string(start) + "->" + std::to_string(end));
            }
        }
        if (nums[n - 1] != std::numeric_limits<int>::max() && nums[n - 1] + 1 <= upper) {
            result.push_back(nums[n - 1] + 1 == upper ? 
                             std::to_string(upper) : 
                             std::to_string(nums[n - 1] + 1) + "->" + std::to_string(upper));
        } 
        
        return result;
    }
};
