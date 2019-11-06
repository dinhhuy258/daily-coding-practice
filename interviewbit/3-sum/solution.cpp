int Solution::threeSumClosest(vector<int> &S, int target) {
    int result = S[0] + S[1] + S[2];
    std::sort(S.begin(), S.end());
    for (int index = 0; index < S.size() - 2; ++index) {
        int i = index + 1;
        int j =  S.size() - 1;
        while(i < j) {
            int sum = S[i] + S[j] + S[index];
            if (std::abs(result - target) > std::abs(sum - target)) {
                result = sum;
            }
            if (sum == target) {
                return target;
            }
            else if (sum > target) {
                --j;
            }
            else {
                ++i;
            }
        }
    }
    return result;
}
