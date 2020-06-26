class Solution {
public:
    int leastBricks(std::vector<std::vector<int>>& wall) {
        std::unordered_map<int, int> map;
        auto result = wall.size();
        for (int i = 0; i < wall.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                ++map[sum];  
                result = std::min(result, wall.size() - map[sum]);
            }
        }
        
        return result;
    }
};

