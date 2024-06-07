class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        mainStack.push(val);
        if (val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

    