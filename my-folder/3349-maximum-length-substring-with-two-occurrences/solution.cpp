class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        map<char,int> mp;
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            bool check = true;
            mp.clear();
            for ( int j = i ; j < n && check ; ++j ) {
                mp[s[j]]++;
                if ( mp[s[j]] > 2 ) check = false;
                else ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};
