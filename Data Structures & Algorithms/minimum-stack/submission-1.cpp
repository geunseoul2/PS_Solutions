class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> minstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        val = std::min(val, minstk.empty() ? val : minstk.top());
        minstk.push(val);
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
