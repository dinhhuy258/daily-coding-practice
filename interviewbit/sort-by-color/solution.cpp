void Solution::sortColors(vector<int> &A) {
    int i = 0, j = 0, k = A.size() - 1;
    while(j <= k) {
        switch(A[j]) {
            case 0:
                std::swap(A[j], A[i]);
                ++i;
                ++j;
                break;
            case 1:
                ++j;
                break;
            case 2:
                std::swap(A[j], A[k]);
                --k;
                break;
        }
    }
}
