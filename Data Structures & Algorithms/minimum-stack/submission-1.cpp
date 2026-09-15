class MinStack {
private:
    std::stack<int> s{};
    std::stack<int> min_stack{};    
public:
    MinStack() = default;
    
    void push(int val) {
        s.push(val);
        if (!min_stack.empty() && val < min_stack.top()) {
            min_stack.push(val);
        } else {
            if (min_stack.empty()) {
                min_stack.push(val);
            } else {
                min_stack.push(min_stack.top());
            }
        }
    }
    
    void pop() {
       s.pop();
       min_stack.pop(); 
    }
    
    int top() {
       return s.top();
    }
    
    int getMin() {
       return min_stack.top(); 
    }
};
