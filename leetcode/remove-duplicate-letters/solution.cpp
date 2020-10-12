class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::vector<int> lastIndex('z' - 'a' + 1, -1);
        auto stringSize = s.size();
        for (int i = 0; i < stringSize; ++i) {
            lastIndex[s[i] - 'a'] = i;
        }

        std::stack<int> stack;
        int mask = 0;
        for (int i = 0; i < stringSize; ++i) {
            auto value = s[i] - 'a';
            if (mask & (1 << value)) {
                continue;
            }

            while (!stack.empty() && stack.top() > value && lastIndex[stack.top()] > i) {
                mask ^= (1 << stack.top());
                stack.pop();
            }
            stack.push(value);
            mask |= (1 << value);
        }

        std::string result = "";
        while(!stack.empty()) {
            result.push_back(stack.top() + 'a');
            stack.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

