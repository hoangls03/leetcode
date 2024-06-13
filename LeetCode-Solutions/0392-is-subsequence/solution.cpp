class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = 0,pos1 = 0;
        while ( pos < s.size() && pos1 < t.size() ) {
            if ( s[pos] != t[pos1] ) {
                pos1++;
            } else {
                pos++;
                pos1++;
            }
        }
        cout<<pos<<'\n';
        if ( pos != s.size() ) return false;
        return true;
    }
};
