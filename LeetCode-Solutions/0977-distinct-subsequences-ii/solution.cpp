const int oo = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        vector<int> occur('z' + 1, -1);
        for ( int i = 0 ; i < n ; ++i ) {
            dp[i+1] = dp[i] * 2 % oo;
            if ( occur[s[i]] >= 0 ) {
                dp[i+1] = (dp[i+1] - dp[occur[s[i]]] + oo)%oo;
            }
            occur[s[i]] = i;
        }
        dp[n] = (dp[n] - 1 + oo)%oo;
        return dp[n];
    }
};
