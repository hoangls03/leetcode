const int oo = 1e9 + 7;
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for ( int i = 1 ; i <= n ; ++i ) {
            dp[i][0] = 1;
        }
        for ( int i = 2 ; i <= n ; ++i ) {
            for ( int j = 1 ; j <= k ; ++j ) {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j])%oo;
                if ( j >= i ) dp[i][j] = (dp[i][j] + oo - dp[i-1][j-i])%oo;
            }
        }
        return dp[n][k];
    }
};
