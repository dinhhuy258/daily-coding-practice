namespace {
    constexpr int dx[] = {-1, 0, 1, 0};
    constexpr int dy[] = {0, -1, 0, 1};
}

class Solution {
private:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix,
                              std::vector<std::vector<int>>& longestIncreasing,
                              int x, int y) {
        int n = matrix.size();
        int m = matrix[0].size();
        int longestPath = 0;
        for (int i = 0; i < 4; ++i) {
            int newY = dy[i] + y;
            int newX = dx[i] + x;
            if (newY >= 0 && newY < n && 
                newX >= 0 && newX < m && 
                matrix[y][x] < matrix[newY][newX]) {
                // Valid coordinate
                longestIncreasing[newY][newX] = longestIncreasing[newY][newX] ? 
                    longestIncreasing[newY][newX] : longestIncreasingPath(matrix, longestIncreasing, newX, newY);
                longestPath = std::max(longestPath, longestIncreasing[newY][newX]);
            }
        }
        longestIncreasing[y][x] = 1 + longestPath;
        return longestIncreasing[y][x];
    }
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int result = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        std::vector<std::vector<int>> longestIncreasing(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!longestIncreasing[i][j]) {
                    result = std::max(result, longestIncreasingPath(matrix, longestIncreasing, j, i));
                }
            }
        }
        
        return result;
    }
};
