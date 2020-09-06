class Solution {
private:
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int xShift, int yShift) {
        int count = 0;
        int n = A.size();
        int r = 0;
        for (int y = yShift; y < n; ++y) {
            int c = 0;
            for (int x = xShift; x < n; ++x) {
                if (A[r][c] == B[y][x]) {
                    count += B[y][x];
                }
                ++c;
            }
            ++r;
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int largestOverlap = 0;
        int n = A.size();
        for (int xShift = 0; xShift < n; ++xShift) {
            for (int yShift = 0; yShift < n; ++yShift) {
                largestOverlap = std::max(largestOverlap, countOverlap(A, B, xShift, yShift));
                largestOverlap = std::max(largestOverlap, countOverlap(B, A, xShift, yShift));
            }
        }

        return largestOverlap;
    }
};

