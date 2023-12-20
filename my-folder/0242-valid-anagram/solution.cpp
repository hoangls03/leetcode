class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if ( n != m ) return false;
        vector<int> vt(30,0);
        for ( int i = 0 ; i < n ; ++i ) {
            vt[s[i]-'a']++;
            vt[t[i]-'a']--;
        }
        for ( int i = 0 ; i < 'z' - 'a' ; ++i ) {
            if ( vt[i] != 0 ) return false;
        }
        return true;
    }
};
