class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key, int val): key(key), val(val), prev(NULL), next(NULL) {}
    };

    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void remove(Node* node) {
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        mp.erase(node -> key);
    }

    void add(int key, int val) {
        Node* prevEnd = tail -> prev;
        Node* node = new Node(key,val);
        prevEnd -> next = node;
        node -> prev = prevEnd;
        node -> next = tail;
        tail -> prev = node;
        mp[key] = node;
    }

    int get(int key) {
        if ( mp.find(key) == mp.end() ) {
            return -1;
        }
        int val = mp[key] -> val;
        remove(mp[key]);
        add(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if ( mp.find(key) == mp.end() ) {
            if ( mp.size() == cap ) {
                remove(head -> next);
            }
            add(key,value);
            return ;
        }
        remove(mp[key]);
        add(key,value);
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
