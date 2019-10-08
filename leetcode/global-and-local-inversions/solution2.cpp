class Solution {
public:
    bool isIdealPermutation(std::vector<int>& A) {
        int currentMax = -1;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (currentMax > A[i + 1]) {
                // local inversion is also global inversion
                return false;
            }
            currentMax = std::max(currentMax, A[i]);
        }
        return true;
    }
};
