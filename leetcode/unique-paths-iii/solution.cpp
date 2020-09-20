class Solution {
private:
    std::vector<std::vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void uniquePathsIII(std::vector<std::vector<int>>& grid, int x, int y, int numEmptySquares, int currentEmptySquares, std::vector<std::vector<bool>>& visited, int &result) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < directions.size(); ++i) {
            auto nextX = x + directions[i][1];
            auto nextY = y + directions[i][0];
            if (nextX >= 0 && nextX < m &&
                nextY >= 0 && nextY < n &&
                !visited[nextY][nextX]) {
                if (grid[nextY][nextX] == 2) {
                    if (currentEmptySquares == numEmptySquares) {
                        ++result;
                    }
                }
                else if (grid[nextY][nextX] == 0) {
                    ++currentEmptySquares;
                    visited[nextY][nextX] = true;
                    uniquePathsIII(grid, nextX, nextY, numEmptySquares, currentEmptySquares, visited, result);
                    visited[nextY][nextX] = false;
                    --currentEmptySquares;
                }
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        std::vector<int> start;
        int numEmptySquares = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                }
                else if (grid[i][j] == 0) {
                    ++numEmptySquares;
                }
            }
        }
        int result = 0;
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        visited[start[0]][start[1]] = true;
        uniquePathsIII(grid, start[1], start[0], numEmptySquares, 0, visited, result);

        return result;
    }
};

