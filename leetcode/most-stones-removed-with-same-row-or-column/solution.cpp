class Solution {
private:
    int removeStonesInternal(int currentIndex, std::vector<std::vector<int>>& stones, std::vector<bool>& visited) {
        int res = 0;
        
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i] && (stones[i][0] == stones[currentIndex][0] || stones[i][1] == stones[currentIndex][1])) {
                visited[i] = true;
                res += 1 + removeStonesInternal(i, stones, visited);
            }
        }
        
        return res;
    }   
public:
    int removeStones(std::vector<std::vector<int>>& stones) {
        std::vector<bool> visited(stones.size(), false);
        int largestNumberOfMoves = 0;
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                largestNumberOfMoves += removeStonesInternal(i, stones, visited);
            }
        }
        
        return largestNumberOfMoves;
    }
};
