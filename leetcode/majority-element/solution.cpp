class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int majorityElement = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != majorityElement) {
                --count;
                if (count == 0) {
                    count = 1;
                    majorityElement = nums[i];
                }
            }
            else {
                ++count;
            }
        }
        return majorityElement;
    }
};
