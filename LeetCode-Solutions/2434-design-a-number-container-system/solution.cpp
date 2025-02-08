class NumberContainers {
public:
    unordered_map<int,int> mp;
    unordered_map<int,set<int>> mark;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = mp.find(index);
        if ( it != end(mp) ) {
            mark[it->second].erase(index);
        }
        mp[index] = number;
        mark[number].insert(index);
    }
    
    int find(int number) {
        auto it = mark.find(number);
        if ( it == end(mark) || it->second.empty() ) return -1;
        return *begin(it->second);
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
