class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> stonesQueue;
        for (auto stone: stones) {
            stonesQueue.push(stone);
        }
        
        while(stonesQueue.size() > 1) {
            int heaviestStone = stonesQueue.top();
            stonesQueue.pop();
            int secondHeaviestStone = stonesQueue.top();
            stonesQueue.pop();
            
            if (heaviestStone != secondHeaviestStone) {
                stonesQueue.push(heaviestStone - secondHeaviestStone);
            }
        }
        
        return stonesQueue.empty() ? 0 : stonesQueue.top();
    }
};
