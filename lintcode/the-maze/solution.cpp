namespace {
    std::vector<std::vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
}

class Solution {
private:
    /**
     * @param x: x position
     * @param y: y position
     * @param maze: the maze
     * @return: whether the ball hit the wall
     */
    bool hitWall(int x, int y, std::vector<std::vector<int>> &maze) {
       return x < 0 || x >= maze[0].size() || y < 0 || y >= maze.size() || maze[y][x] == 1; 
    }
    
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(std::vector<std::vector<int>> &maze, std::vector<int> &start, std::vector<int> &destination) {
        int n = maze.size();
        int m = maze[0].size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::queue<std::pair<std::vector<int>/* current position */, int/* direction */>> queue;
        for (int i = 0; i < directions.size(); ++i) {
            queue.push(std::make_pair(start, i));
        }
        visited[start[0]][start[1]] = true;
        while (!queue.empty()) {
            auto position = queue.front().first;
            auto directionIndex = queue.front().second;
            auto direction = directions[directionIndex];
            queue.pop();
            int x = position[1];
            int y = position[0];
            // Go util hit the wall
            while(!hitWall(x + direction[1], y + direction[0], maze)) {
                x += direction[1];
                y += direction[0];
            }
            if (destination[1] == x && destination[0] == y) {
                return true;
            }
            if (!visited[y][x]) {
                visited[y][x] = true;
                for (int i = 0; i < directions.size(); ++i) {
                    if (i != directionIndex) {
                        queue.push(std::make_pair(std::vector<int>{y, x}, i));
                    }
                }    
            }
        }
        return false;
    }
};
