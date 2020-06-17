class Solution {
private:
    int calc(std::vector<int>& p1, std::vector<int>& p2) {
        return std::pow(p1[0] - p2[0], 2) + std::pow(p1[1] - p2[1], 2);
    }
public:
    bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4) {
        auto d12 = calc(p1, p2);
        auto d13 = calc(p1, p3);
        auto d14 = calc(p1, p4);

        if (d12 == 0 || d13 == 0 || d14 == 0) {
            return false;
        }

        if (d12 == d13 && d12 + d13 == d14) {
            return calc(p2, p4) == calc(p3, p4);
        }
        if (d12 == d14 && d12 + d14 == d13) {
            return calc(p2, p3) == calc(p3, p4);
        }
        if (d13 == d14 && d13 + d14 == d12) {
            return calc(p2, p3) == calc(p2, p4);
        }

        return false;
    }
};

