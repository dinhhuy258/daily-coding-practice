class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        std::vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = 0;
        int direction = 1;
        while (ans.size() != n * m) {
            ans.push_back(matrix[i][j]);
            j += direction;
            i -= direction;
            if (i >= n) {
                direction = -direction;
                j += 2;
                i = n - 1;
            }
            else if (j >= m) {
                direction = -direction;
                i += 2;
                j = m - 1;
            }
            else if (i < 0) {
                direction = -direction;
                i = 0;
            }
            else if (j < 0) {
                direction = -direction;
                j = 0;
            }
        }

        return ans;
    }
};

