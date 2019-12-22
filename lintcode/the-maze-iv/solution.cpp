#define START 'S'
#define END 'T'
#define WALL '#'

class Solution {
private:
    std::vector<std::vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int theMazeIV(std::vector<vector<char>> &maps) {
        auto n = maps.size();
        auto m = maps[0].size();
        std::queue<std::pair<int, int>> queue;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (maps[i][j] == START) {
                    queue.push(std::make_pair(i, j));
                    goto startAlgorithm;
                }
            }
        }
    startAlgorithm: 
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        visited[queue.front().first][queue.front().second] = true;
        auto minutes = 0;
        auto nodesLeft = 1;
        while (!queue.empty()) {
            auto x = queue.front().second;
            auto y = queue.front().first;
            queue.pop();
            for (int i = 0; i < directions.size(); ++i) {
                auto nextX = x + directions[i][1];
                auto nextY = y + directions[i][0];
                if (nextX >= 0 && nextX < m && 
                    nextY >= 0 && nextY < n && 
                    !visited[nextY][nextX] && maps[nextY][nextX] != WALL) {
                    if (maps[nextY][nextX] == END) {
                        ++minutes;
                        return minutes;
                    }
                    visited[nextY][nextX] = true;
                    queue.push(std::make_pair(nextY, nextX));
                }
            }
            --nodesLeft;
            if (!nodesLeft) {
                ++minutes;
                nodesLeft = queue.size();
            }
        }
        
        // The end point can not be reached
        return -1;
    }
};
