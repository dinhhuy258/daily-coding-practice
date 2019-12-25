class Solution {
private:
bool colorBorder(std::vector<std::vector<int>>& grid, 
                 std::vector<std::vector<bool>>& visited, 
                 int r, int c, 
                 int color, int targetColor) {
    int n = grid.size();
    int m = grid[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m) {
        return false;
    }
    if (visited[r][c]) {
        return true;
    }
    if (grid[r][c] != color) {
        return false;
    }
    visited[r][c] = true;
    bool res = colorBorder(grid, visited, r + 1, c, color, targetColor);
    res &= colorBorder(grid, visited, r - 1, c, color, targetColor);
    res &= colorBorder(grid, visited, r, c + 1, color, targetColor);
    res &= colorBorder(grid, visited, r, c - 1, color, targetColor);
    if (!res) {
        grid[r][c] = targetColor;
    }
    return true;
}    
public:
    std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>>& grid, int r0, int c0, int color) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        colorBorder(grid, visited, r0, c0, grid[r0][c0], color);   
        return grid;
    }
};
