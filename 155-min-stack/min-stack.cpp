class MinStack {
public:
stack<int>st;
stack<int>minn;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        value=min(value,minn.empty()?value:minn.top());
        minn.push(value);
    }
    
    void pop() {
        st.pop();
        minn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */