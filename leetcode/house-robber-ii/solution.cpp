class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        std::vector<int> dp1(nums.size() - 1, 0);
        std::vector<int> dp2(nums.size() - 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (i != nums.size() - 1) {
                dp1[i] = (i == 0) ? nums[0] : ((i == 1) ? std::max(nums[0], nums[1]) : std::max(dp1[i - 1], dp1[i - 2] + nums[i]));
            }
            if (i != 0) {
                dp2[i - 1] = (i == 1) ? nums[1] : ((i == 2) ? std::max(nums[1], nums[2]) : std::max(dp2[i - 2], dp2[i - 3] + nums[i]));
            }
        }
        return std::max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
    }
};
