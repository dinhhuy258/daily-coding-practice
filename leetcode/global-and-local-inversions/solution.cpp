class FenwickTree {
private:
    std::vector<int> nodes;
public:
    FenwickTree(int n) {
        nodes.resize(n);
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += nodes[i];
        }
        return sum;
    }
    void update(int i, int delta) {
        for (; i < nodes.size(); i += i & -i) {
            nodes[i] += delta;
        }
    }
};

class Solution {
private:
    int getNumberOfLocalInversions(std::vector<int>& A) {
        int numberOfLocalInversions = 0;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i + 1]) {
                ++numberOfLocalInversions;
            }
        }
        return numberOfLocalInversions;
    }
    int getNumberOfGlobalInversions(std::vector<int>& A) {
        int numberOfGlobalInversions = 0;
        FenwickTree fenwickTree(A.size() + 1);
        for (int i = A.size() - 1; i >= 0; --i) {
            numberOfGlobalInversions += fenwickTree.query(A[i]);
            fenwickTree.update(A[i] + 1, 1);
        }
        return numberOfGlobalInversions;
    }
public:
    bool isIdealPermutation(std::vector<int>& A) {
        return getNumberOfGlobalInversions(A) == getNumberOfLocalInversions(A);
    }
};
