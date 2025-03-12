class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<long long> dp(2,0);
        int odd = 0, even = 0;
        long long ans = 0;
        for ( auto i : s ) {
            if ( i == '1' ) {
                ans += dp[0];
                dp[1] += even;
            } else {
                ans += dp[1];
                dp[0] += odd;
            }
            odd += ( i == '1' );
            even += ( i == '0' );
        }
        return ans;
    }
};
