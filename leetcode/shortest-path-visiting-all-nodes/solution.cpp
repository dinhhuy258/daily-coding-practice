class Solution {
public:
    int shortestPathLength(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        std::queue<std::pair<int, int>> queue;
        std::vector<std::vector<int>> distances(n, std::vector<int>(1 << n, std::numeric_limits<int>::max()));
        for (int i = 0; i < n; ++i) {
            queue.push(std::make_pair(i, 1 << i));
            distances[i][1 << i] = 0;
        }
        
        while(!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            auto distance = distances[node.first][node.second];
            if (node.second == (1 << n) - 1) {
                // Visit all nodes
                return distance;
            }
            for (int i = 0; i < graph[node.first].size(); ++i) {
                int neighbor = graph[node.first][i];
                if (distance + 1 < distances[neighbor][node.second | (1 << neighbor)]) {
                    queue.push(std::make_pair(neighbor, node.second | (1 << neighbor)));
                    distances[neighbor][node.second | (1 << neighbor)] = distance + 1;
                }
            }
        }
        return 0;
    }
};
