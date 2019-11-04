vector<int> Solution::wave(vector<int> &A) {
    std::sort(A.begin(), A.end());
    int i = 1;
    while(i < A.size()) {
        std::swap(A[i], A[i - 1]);
        i += 2;
    }
    return A;
}
