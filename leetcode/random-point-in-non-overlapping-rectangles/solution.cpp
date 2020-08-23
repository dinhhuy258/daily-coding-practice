class Solution {
private:
    int totalPoints = 0;
    std::vector<int> totalPointsCum;
    std::vector<std::vector<int>> rects;

public:
    Solution(std::vector<std::vector<int>>& rects) {
        this->rects = std::move(rects);

        for (auto& rect: this->rects) {
            int w = rect[2] - rect[0] + 1;
            int h = rect[3] - rect[1] + 1;
            totalPoints += w * h;
            totalPointsCum.push_back(totalPoints);
        }
    }

    std::vector<int> pick() {
        auto point = (rand() % totalPoints); // random number between 1 and totalPoints
        int l = 0;
        int r = rects.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (point >= totalPointsCum[m]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        int rectIndex = l;
        auto rect = rects[rectIndex];
        int w = rect[2] - rect[0] + 1;
        int h = rect[3] - rect[1] + 1;
        int offset = point - (totalPointsCum[rectIndex] - w * h);

        return {rect[0] + offset % w, rect[1] + offset / w};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
