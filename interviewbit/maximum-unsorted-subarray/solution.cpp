vector<int> Solution::subUnsort(vector<int> &A) {
    int size = A.size();
    if (size < 2) {
        return {-1};
    }
    int left = 0;
    while(left < size && A[left] <= A[left + 1]) {
        ++left;
    }
    int right = size - 1;
    while(right > 0 && A[right] >= A[right - 1]) {
        --right;
    }
    if (left >= right) {
        // Sorted array
        return {-1};
    }
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    for (int i = left; i <= right; ++i) {
        min = std::min(min, A[i]);
        max = std::max(max, A[i]);
    }
    while(left > 0 || right < size - 1) {
        if (left > 0 && A[left - 1] > min) {
            --left;
            min = std::min(min, A[left]);
            max = std::max(max, A[left]);
        }
        else if (right < size - 1 && A[right + 1] < max) {
            ++right;
            min = std::min(min, A[right]);
            max = std::max(max, A[right]);
        }
        else {
            break;
        }
    }
    return {left, right};
}
