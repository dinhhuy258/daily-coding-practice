class Solution {
public:
    std::vector<double> calcEquation(std::vector<std::vector<string>>& equations, 
                                     std::vector<double>& values, 
                                     std::vector<std::vector<string>>& queries) {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
        for (auto i = 0; i < equations.size(); ++i) {
            if (graph.find(equations[i][0]) == graph.end()) {
                graph[equations[i][0]] = std::vector<std::pair<std::string, double>>();
            }
            if (graph.find(equations[i][1]) == graph.end()) {
                graph[equations[i][1]] = std::vector<std::pair<std::string, double>>();
            }
            graph[equations[i][0]].push_back(std::make_pair(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(std::make_pair(equations[i][0], 1.0 / values[i]));
        }
        
        std::vector<double> result;
        for (auto i = 0; i < queries.size(); ++i) {
            auto variable1 = queries[i][0];
            auto variable2 = queries[i][1];
            if (graph.find(variable1) == graph.end() ||
                graph.find(variable2) == graph.end()) {
                result.push_back(-1);
            }
            else if (variable1 == variable2) {
                result.push_back(1);
            }
            else {
                // Evaluate division
                std::queue<std::pair<std::string, double>> queue;
                std::unordered_set<std::string> visited;
                queue.push(std::make_pair(variable1, 1));
                visited.insert(variable1);
                result.push_back(-1);
                while(!queue.empty()) {
                    auto node = queue.front();
                    queue.pop();
                    auto &neighbors = graph[node.first];
                    for (auto &neighbor: neighbors) {
                        if (visited.find(neighbor.first) == visited.end()) {
                            // Not visited
                            if (neighbor.first == variable2) {
                                result.pop_back();
                                result.push_back(node.second * neighbor.second);
                                break;
                            }
                            visited.insert(neighbor.first);
                            queue.push(std::make_pair(neighbor.first, node.second * neighbor.second));
                        }
                    }
                }
            }
        }
        
        return result;
    }
};
