class Solution {
public:
    int compareVersion(std::string& version1, std::string& version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int i, j, num1, num2;
        i = j = num1 = num2 = 0;
        while (i < len1 || j < len2) {
            if (i < len1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                ++i;
            }
            if (j < len2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                ++j;
            }
            if ((i >= len1 || version1[i] == '.') && (j >= len2 || version2[j] == '.')) {
                if (num1 > num2) {
                    return 1;
                }
                else if (num1 < num2) {
                    return -1;
                }
                num1 = 0;
                num2 = 0;
                ++i;
                ++j;
            }
        }
        return 0;
    }
};