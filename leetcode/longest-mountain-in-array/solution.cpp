class Solution {
public:
    int longestMountain(std::vector<int>& A) {
        int size = A.size();
        if (size < 3) {
            return 0;
        }

        int ans = 0;
        int j = 0;
        int steep = 0;
        for (int i = 1; i < size; ++i) {
            if (A[i] == A[i - 1]) {
                j = i;
                steep = 0;
            }
            else if (A[i] > A[i - 1]) {
                if (steep == -1) {
                    j = i - 1;
                }
                steep = 1;
            }
            else {
                if (steep == 0) {
                    j = i;
                }
                else {
                    ans = std::max(i - j + 1, ans);
                    steep = -1;
                }
            }
        }

        return ans;
    }
};

