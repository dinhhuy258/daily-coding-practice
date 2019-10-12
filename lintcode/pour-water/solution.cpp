class Solution {
private:
    /**
     * Find the lowest slot from a non-increasing sequence
     */
    int findLowestSlot(std::vector<int> &heights, int from, bool left) {
        if ((from == 0 && left) || (from == heights.size() - 1 && !left)) {
            return from;
        }
        int i = from;
        int result = from;
        while ((left && i - 1 >= 0 && heights[i - 1] <= heights[i]) ||
               (!left && i + 1 < heights.size() && heights[i + 1] <= heights[i])) {
            if ((!left && heights[i + 1] < heights[i]) ||
                (left && heights[i - 1] < heights[i])) {
                result = left ? (i - 1) : (i + 1);
            }
            i = left ? (i - 1) : (i + 1);
        }
        return heights[result] != heights[from] ? result : from;
    }
public:
    /**
     * @param heights: the height of the terrain
     * @param V: the units of water
     * @param K: the index
     * @return: how much water is at each index
     */
    std::vector<int> pourWater(std::vector<int> &heights, int V, int K) {
        for (int i = 0; i < V; ++i) {
            int lowestSlot = findLowestSlot(heights, K, true);
            if (lowestSlot == K) {
                // Moving left will not make it fall
                lowestSlot = findLowestSlot(heights, K, false);
            }
            ++heights[lowestSlot];
        }
        return heights;
    }
};
