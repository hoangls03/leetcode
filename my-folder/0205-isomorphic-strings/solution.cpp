class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char,char> mp;
        map<char,char> check;
        mp.clear();
        for ( int i = 0 ; i < n ; ++i ) {
            mp[s[i]] = s[i];
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( s[i] != t[i] && mp[s[i]] != t[i] ) {
                mp[s[i]] = t[i];
            } 
            check[t[i]] = s[i];
        }
        for ( int i = 0 ; i < n ; ++i ) {
            cout<<mp[s[i]]<<" "<<t[i]<<'\n';
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( mp[s[i]] != t[i] || check[t[i]] != s[i] ) return false;
        }
        return true;

    }
};
