class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // KMP algorithm
        std::vector<int> lsp(n, 0);
        int i = 0, j = 1;
        while (j < n) {
            if (s[i] == s[j]) {
                ++i;
                lsp[j] = i;
                ++j;
            }
            else {
                if (i == 0) {
                    lsp[j] = 0;
                    ++j;
                }
                else {
                    i = lsp[i - 1];
                }
            }
        }
        
        // n - lsp[n - 1] is the length of the repeating string
        return lsp[n - 1] && (lsp[n - 1] % (n - lsp[n - 1]) == 0);
    }
};

