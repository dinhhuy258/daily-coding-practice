int Solution::lengthOfLongestSubstring(string A) {
    std::array<int, 128> map;
    std::fill(map.begin(), map.end(), -1);
    int i = 0;
    int j = 0;
    int longestSubstring = 0;
    while(i < A.size()) {
        if (map[A[i]] != -1) {
            j = std::max(j, map[A[i]] + 1);
        }
        map[A[i]] = i;
        longestSubstring = std::max(longestSubstring, i - j + 1);
        ++i;
    }
    return longestSubstring;
}
