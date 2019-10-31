vector<int> Solution::plusOne(vector<int> &A) {
    int memory = 0;
    int i = A.size() - 1;
    do {
        A[i] = A[i] + 1;
        memory = 0;
        if (A[i] == 10) {
            A[i] = 0;
            memory = 1;
        }
        --i;
    }
    while(memory == 1 && i >= 0);
    if (memory == 1) {
        A.insert(A.begin(), 1);
    }
    while(A[0] == 0) {
        A.erase(A.begin());
    }
    return A;
}

