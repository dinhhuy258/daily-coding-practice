class Solution {
public:
    std::vector<int> numsSameConsecDiff(int N, int K) {
        std::vector<int> result;
        for (int i = N == 1 ? 0 : 1; i <= 9; ++i) {
            std::stack<std::pair<int, std::string>> nodes;
            nodes.push(std::make_pair(i, ""));
            while(!nodes.empty()) {
                auto node = nodes.top().first;
                auto current = nodes.top().second;
                nodes.pop();
                current += std::to_string(node);
                if (current.size() == N) {
                    result.push_back(std::stoi(current));
                    continue;
                }
                if (node + K <= 9) {
                    nodes.push(std::make_pair(node + K, current));
                }
                if (node - K >= 0 && K != 0) {
                    nodes.push(std::make_pair(node - K, current));
                }
            }
        }

        return result;
    }
};

