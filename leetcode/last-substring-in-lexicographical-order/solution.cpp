class Solution {
public:
    std::string lastSubstring(std::string s) {
        int stringLength = s.size();
        int i = 0;
        int j = 1;
        int k = 0;
        while (j + k < stringLength) {
            while (j + k < stringLength && s[i + k] == s[j + k]) {
                ++k;
            }
            if (s[i + k] > s[j + k]) {
                j = j + k + 1;
                k = 0;
            }
            else {
                i = j;
                ++j;
                k = 0;
            }
        }

        return s.substr(i);
    }
};

