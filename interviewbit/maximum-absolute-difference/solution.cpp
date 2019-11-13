int Solution::maxArr(vector<int> &A) {
    if (A.empty()) {
        return 0;
    }
    std::pair<int, int> min1 = std::make_pair(A[0], 0);
    std::pair<int, int> min2 = std::make_pair(A[0], 0);
    int result = 0;
    for (int i = 1; i < A.size(); ++i) {
        result = std::max(result, std::abs(A[i] - min1.first) + std::abs(i - min1.second));
        result = std::max(result, std::abs(A[i] - min2.first) + std::abs(i - min2.second));
        if (A[i] - min1.first > i - min1.second) {
            min1.first = A[i];
            min1.second = i;
        } 
        if (min2.first - A[i] > i - min2.second) {
            min2.first = A[i];
            min2.second = i;
        }
    }
    return result;
}
