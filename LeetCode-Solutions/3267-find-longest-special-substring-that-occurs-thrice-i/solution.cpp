class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string,int> mp;
        int ans = -1;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 1 ; j <= n - i ; ++j ) {
                string t = s.substr(i,j);
                bool check = true;
                for ( int k = 0 ; k < j && check ; ++k ) {
                    if ( t[k] != t[0] ) {
                        check = false;
                    }
                }
                if ( check ) {
                    mp[t]++;
                    if ( mp[t] >= 3 ) {
                        ans = max(ans,j);
                    }
                }
            }
        }
        return ans;
    }
};
