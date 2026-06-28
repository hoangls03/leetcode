const int oo = 1e9 + 7;
class Solution {
public:
    /*
        0: release/sell stock gain benefit
        1: hold/buy stock lost money
        dp: max value
    */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k + 1,-oo)));
        dp[0][1][1] = -prices[0];
        for ( int i = 0 ; i < n ; ++i ) {
            dp[i][0][0] = 0;
        }
        for ( int i = 1 ; i < n ; ++i ) {
            for ( int j = 1 ; j <= k ; ++j ) {
                dp[i][1][j] = max(dp[i-1][1][j], dp[i-1][0][j-1] - prices[i]);
                dp[i][0][j] = max(dp[i-1][0][j], dp[i-1][1][j] + prices[i]);
            }
        }
        int ans = 0;
        for ( int i = 1 ; i <= k ; ++i ) {
            ans = max(ans,dp[n-1][0][i]);
        }
        return ans;
    }
};
