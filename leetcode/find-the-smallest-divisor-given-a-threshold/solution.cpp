class Solution {
private:
    int calculate(std::vector<int>& nums, int divisor) {
        int result = 0;
        for (auto& num : nums) {
            result = result + (num / divisor) + (num % divisor != 0);
        }

        return result;
    }
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int size = nums.size();
        int min = 1;
        int max = *std::max_element(nums.begin(), nums.end());
        int middle, result;
        while (min < max) {
            middle = (min + max) / 2;
            result = calculate(nums, middle);
            if (result > threshold) {
                // Divisor is small
                min = middle + 1;
            }
            else {
                // Divisor is large
                max = middle;
            }
        }
        return min;
    }
};
