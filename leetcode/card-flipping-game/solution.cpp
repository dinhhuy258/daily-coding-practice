class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        std::array<bool, 2001> map;
        map.fill(false);

        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] == backs[i]) {
                map[fronts[i]] = true;
            }
        }

        int result = std::numeric_limits<int>::max();
        for (int i = 0; i < fronts.size(); ++i) {
            if (fronts[i] != backs[i]) {
                result = !map[fronts[i]] ? std::min(result, fronts[i]) : result;
                result = !map[backs[i]] ? std::min(result, backs[i]) : result;
            }
        }

        return result == std::numeric_limits<int>::max() ? 0 : result;
    }
};

