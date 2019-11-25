class Solution {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        int numberOfNodes = graph.size();
        std::vector<std::vector<int>> paths;
        std::vector<int> currentPath;
        std::queue<std::pair<int, std::vector<int>>> queue;
        queue.push(std::make_pair(0, std::vector<int>{0}));
        while(!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            for (auto& neighbor: graph[node.first]) {
                if (neighbor == numberOfNodes - 1) {
                    std::vector<int> path = node.second;
                    path.push_back(std::move(neighbor));
                    paths.push_back(path);
                }
                else {
                    std::vector<int> path = node.second;
                    path.push_back(neighbor);
                    queue.push(std::make_pair(neighbor, std::move(path)));
                }
            }
        }
        return paths;
    }
};
