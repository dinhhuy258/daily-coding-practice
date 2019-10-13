class MinStack {
private:
    std::stack<int> minStack;

    std::stack<int> dataStack;
public:
    MinStack() {
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        dataStack.push(number);
        if (minStack.empty() || minStack.top() >= number) {
            minStack.push(number);
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        int value = dataStack.top();
        dataStack.pop();
        if (minStack.top() == value) {
            minStack.pop();
        }
        return value;
    }

    /*
     * @return: An integer
     */
    int min() {
        return minStack.top();
    }
};
