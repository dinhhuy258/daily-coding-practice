class Solution {
public:
    bool checkValidString(std::string s) {
        std::stack<int> stack1;
        std::stack<int> stack2;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    stack1.push(i);
                    break;
                case ')':
                    if (!stack1.empty()) {
                        stack1.pop();
                    }
                    else if (!stack2.empty()) {
                        stack2.pop();
                    }
                    else {
                        return false;
                    }
                    break;
                default:
                    stack2.push(i);
            }
        }
        
        while (!stack1.empty() && !stack2.empty()) {
            if (stack1.top() > stack2.top()) {
                return false;
            }
            stack1.pop();
            stack2.pop();
        }
        
        return stack1.empty();
    }
};