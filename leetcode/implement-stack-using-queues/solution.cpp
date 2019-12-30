class MyStack {
public:
    
    std::queue<int> queue1, queue2;
    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue2.push(x);
        while(!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        std::swap(queue1, queue2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {  
        int result = queue1.front();
        queue1.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return queue1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
