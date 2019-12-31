class Solution {
private:
    void findCriticalConnections(int currentNode, 
                                 int parent, 
                                 std::vector<std::vector<int>>& graph, 
                                 std::vector<bool>& visited, 
                                 std::vector<int>& ids, 
                                 std::vector<int>& lowLinks, 
                                 std::vector<std::vector<int>>& result) {
        static int id = 0;
        visited[currentNode] = true;
        lowLinks[currentNode] = ids[currentNode] = id++;
        for (auto& neighbor: graph[currentNode]) {
            if (neighbor == parent) {
                continue;
            }
            if (!visited[neighbor]) {
                findCriticalConnections(neighbor, currentNode, graph, visited, ids, lowLinks, result);
                lowLinks[currentNode] = std::min(lowLinks[currentNode], lowLinks[neighbor]);
                if (ids[currentNode] < lowLinks[neighbor]) {
                    result.push_back({currentNode, neighbor});
                }
            }
            else {
                lowLinks[currentNode] = std::min(lowLinks[currentNode], ids[neighbor]);
            }
        }
    }
public:
    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<int>> graph(n, std::vector<int>{});
        for (auto& connection: connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        std::vector<bool> visited(n, false);
        std::vector<int> ids(n, -1);
        std::vector<int> lowLinks(n, -1);
        std::vector<std::vector<int>> result;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                findCriticalConnections(i, -1, graph, visited, ids, lowLinks, result);
            }
        }
        
        return result;
    }
};
