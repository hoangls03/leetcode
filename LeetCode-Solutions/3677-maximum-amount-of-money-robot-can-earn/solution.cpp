const int oo = 1e9 + 5;
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(5,-oo)));
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i == 0 && j == 0 ) {
                    dp[i][j][0] = coins[i][j];
                    dp[i][j][1] = 0;
                } else {
                    for ( int k = 0 ; k <= 2 ; ++k ) {
                        int left = (j == 0) ? -oo : dp[i][j-1][k];
                        int up = (i == 0) ? -oo : dp[i-1][j][k];
                        
                        dp[i][j][k] = max({dp[i][j][k],left + coins[i][j],up + coins[i][j]});

                        left = (j == 0 || k == 0) ? -oo : dp[i][j-1][k-1];
                        up = ( i == 0 || k == 0 ) ? -oo : dp[i - 1][j][k - 1];

                        dp[i][j][k] = max({dp[i][j][k],left,up});
                    }
                }
                for ( int k = 0 ; k <= 2 ; ++k ) {

                }
            }
        }
        return max({dp[m - 1][n - 1][0],dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};
