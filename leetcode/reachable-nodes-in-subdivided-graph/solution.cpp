class Solution {
public:
    int reachableNodes(std::vector<std::vector<int>>& edges, int M, int N) {
        std::vector<std::vector<std::pair<int, int>>> neighbors(N, std::vector<std::pair<int, int>>{});
        for (auto& edge: edges) {
            neighbors[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
            neighbors[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
        }
        
        std::priority_queue<std::pair<int, int>> queue;
        std::vector<bool> visited(N, false);
        std::vector<std::vector<int>> visitedEdges(N, std::vector<int>(N, 0));
        queue.push(std::make_pair(M, 0));
        int numReachableNodes = 0;
        while (!queue.empty()) {
            auto node = queue.top().second;
            auto stepLeft = queue.top().first;
            queue.pop();
            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            ++numReachableNodes;
            
            for (auto& neighbor: neighbors[node]) {
                auto neighborNode = neighbor.first;
                auto numNodes = neighbor.second;
               
                auto numVistedNode = std::min(stepLeft, numNodes - visitedEdges[neighborNode][node]) ;
                numReachableNodes += std::max(numVistedNode - visitedEdges[node][neighborNode], 0);
                visitedEdges[node][neighborNode] = std::max(visitedEdges[node][neighborNode], numVistedNode);
                
                if (!visited[neighborNode] && stepLeft - (numNodes + 1) >= 0) {
                    queue.push(std::make_pair(stepLeft - (numNodes + 1), neighborNode));
                }
            }
        }
        return numReachableNodes;
    }
};
