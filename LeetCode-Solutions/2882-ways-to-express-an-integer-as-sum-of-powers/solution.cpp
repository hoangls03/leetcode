const int oo = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            long long tmp = 1;
            for ( int j = 1 ; j <= x ; ++j ) {
                tmp = tmp*i;
            }
            for ( long long j = n ; j >= 1 ; --j ) {
                if ( j >= tmp ) {
                    dp[j] = (1LL*dp[j] + dp[j - tmp])%oo;
                }
            }
        }
        return dp[n];
    }
};
