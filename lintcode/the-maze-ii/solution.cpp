class Solution {
private:
    std::vector<std::vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
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
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int n = maze.size();
        int m = maze[0].size();
        std::vector<std::vector<int>> distances(n, std::vector<int>(m, std::numeric_limits<int>::max()));
        std::queue<std::pair<std::vector<int>/* current position */, int/* direction */>> queue;
        for (int i = 0; i < directions.size(); ++i) {
            queue.push(std::make_pair(start, i));
        }
        distances[start[0]][start[1]] = 0;
        int result = std::numeric_limits<int>::max();
        while (!queue.empty()) {
            auto position = queue.front().first;
            auto directionIndex = queue.front().second;
            auto direction = directions[directionIndex];
            queue.pop();
            int x = position[1];
            int y = position[0];
            int lastDistance = distances[y][x];
            int distance = 0;
            // Go util hit the wall
            while(!hitWall(x + direction[1], y + direction[0], maze)) {
                x += direction[1];
                y += direction[0];
                ++distance;
            }
            if (lastDistance + distance < distances[y][x]) {
                distances[y][x] = lastDistance + distance;
                if (destination[1] == x && destination[0] == y) {
                    result = std::min(result, distances[y][x]);
                    // No need to go further
                    continue;
                }
                for (int i = 0; i < directions.size(); ++i) {
                    if (i != directionIndex) {
                        queue.push(std::make_pair(std::vector<int>{y, x}, i));
                    }
                } 
            }
        }
        return result == std::numeric_limits<int>::max() ? -1 : result;
    }
};
