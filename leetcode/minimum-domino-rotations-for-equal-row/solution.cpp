class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        std::vector<int> countA(7, 0);
        std::vector<int> countB(7, 0);
        int size = A.size();
        int haftSize = size / 2;
        haftSize = size % 2 == 0 ? haftSize : haftSize + 1;
        int mostValueA = 0;
        int mostValueB = 0;

        for (int i = 0; i < size; ++i) {
            ++countA[A[i]];
            if (countA[A[i]] >= haftSize) {
                mostValueA = A[i];
            }

            ++countB[B[i]];
            if (countB[B[i]] > haftSize) {
                mostValueB = B[i];
            }
        }

        bool flagA = true;
        bool flagB = true;
        for (int i = 0; i < size; ++i) {
            if (A[i] != mostValueA && B[i] != mostValueA) {
                flagA = false;
            }
            if (B[i] != mostValueB && A[i] != mostValueB) {
                flagB = false;
            }
        }

        int result = -1;
        if (flagA) {
            result = size - countA[mostValueA];
        }
        if (flagB) {
            result = result == - 1 ? size - countB[mostValueB] : std::min(size - countB[mostValueB], result);
        }

        return result;
    }
};

