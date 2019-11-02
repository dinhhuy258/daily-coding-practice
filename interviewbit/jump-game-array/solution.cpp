int Solution::canJump(vector<int> &A) {
    if (A.size() <= 1) {
        return true;
    }
    int maxJump = A[0];
    for (int i = 1; i < A.size(); ++i) {
        if (maxJump <= i && A[i] == 0) {
            return false;
        }
        maxJump = std::max(maxJump, A[i] + i);
        if (maxJump >= A.size() - 1) {
            return true;
        }
    }
    return false;
}
