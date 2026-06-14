const int oo = 1e9;
class MinStack {
public:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        int minVal;
        Node(int value): val(value), next(NULL), prev(NULL), minVal(oo) {}
    };
    Node* head = new Node(oo);
    Node* tail = new Node(oo);

    MinStack() {
        head -> next = tail;
        tail -> prev = head;
    }
    
    void push(int value) {
        Node* prevTail = tail -> prev;
        Node* node = new Node(value);
        
        prevTail -> next = node;
        node -> prev = prevTail;
        node -> next = tail;
        tail -> prev = node;
        
        if ( prevTail == head ) {
            node -> minVal = node -> val;
        } else {
            node -> minVal = min(value, prevTail -> minVal);
        }
    }
    
    void pop() {
        Node* node = tail -> prev;

        node -> prev -> next = tail;
        tail -> prev = node -> prev;

        return ;
    }
    
    int top() {
        return tail -> prev -> val;
    }
    
    int getMin() {
        return tail -> prev -> minVal;
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
