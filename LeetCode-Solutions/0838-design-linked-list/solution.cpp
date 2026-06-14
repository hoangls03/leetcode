class MyLinkedList {
public:
    struct Node {
      int val;
      Node* prev;
      Node* next;
      Node(int value): val(value), prev(NULL), next(NULL) {}  
    };

    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    int listSize = 0;
    MyLinkedList() {
        listSize = 0;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int index) {
        if ( index >= listSize || index < 0 ) {
            // cout<<index<<" "<<listSize<<'\n';
            return -1;
        }
        // cout<<"HERe "<<index<<" "<<listSize<<'\n';
        Node* node = head -> next;
        int curIndex = 0;
        while ( curIndex < index ) {
            // cout<<node->val<<'\n';
            node = node -> next;
            curIndex++;
        }
        return node -> val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
        node -> prev = head;
        listSize++;

        // cout<<"HEAD check "<<tail->prev->val<<" "<<head->next->val<<'\n';
        return ;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        node -> prev = tail -> prev;
        node -> next = tail;
        tail -> prev -> next = node;
        tail -> prev = node;
        listSize++;
        // cout<<"TAIL check "<<tail->prev->val<<" "<<node->prev->val<<'\n';
        return ;
    }
    
    void addAtIndex(int index, int val) {
        if ( index > listSize ) {
            return ;
        }
        int curIndex = 0;
        Node* node = head;
        while ( curIndex < index ) {
            node = node->next;
            curIndex++;
        }
        Node* cur = new Node(val);
        // cout<<"Add here "<<node->val<<" "<<tail->prev->val<<" "<<head->next->val<<" "<<node->next->val<<'\n';
        node -> next -> prev = cur;
        cur -> next = node -> next;
        node -> next = cur;
        cur -> prev = node;

        // cout<<"next is "<< cur -> next -> val<<'\n';
        listSize++;
    }
    
    void deleteAtIndex(int index) {
        if ( index < 0 || index >= listSize ) {
            return ;
        }

        Node* node = head -> next;
        int curIndex = 0;
        while ( curIndex < index ) {
            node = node -> next;
            curIndex++;
        }
        // cout<<"Check " << tail -> prev -> val<<'\n';
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;

        // cout<<"Check " << tail -> prev -> val<<'\n';
        listSize--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
