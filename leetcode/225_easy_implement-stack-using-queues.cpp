class MyStack {
    queue<int> stack_q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack_q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val;
        for(int i=0; i<stack_q.size()-1; i++){
            val = stack_q.front();
            stack_q.pop();
            stack_q.push(val);
        }
        val = stack_q.front();
        stack_q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        int val;
        for(int i=0; i<stack_q.size(); i++){
            val = stack_q.front();
            stack_q.pop();
            stack_q.push(val);
        }
        return val;        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return stack_q.empty();
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