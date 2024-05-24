class RandomizedSet {
public:
    vector<int> vt;
    map<int,int> mp;
    RandomizedSet() {
        mp.clear();
        vt.clear();
    }
    
    bool insert(int val) {
        vt.push_back(val);
        bool check = false;
        if ( mp[val] == 0 ) check = true;
        mp[val] = 1;
        return check;
    }
    
    bool remove(int val) {
        if ( mp[val] >= 1 ) {
            for ( int i = 0 ; i < vt.size() ; ++i ) {
                if ( vt[i] == val ) {
                    vt.erase(vt.begin() + i);
                    break;
                }
            }
            mp[val]--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int val = rand()%vt.size();
        return vt[val];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
