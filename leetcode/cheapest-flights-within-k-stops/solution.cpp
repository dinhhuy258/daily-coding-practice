class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int K) {
        std::vector<std::vector<std::pair<int, int>>> neighbors(n, std::vector<std::pair<int, int>>{});
        for (auto& flight: flights) {
            neighbors[flight[0]].push_back(std::make_pair(flight[1], flight[2]));
        }
        
        std::vector<bool> visited(n, false);
        std::priority_queue<std::tuple<int /* distance */, int /* number of stops */, int /* node */>, std::vector<std::tuple<int, int, int>>, std::greater<std::tuple<int, int, int>>> queue;
        queue.push(std::make_tuple(0, 0, src));
        visited[src] = true;
        
        while(!queue.empty()) {
            int distance, numOfStops, node;
            std::tie(distance, numOfStops, node) = queue.top();
            queue.pop();
            visited[node] = true;
            if (node == dst) {
                return distance;
            }
            
            for (auto& neighbor: neighbors[node]) {
                auto neighborNode = neighbor.first;
                auto edgeWeight = neighbor.second;
                if (visited[neighborNode] || (numOfStops == K && neighborNode != dst)) {
                    // We cannot go further
                    continue;
                }
                
                queue.push(std::make_tuple(distance + edgeWeight, numOfStops + 1, neighborNode));
            }
        }
        return -1;
    }
};
