class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        std::vector<int> outDegrees(n, 0);
        std::vector<std::vector<int>> adjacencyList(n, std::vector<int>{});
    
        for (auto& edge: edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
            ++outDegrees[edge[0]];
            ++outDegrees[edge[1]];
        }
        
        int numNodeLeft = n;
        while (numNodeLeft > 2) {
            auto tempOutDegrees = outDegrees;
            for (int i = 0; i < n; ++i) {
                if (tempOutDegrees[i] == 1) {
                    outDegrees[i] = -1;
                    for (auto &node: adjacencyList[i]) {
                        --outDegrees[node];
                    }
                    --numNodeLeft;
                }
            } 
        }
        
        std::vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (outDegrees[i] >= 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};
