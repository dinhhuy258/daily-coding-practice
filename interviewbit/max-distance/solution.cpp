int Solution::maximumGap(const vector<int> &A) {
    int n =  A.size();
    if (n <= 0) {
        return -1;
    }
    std::vector<int> lMin, rMax;
    lMin.reserve(n);
    rMax.reserve(n);
    lMin[0] = A[0];
    for (int i = 1; i < n; ++i) {
        lMin[i] = std::min(A[i], lMin[i - 1]);
    }
    rMax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rMax[i] = std::max(A[i], rMax[i + 1]);
    }
    int maxDistance = -1;
    int i = 0, j = 0;
    while(i < n && j < n) {
        if (lMin[i] <= rMax[j]) {
            maxDistance = std::max(maxDistance, j - i);
            ++j;
        }
        else {
            ++i;
        }
    }
    return maxDistance;
}
