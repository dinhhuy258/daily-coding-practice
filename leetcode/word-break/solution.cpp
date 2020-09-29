class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> dp(s.size() + 1, false);
        std::unordered_set<std::string> dictionary;
        for (auto& word: wordDict) {
            dictionary.insert(word);
        }
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dictionary.find(s.substr(j, i - j)) != dictionary.end()) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};

