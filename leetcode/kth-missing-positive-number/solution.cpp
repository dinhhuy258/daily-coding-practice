class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        int middle;
        while (low <= high) {
            int middle = (low + high) / 2;

            if (arr[middle] - (1 + middle) < k) {
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return low + k;
    }
};

