class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int N, int K) {
        std::vector<std::vector<std::pair<int, int>>> neighbors(N + 1, std::vector<std::pair<int, int>>{});
        for (auto& time: times) {
            neighbors[time[0]].push_back(std::make_pair(time[1], time[2]));
        }
        std::vector<bool> visited(N + 1, false);
        std::vector<int> dist(N + 1, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
        queue.push(std::make_pair(0, K));
        dist[K] = 0;
        
        while(!queue.empty()) {
            auto node = queue.top().second;
            auto distanceToNode = queue.top().first;
            queue.pop();
            if (distanceToNode > dist[node]) {
                continue;
            }
            visited[node] = true;
            for (auto& neighbor: neighbors[node]) {
                auto neighborNode = neighbor.first;
                auto edgeWeight = neighbor.second;
                if (visited[neighborNode]) {
                    continue;
                }
                if (dist[neighborNode] > dist[node] + edgeWeight) {
                    dist[neighborNode] = dist[node] + edgeWeight;
                    queue.push(std::make_pair(dist[neighborNode], neighborNode));
                }
            }
        }
    
        int time = -1;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == std::numeric_limits<int>::max()) {
                return -1;
            }
            time = std::max(time, dist[i]);
        }
        
        return time;
    }
};