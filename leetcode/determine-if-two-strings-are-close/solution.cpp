class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        std::vector<int> map1(26, 0);
        std::vector<int> map2(26, 0);
        for (int i = 0; i < word1.size(); ++i) {
            ++map1[word1[i] - 'a'];
        }
        for (int i = 0; i < word1.size(); ++i) {
            ++map2[word2[i] - 'a'];
            if (map1[word2[i] - 'a'] == 0) {
                return false;
            }
        }

        std::sort(map1.begin(), map1.end());
        std::sort(map2.begin(), map2.end());
        for (int i = 0; i < 26; ++i) {
            if (map1[i] != map2[i]) {
                return false;
            }
        }

        return true;
    }
};

