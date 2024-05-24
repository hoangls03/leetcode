class Solution {
public:
    string makeGood(string s) {
        if ( s.size() < 2 ) return s;
        string ans = "";
        bool check = true;
        while ( check ) {
            check = false;
            int n = s.size();
            for ( int i = 0 ; i < n - 1 && !check ; ++i ) {
                if ( i < s.size() - 1 && s[i] == s[i+1] + abs('a' - 'A') || s[i] + abs('a'-'A') == s[i+1] ) {
                    s.erase(i,2);
                    check = true;
                    break;
                }
            }
        }
        return s;
    }
};
