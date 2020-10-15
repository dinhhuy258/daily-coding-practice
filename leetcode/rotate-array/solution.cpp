class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        auto size = nums.size();
        k = k % size;

        int count = 0;
        int index = 0;
        int start = 0;
        int lastValue = nums[0];
        while (count < size) {
            ++count;
            index = index + k;
            if (index >= size) {
                index -= size;
            }
            std::swap(nums[index], lastValue);
            if (index == start) {
                ++start;
                ++index;
                lastValue = nums[index];
            }
        }
    }
};

