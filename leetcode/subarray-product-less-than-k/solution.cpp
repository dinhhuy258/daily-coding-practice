class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int count = 0;
        int lastIndex = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[lastIndex++];
                 if (lastIndex >= n) {
                    return 0;
                }
            }


            count += (i - lastIndex + 1);
        }

        return count;
    }
};

