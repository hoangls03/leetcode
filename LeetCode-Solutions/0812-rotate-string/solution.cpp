class Solution {
public:
    bool rotateString(string s, string goal) {
        if ( s.size() != goal.size() ) return false;
        int n = s.size();
        for ( int i = 1 ; i <= s.size() ; ++i ) {
            if ( s.substr(0,i) == goal.substr(n-i) && s.substr(i) == goal.substr(0,n-i) ) {
                return true;
            }
        }
        return false;
    }
};
