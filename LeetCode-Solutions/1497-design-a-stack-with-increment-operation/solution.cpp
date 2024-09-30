class CustomStack {
public:
    vector<int> vt;
    int size = 0;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if ( vt.size() < size ) vt.push_back(x);
    }
    
    int pop() {
        if ( vt.size() == 0 ) return -1;
        int temp = vt[vt.size()-1];
        vt.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        int vt_size = vt.size();
        int loop = min(k,vt_size);
        for ( int i = 0 ; i < loop ; ++i ) {
            vt[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
