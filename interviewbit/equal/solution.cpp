vector<int> Solution::equal(vector<int> &A) {
    std::vector<int> result;
    std::unordered_map<int, std::pair<int, int>> map;
    int size = A.size();
    for (int i = 0;  i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int sum = A[i] + A[j];
            if (map.find(sum) == map.end()) {
                map[sum] = std::make_pair(i, j);
            }
            else {
                auto pair = map[sum];
                if (pair.first != i && pair.first != j && 
                    pair.second != i && pair.second != j) {
                    if (result.empty() || 
                        (pair.first < result[0]) || 
                        (pair.first == result[0] && pair.second < result[1]) || 
                        (pair.first == result[0] && pair.second == result[1] && i < result[2]) || 
                        (pair.first == result[0] && pair.second == result[1] && i == result[2] && j < result[3])) {
                        result = {pair.first, pair.second, i, j};
                    }
                }
            }
        } 
    }
    return result;
}
