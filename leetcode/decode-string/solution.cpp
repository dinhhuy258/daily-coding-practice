class Solution {
private:
    std::string repeat(std::string& s, int times) {
        std::string result;
        result.reserve(s.length() * times);
        for (int i = 0; i < times; ++i) {
            result += s;
        }
        return result;
    }
public:
    std::string decodeString(std::string s) {
        std::stack<std::pair<int, std::string>> stack;
        std::string decodedString = "";
        int repeatTimes = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                repeatTimes = repeatTimes * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                stack.push(std::make_pair(repeatTimes, decodedString));
                decodedString = "";
                repeatTimes = 0;
            }
            else if (s[i] == ']') {
                decodedString = stack.top().second + repeat(decodedString, stack.top().first);
                stack.pop();
            }
            else {
                decodedString += s[i];
            }
        }
        return decodedString;
    }
};
