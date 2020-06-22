class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        auto n = matrix.size();
        for (int c = 0; c < n / 2; ++c) {
            for (int r = 0; r < (n  + 1) / 2; ++r) {
                int i = c;
                int j = n - r - 1;
                std::swap(matrix[r][c], matrix[i][j]);

                std::swap(i, j);
                j = n - j - 1;
                std::swap(matrix[r][c], matrix[i][j]);

                std::swap(i, j);
                j = n - j - 1;
                std::swap(matrix[r][c], matrix[i][j]);
            }
        }
    }
};

