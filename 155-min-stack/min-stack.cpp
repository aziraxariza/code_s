class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {}

    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val); // minST mein top par ab tk ka min ele rahega
        }
    }

    void pop() {
        if(st.top() == minSt.top()) {
            minSt.pop(); // dono ka top same hai toh dono se hatao top kyuki hume getMin se by chance alr popped ele nhi chahiye
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
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