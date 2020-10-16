class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;

        int low = 0;
        int high = n;
        int middle;
        int searchRow = -1;
        while (low <= high) {
            middle = (low + high) / 2;
            std::cout << middle << std::endl;
            if (matrix[middle][0] <= target && matrix[middle][m] >= target) {
                searchRow = middle;
                break;
            }
            if (target < matrix[middle][0]) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        if (searchRow == -1) {
            return false;
        }

        low = 0;
        high = m;

        while (low <= high) {
            middle = (low + high) / 2;
            if (matrix[searchRow][middle] == target) {
                return true;
            }
            else if (matrix[searchRow][middle] > target) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return false;
    }
};

