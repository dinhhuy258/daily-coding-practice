vector<int> Solution::maxone(vector<int> &A, int M) {
    if (A.empty()) {
        return {};
    }
    std::queue<int> queue;
    int count = 0;
    int startIndex = 0;
    int i = 0;
    std::pair<int, int> indicesPair = std::make_pair(0, 0);
    while(i < A.size()) {
        if (A[i] == 0) {
            ++count;
            if (count > M) {
                if (M == 0) {
                    startIndex = i + 1;
                }
                else {
                    startIndex = queue.front() + 1;
                    queue.pop();
                    queue.push(i);
                }
                --count;
            }
            else {
                queue.push(i);
            }
        }
        if (indicesPair.second - indicesPair.first < i - startIndex) {
            indicesPair.first = startIndex;
            indicesPair.second = i;
        }
        ++i;
    }
    std::vector<int> result;
    result.reserve(indicesPair.second - indicesPair.first + 1);
    for (i = indicesPair.first; i <= indicesPair.second; ++i) {
        result.push_back(i);
    }
    return result;
}
