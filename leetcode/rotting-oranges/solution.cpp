#define FRESH 1
#define ROTTEN 2
#define NEW_ROTTEN 3

class Solution {
private:
    std::vector<std::vector<int>> DIRECTIONS = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    std::vector<std::pair<int, int>> infectFreshOranges(std::vector<std::vector<int>>& grid,
                                                        std::vector<std::pair<int, int>>& rottenOranges) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::pair<int, int>> newRottenOranges;

        for (auto& rottenOrange: rottenOranges) {
            auto x = rottenOrange.first;
            auto y = rottenOrange.second;
            for (int i = 0; i < DIRECTIONS.size(); ++i) {
                auto nextX = x + DIRECTIONS[i][1];
                auto nextY = y + DIRECTIONS[i][0];
                if (nextX >= 0 && nextX < m &&
                    nextY >= 0 && nextY < n &&
                    grid[nextY][nextX] == FRESH) {
                    // Avoid adding the same cell into newRottenOranges array
                    grid[nextY][nextX] = NEW_ROTTEN;
                    newRottenOranges.push_back(std::make_pair(nextX, nextY));
                }
            }
        }

        return newRottenOranges;
    }
    std::vector<std::pair<int, int>> getRottenOranges(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::pair<int, int>> rottenOranges;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                if (grid[y][x] == ROTTEN) {
                    rottenOranges.push_back(std::make_pair(x, y));
                }
            }
        }

        return rottenOranges;
    }
    bool hasFreshOrange(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::pair<int, int>> rottenOranges;
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                if (grid[y][x] == FRESH) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::pair<int, int>> rottenOranges = getRottenOranges(grid);

        int minutes = -1;
        while (!rottenOranges.empty()) {
            ++minutes;
            rottenOranges = infectFreshOranges(grid, rottenOranges);
        }

        return hasFreshOrange(grid) ? -1 : std::max(minutes, 0);
    }
};

