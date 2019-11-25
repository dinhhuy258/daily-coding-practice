class Solution {
private:
    void allPathsSourceTarget(int node, 
                              std::vector<std::vector<int>>& graph, 
                              std::vector<int>& currentPath,
                              std::vector<std::vector<int>>& paths) {
        currentPath.push_back(node);
        if (node == graph.size() - 1) {
            paths.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        for (auto& neighbor: graph[node]) {
            allPathsSourceTarget(neighbor, graph, currentPath, paths);
        }
        currentPath.pop_back();
    }
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<std::vector<int>> paths;
        std::vector<int> currentPath;
        allPathsSourceTarget(0, graph, currentPath, paths);
        return paths;
    }
};
