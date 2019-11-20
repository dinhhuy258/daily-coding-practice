int Solution::braces(string A) {
    std::stack<char> stack;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] == ' ') {
            continue;
        }
        else if (A[i] == ')') {
            bool hasOperator = false;
            while(true) {
                char value = stack.top();
                stack.pop();
                if (value == '+' || value == '-' || value == '*' || value == '/') {
                    hasOperator = true;
                }
                else if (value == '(') {
                    break;
                }
            }
            if (!hasOperator) {
                return true;
            }
        }
        else {
            stack.push(A[i]);
        }
    }
    return false;
}
