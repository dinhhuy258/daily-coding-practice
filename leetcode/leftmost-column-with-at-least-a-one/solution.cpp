/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        std::vector<int> dimensions = binaryMatrix.dimensions();
        int y = dimensions[0] - 1;
        int x = dimensions[1] - 1;
        int result = -1;
        while (x >= 0 && y >= 0) {
            if (binaryMatrix.get(y, x) == 0) {
                --y;
            }
            else {
                result = x;
                --x;
            }
        }
        
        return result;
    }
};
