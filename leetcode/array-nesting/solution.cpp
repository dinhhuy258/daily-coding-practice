class Solution {
public:
    int arrayNesting(std::vector<int>& nums) {
        std::vector<int> visited(nums.size(), false);
        int i = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int nestingLength = 0;
            while (!visited[i]) {
                ++nestingLength;
                visited[i] = true;
                i = nums[i];
            }

            ans = std::max(ans, nestingLength);
        }

        return ans;
    }
};

