class Solution {
private:
    bool isDigit(char element) {
        return element >= '0' && element <= '9';
    }
public:
    int calculate(std::string s) {
        std::stack<char> operatorStack;
        std::stack<int> operandStack;
        bool openParenthesis = false;
        int i = 0;
        while (i < s.size()) {
            char element = s[i++];
            if (element == ' ') {
                continue;
            }
            if (isDigit(element)) {
                int currentValue = element - '0';
                while(i < s.size() && isDigit(s[i])) {
                    currentValue = currentValue * 10 + (s[i] - '0');
                    ++i;
                }
                if (operandStack.empty() || openParenthesis) {
                    operandStack.push(currentValue);
                }
                else {
                    int lastValue = operandStack.top();
                    operandStack.pop();            
                    operandStack.push(operatorStack.top() == '+' ? lastValue + currentValue : lastValue - currentValue);
                    operatorStack.pop();
                }
            }
            else if (element == '+' || element == '-') {
                operatorStack.push(element);
            }
            else if (element == ')' && !operatorStack.empty()) {
                int currentValue = operandStack.top();
                operandStack.pop();
                int lastValue = operandStack.top();
                operandStack.pop();
                operandStack.push(operatorStack.top() == '+' ? lastValue + currentValue : lastValue - currentValue);
                operatorStack.pop();
            }
            openParenthesis = element == '(';
        }
        
        return operandStack.top();
    }
};
