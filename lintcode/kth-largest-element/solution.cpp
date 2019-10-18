class Solution {
private:
    /**
     * @param nums: An array
     * @param left
     * @param right
     * @return: an index of partition
     */
    int partition(std::vector<int> &nums, int left, int right) {

        int pivot = nums[right];
        int i = 0;
        for (int j = 0; j < right; ++j) {
            if (nums[j] > pivot) {
                std::swap(nums[i++], nums[j]);
            }
        }
        std::swap(nums[i], nums[right]);
        return i;
    }

    /**
     * @param nums: An array
     * @param left
     * @param right
     * @param k
     * @return: the Kth largest element
     */
    int kthLargestElement(std::vector<int> &nums, int left, int right, int k) {
        if (k >= 0 && right - left >= k) {
            int partitionIndex = partition(nums, left, right);
            if (partitionIndex - left == k) {
                return nums[partitionIndex];
            }
            if (partitionIndex - left > k) {
                return kthLargestElement(nums, left, partitionIndex - 1, k);
            }
            return kthLargestElement(nums, partitionIndex + 1, right, k + left - partitionIndex - 1);
        }
        return -1;
    }
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        return kthLargestElement(nums, 0, nums.size() - 1, n - 1);
    }
};
