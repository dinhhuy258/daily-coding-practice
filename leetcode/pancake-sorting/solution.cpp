class Solution {
private:
    int findMax(std::vector<int>& A, int k) {
        int maxIndex = 0;
        for (int i = 1; i <= k; ++i) {
            if (A[i] > A[maxIndex]) {
                maxIndex = i;
            }
        }

        return maxIndex;
    }
    void flip(std::vector<int>& A, int j) {
        int i = 0;
        while (i < j) {
            std::swap(A[i++], A[j--]);
        }
    }
public:
    std::vector<int> pancakeSort(std::vector<int>& A) {
        std::vector<int> result;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            int maxIndex = findMax(A, n - i - 1);
            if (maxIndex == n - i - 1) {
                continue;
            }

            result.push_back(maxIndex + 1);
            flip(A, maxIndex);
            result.push_back(n - i);
            flip(A, n - i - 1);
        }

        return result;
    }
};

