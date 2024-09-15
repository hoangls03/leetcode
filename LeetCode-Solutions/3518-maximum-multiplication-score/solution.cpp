class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        long long ans;
        long long dp[5];
        for ( int i = 0 ; i < 4 ; ++i ) {
            dp[i] = -1e17;
        }
        for ( int i = 0 ; i < n ; ++i ) {
            dp[3] = max(1LL*dp[2] + 1LL*a[3]*b[i],dp[3]);
            dp[2] = max(1LL*dp[1] + 1LL*a[2]*b[i],dp[2]);
            dp[1] = max(1LL*dp[0] + 1LL*a[1]*b[i],dp[1]);
            dp[0] = max(dp[0],1LL*a[0]*b[i]);
        }
        return dp[3];
    }
};
