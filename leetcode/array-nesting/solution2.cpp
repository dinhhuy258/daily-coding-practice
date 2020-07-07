class Solution {
public:
    int arrayNesting(std::vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int nestingLength = 0;
            while (nums[i] != -1) {
                ++nestingLength;
                j = i;
                i = nums[i];
                nums[j] = -1;
            }

            ans = std::max(ans, nestingLength);
        }

        return ans;
    }
};

