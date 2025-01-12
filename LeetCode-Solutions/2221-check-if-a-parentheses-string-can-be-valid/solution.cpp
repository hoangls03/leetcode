class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = locked.size();
        if ( n & 1 ) return false;
        stack<int> open,res;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( locked[i] == '1' ) {
                if ( s[i] == '(' ) {
                    open.push(i);
                } else {
                    if ( open.size() ) {
                        open.pop();
                    } else if ( res.size() ){
                        res.pop();
                    } else {
                        return false;
                    }
                }
            } else res.push(i);
        }
        while ( open.size() && res.size() && open.top() < res.top() ) {
            res.pop();
            open.pop();
        }
        if ( open.size() ) return false;
        return true;
    }
};
