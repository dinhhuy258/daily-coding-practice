int Solution::maxp3(vector<int> &A) {
    if (A.size() < 3) {
        return std::numeric_limits<int>::min();
    }
    int result = std::numeric_limits<int>::min();
    int min1, min2;
    int max1, max2, max3;
    min1 = min2 = std::numeric_limits<int>::max();
    max1 = max2 = max3 = std::numeric_limits<int>::min();
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] <= min1) {
            min2 = min1;
            min1 = A[i];
        }
        else if (A[i] <= min2) {
            min2 = A[i];
        }
        if (A[i] >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = A[i];
        }
        else if (A[i] >= max2) {
            max3 = max2;
            max2 = A[i];
        }
        else if (A[i] >= max3) {
            max3 = A[i];
        }
    }
    return std::max(max1 * max2 * max3, min1 * min2 * max1);
}
