class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,int> mp;
        int n = s.size();
        int ans = 0;
        for ( int i = k - 1; i < n ; ++i ) {
            string t = s.substr(i - k + 1,k);
            if ( mp[t] == 0 ) {
                ans++;
            }
            mp[t]++;
        }
        return (ans == (1<<k));
    }
};
