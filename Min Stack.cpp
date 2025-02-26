class MinStack {
    stack<pair<int, int>> ds; 
public:
    MinStack() { 
    }
    
    void push(int val) {
        if(ds.empty()) ds.push({val, val});
        else ds.push({val, min(ds.top().second, val)});
    }
    
    void pop() {
        ds.pop();
    }
    
    int top() {
        return ds.top().first;
    }
    
    int getMin() {
        return ds.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
