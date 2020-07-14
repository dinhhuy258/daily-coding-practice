class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int distance = 0;
        while (temp != 0) {
            if (temp & 1) {
                ++distance;
            }
            temp = temp >> 1;
        }

        return distance;
    }
};

