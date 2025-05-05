const int oo = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(max(n,3) + 1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for ( int i = 3 ; i <= n ; ++i ) {
            dp[i] = (2*dp[i-1] + dp[i-3])%oo;
        }
        return dp[n];
    }
};
