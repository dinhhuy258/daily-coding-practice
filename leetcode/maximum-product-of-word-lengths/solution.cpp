class Solution {
public:
    int maxProduct(vector<string>& words) {
        int wordsSize = words.size();
        std::vector<int> wordBits(wordsSize, 0);
        for (int i = 0; i < wordsSize; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                wordBits[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        int ans = 0;
        for (int i = 0; i < wordsSize - 1; ++i) {
            for (int j = i + 1; j < wordsSize; ++j) {
                if (!(wordBits[i] & wordBits[j])) {
                    ans = std::max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;
    }
};

