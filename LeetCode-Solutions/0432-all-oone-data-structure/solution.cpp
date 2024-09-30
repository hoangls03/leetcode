class AllOne {
public:
    map<string,int> mp;
    map<int,set<string>> count;
    AllOne() {
        
    }
    
    void inc(string key) {
        int temp = mp[key];
        if ( temp ) count[temp].erase(key);
        if ( count[temp].empty() ) count.erase(temp);
        mp[key]++;
        count[temp+1].insert(key);
    }
    
    void dec(string key) {
        int temp = mp[key];
        count[temp].erase(key);
        mp[key]--;
        if ( mp[key] ) {
            count[mp[key]].insert(key);
        }
        if ( count[temp].empty() ) count.erase(temp); 
    }
    
    string getMaxKey() {
        if ( count.empty() ) {
            return "";
        }
        return *(count.rbegin() -> second.begin());
    }
    
    string getMinKey() {
        if ( count.empty() ) {
            return "";
        }
        return *(count.begin() -> second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
