class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size= nums.size();
        int min1 = nums[0];
        int min2 = std::numeric_limits<int>::max();
        for (int i = 1; i < size; ++i) {
            if (nums[i] > min2) {
                return true;
            }
            if (nums[i] <= min1) {
                min1 = nums[i];
            }
            else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }

        return false;
    }
};

