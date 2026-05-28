class MinStack {
public:
    vector<pair<int, int>> v;
    MinStack() {
        
    }
    
    void push(int val) {
        if(v.empty()) v.push_back({val, val});
        else v.push_back({val, v.back().second > val ? val : v.back().second});

        return;
    }
    
    void pop() {
        v.pop_back();
        return;
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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