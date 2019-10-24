class Solution {
private:
    std::vector<std::vector<int>> mergeSkylines(std::vector<std::vector<int>>& leftSkyline, std::vector<std::vector<int>>& rightSkyline) {
        int lastHeightLeft = 0;
        int lastHeightRight = 0;
        int left = 0;
        int right = 0;
        std::vector<std::vector<int>> mergedSkyline;
        while (left < leftSkyline.size() && right < rightSkyline.size()) {
            if (leftSkyline[left][0] < rightSkyline[right][0]) {
                mergedSkyline.push_back({leftSkyline[left][0], std::max(leftSkyline[left][1], lastHeightRight)});
                lastHeightLeft = leftSkyline[left][1];
                ++left;
            }
            else if (leftSkyline[left][0] > rightSkyline[right][0]) {
                mergedSkyline.push_back({rightSkyline[right][0], std::max(rightSkyline[right][1], lastHeightLeft)});
                lastHeightRight = rightSkyline[right][1];
                ++right;
            }
            else {
                mergedSkyline.push_back({leftSkyline[left][0], std::max(leftSkyline[left][1], rightSkyline[right][1])});
                lastHeightLeft = leftSkyline[left][1];
                lastHeightRight = rightSkyline[right][1];
                ++left;
                ++right;
            }
        }
        while (left < leftSkyline.size()) {
            mergedSkyline.push_back(leftSkyline[left++]);
        }
        while (right < rightSkyline.size()) {
            mergedSkyline.push_back(rightSkyline[right++]);
        }
        // Remove redundant points
        int index = 1;
        while(index < mergedSkyline.size()) {
            if (mergedSkyline[index][1] == mergedSkyline[index - 1][1]) {
                mergedSkyline.erase(mergedSkyline.begin() + index);
            }
            else {
                ++index;
            }
        }
        return mergedSkyline;
    }
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings, int left, int right) {
        if (left == right) {
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
        }
        int middle = (left + right) / 2;
        auto leftSkyline = getSkyline(buildings, left, middle);
        auto rightSkyline = getSkyline(buildings, middle + 1, right);
        return mergeSkylines(leftSkyline, rightSkyline);
    }
public:
    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {
        if (buildings.empty()) {
            return {};
        }
        return getSkyline(buildings, 0, buildings.size() - 1);
    }
};
