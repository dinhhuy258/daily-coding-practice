class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> minPath(n, std::vector<int>(m, std::numeric_limits<int>::max()));
        minPath[0][0] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j != 0) {
                    minPath[i][j] = std::min(minPath[i][j], minPath[i][j - 1] + grid[i][j]);
                }
                if (i != 0) {
                    minPath[i][j] = std::min(minPath[i][j], minPath[i - 1][j] + grid[i][j]);
                }
            }
        }
        
        return minPath[n - 1][m - 1];
    }
};
