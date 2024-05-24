class MyQueue {
public:
    stack<int> st,st1;
    MyQueue() {
    
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while ( st.size() ) {
            st1.push(st.top());
            st.pop();
        }
        int x = st1.top();
        st1.pop();
        while ( st1.size() ) {
            st.push(st1.top());
            st1.pop();
        }
        return x;
    }
    
    int peek() {
        while ( st.size() ) {
            st1.push(st.top());
            st.pop();
        }
        int x = st1.top();
        while ( st1.size() ) {
            st.push(st1.top());
            st1.pop();
        }
        return x;
    }
    
    bool empty() {
        if ( st.empty() ) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
