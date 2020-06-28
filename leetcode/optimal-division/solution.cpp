class Solution {
public:
    std::string optimalDivision(std::vector<int>& nums) {
        // Divide the list into 2 parts
        // Part 1 is the numerator, and part 2 is the denominator
        // In order to get the maximum result, we need to optimize the part 1 and the part 2 so that
        // numerator is the largest and denominator is the smallest.
        // Since the list is the list of positive integers so the first part (numerator) should contain ONLY one number
        // The problem becomes the optimal problem of dividing the denominator so that the value is smallest.
        // Use the same method as above we can easily find the way to minimize denominator.
        // The optimal division is always a / (b / c / d / ...)
        if (nums.size() == 1) {
            return std::to_string(nums[0]);
        }
        else if (nums.size() == 2) {
            return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
        }
        std::string result = std::to_string(nums[0]) + "/(" + std::to_string(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            result += "/" + std::to_string(nums[i]);
        }
        result += ")";

        return result;
    }
};

