class Solution {
private:
    bool isPalindrome(const std::string &s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
    void partition(std::string s, int index, std::vector<std::string> current, std::vector<std::vector<std::string>> &ans) {
        if (index == s.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            auto subString = s.substr(index, i - index + 1);
            if (isPalindrome(subString)) {
                current.push_back(subString);
                partition(s, i + 1, current, ans);
                current.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        partition(s, 0, {}, ans);

        return ans;
    }
};
