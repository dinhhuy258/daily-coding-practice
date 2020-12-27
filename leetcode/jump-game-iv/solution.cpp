class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        std::unordered_map<int, std::vector<int>> map;
        for (int i = 0; i < n; ++i) {
            map[arr[i]].push_back(i);
        }

        std::queue<std::pair<int, int>> queue;
        std::vector<bool> visited(n, false);
        visited[0] = true;
        queue.push(std::make_pair(0, 0));
        while (!queue.empty()) {
            auto node = queue.front().first;
            auto steps = queue.front().second;
            queue.pop();
            if (node == n - 1) {
                return steps;
            }
            if (node - 1 >= 0 && !visited[node - 1]) {
                visited[node - 1] = true;
                queue.push(std::make_pair(node - 1, steps + 1));
            }
            if (node + 1 >= 0 && !visited[node + 1]) {
                visited[node + 1] = true;
                queue.push(std::make_pair(node + 1, steps + 1));
            }
            for (int i = 0; i < map[arr[node]].size(); ++i) {
                if (!visited[map[arr[node]][i]]) {
                    visited[map[arr[node]][i]] = true;
                    queue.push(std::make_pair(map[arr[node]][i], steps + 1));
                }
            }
            // No need to check again anymore
            map[arr[node]].clear();
        }

        // Not reachable
        return -1;
    }
};

