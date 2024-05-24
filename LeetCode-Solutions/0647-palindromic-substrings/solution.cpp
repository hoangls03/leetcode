class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); 
        int ans = n;
        vector<vector<int>> f(n,vector<int>(n,0));
        for ( int i = 0 ; i < n ; ++i ) {
            int l = i - 1 , r = i + 1;
            f[i][i] = 1;
            while ( l >= 0 && r < n && s[l] == s[r] ) {
                if ( f[l][r] == 0 ) {
                    f[l][r] = 1;
                    ans++;
                }
                l--;
                r++;
            }
            if ( i + 1 < n && s[i] == s[i+1] ) {
                if ( f[i][i+1] == 0 ) {
                    f[i][i+1] = 1;
                    ans++;
                }
                l = i - 1;
                r = i + 2;
                while ( l >= 0 && r < n && s[l] == s[r] ) {
                    if ( f[l][r] == 0 ) {
                        f[l][r] = 1;
                        ans++;
                    }
                    l--;
                    r++;
                }
            }
        }
        return ans;
    }
};
