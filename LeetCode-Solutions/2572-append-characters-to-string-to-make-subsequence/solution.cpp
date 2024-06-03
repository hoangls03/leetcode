class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size();
        int n = t.size();
        int pos = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            if ( pos < m && s[i] == t[pos] ) {
                pos++;
            }
        }
        return n-pos;
    }
};
