class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        auto comparator = [&](std::pair<int, int> &a, std::pair<int, int> &b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
        decltype(comparator)> minHeap(comparator);
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            minHeap.push(std::make_pair(i, 0));
        }
        int result = matrix[minHeap.top().first][minHeap.top().second];
        for (int i = 1; i <= k; ++i) {
            auto r = minHeap.top().first;
            auto c = minHeap.top().second;
            minHeap.pop();
            result = matrix[r][c];
            if (c < n - 1) {
                minHeap.push(std::make_pair(r, c + 1));
            }
        }
        return result;
    }
};

