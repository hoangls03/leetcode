class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> l_b(n,0);
        l_b[0] = (s[0] == 'b');
        for ( int i = 1 ; i < n ; ++i ) {
            l_b[i] = l_b[i-1] + ( s[i] == 'b' );
        }
        vector<int> dp(n,0);
        for ( int i = 1 ; i < n ; ++i ) {
            if ( s[i] == 'a' ) {
                dp[i] = min(l_b[i],dp[i-1] + 1);
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};
