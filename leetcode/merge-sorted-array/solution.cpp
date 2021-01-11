class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int currentIndex = nums1.size() - 1;
        while (true) {
            if (j < 0) {
                break;
            }
            if (i < 0 || nums1[i] <= nums2[j]) {
                nums1[currentIndex--] = nums2[j--];
            }
            else {
                nums1[currentIndex--] = nums1[i--];
            }
        }
    }
};

