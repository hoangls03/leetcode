class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1, 0);
        vector<double> sum(n + 1, 0);
        if ( k == 0 ) return 1;
        for ( int i = 1 ; i <= n ; ++i ) {
            int pos = max(i - maxPts - 1,0);
            int r = min(i - 1,k-1);
            if ( pos <= r ) {
                dp[i] = (sum[r] - sum[pos] + (i <= maxPts) )/maxPts;
            }
            sum[i] = sum[i-1] + dp[i];
        }
        double ans = 0;
        for ( int i = k ; i <= n ; ++i ) {
            ans += dp[i];
        }
        return ans;
    }
};
