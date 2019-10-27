class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int n = nums.size();
        int count1, count2, majority1, majority2;
        count1 = count2 = 0;
        majority1 = majority2 = std::numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == majority1) {
                ++count1;
            }
            else if (nums[i] == majority2) {
                ++count2;
            }
            else if (count1 == 0) {
                count1 = 1;
                majority1 = nums[i];
            }
            else if (count2 == 0) {
                count2 = 1;
                majority2 = nums[i];
            }
            else {
                --count1;
                --count2;
            }
        }
        count1 = count2 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == majority1) {
                ++count1;
            }
            else if (nums[i] == majority2) {
                ++count2;
            }
        }
        std::vector<int> result;
        result.reserve(2);
        if (count1 > n / 3) {
            result.push_back(majority1);
        }
        if (count2 > n / 3) {
            result.push_back(majority2);
        }
        return result;
    }
};
