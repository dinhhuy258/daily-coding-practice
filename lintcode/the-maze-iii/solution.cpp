class Solution {
private:
    std::vector<std::vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::vector<char> directionNames = {'u', 'l', 'd', 'r'};
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
     * @param ball: the ball position
     * @param hole: the hole position
     * @return: the lexicographically smallest way
     */
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole) {
                int n = maze.size();
        int m = maze[0].size();
        std::vector<std::vector<std::pair<int, std::string>>> shortestWays(n, std::vector<std::pair<int, std::string>>(m, std::make_pair(std::numeric_limits<int>::max(), "")));
        std::queue<std::pair<std::vector<int>/* current position */, int/* direction */>> queue;
        for (int i = 0; i < directions.size(); ++i) {
            queue.push(std::make_pair(ball, i));
        }
        shortestWays[ball[0]][ball[1]].first = 0;
        auto shortestWay = std::make_pair(std::numeric_limits<int>::max(), std::string("impossible"));
        while (!queue.empty()) {
            auto position = queue.front().first;
            auto directionIndex = queue.front().second;
            auto direction = directions[directionIndex];
            queue.pop();
            auto x = position[1];
            auto y = position[0];
            auto lastShortestWay= shortestWays[y][x];
            auto distance = 0;
            auto reachHole = false;
            // Go util hit the wall
            while(!hitWall(x + direction[1], y + direction[0], maze)) {
                x += direction[1];
                y += direction[0];
                ++distance;
                if (hole[1] == x && hole[0] == y) {
                    reachHole = true;
                    // Can not go further
                    break;
                }
            }
            if (lastShortestWay.first + distance < shortestWays[y][x].first) {
                if (!reachHole) {
                    for (int i = 0; i < directions.size(); ++i) {
                        if (i != directionIndex) {
                            queue.push(std::make_pair(std::vector<int>{y, x}, i));
                        }
                    }
                }
                shortestWays[y][x].first = lastShortestWay.first + distance;
                shortestWays[y][x].second = lastShortestWay.second + directionNames[directionIndex];
            }
            else if (lastShortestWay.first + distance == shortestWays[y][x].first) {
                auto path = lastShortestWay.second + directionNames[directionIndex];
                shortestWays[y][x].second = shortestWays[y][x].second > path ? path : shortestWays[y][x].second;
            }
            // Update shortestWay
            if (reachHole && shortestWay.first > shortestWays[y][x].first) {
                shortestWay.first = shortestWays[y][x].first;
                shortestWay.second = shortestWays[y][x].second;
            }
            else if (reachHole && shortestWay.first == shortestWays[y][x].first) {
                shortestWay.second = shortestWay.second > shortestWays[y][x].second ? shortestWays[y][x].second : shortestWay.second;
            }
        }
        return shortestWay.second;
    }
};
