class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return a[0] < b[0];
        });

        int pointsSize = points.size();
        int minArrowShots = 1;
        auto lastPoint = points[0];
        for (int i = 1; i < pointsSize; ++i) {
            auto point = points[i];
            if (point[0] > lastPoint[1]) {
                ++minArrowShots;
                lastPoint = point;
            }
            else {
                lastPoint[0] = point[0];
                lastPoint[1] = std::min(lastPoint[1], point[1]);
            }
        }
        return minArrowShots;
    }
};

