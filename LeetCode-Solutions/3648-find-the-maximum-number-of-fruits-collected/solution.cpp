class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i == j ) ans += fruits[i][j];
            }
        }
        vector<vector<int>> dp(n,vector<int>(n,-1e9));
        dp[n-1][0] = fruits[n-1][0];
        for ( int j = 0 ; j < n - 1 ; ++j ) {
            for ( int i = j + 1 ; i < n ; ++i ) {
                for ( int k = -1 ; k <= 1 ; ++k ) {
                    if ( i + k >= j + 1 && i + k < n ) {
                        dp[i+k][j + 1] = max(dp[i+k][j+1],dp[i][j] + fruits[i + k][j + 1]);
                    }
                }
            }
        }
        dp[0][n-1] = fruits[0][n-1];
        for ( int i = 0 ; i < n - 1; ++i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                for ( int k = -1 ; k <= 1 ; ++k ) {
                    if ( j + k >= i + 1 && j + k < n ) {
                        dp[i + 1][j + k] = max(dp[i + 1][j+k],dp[i][j] + fruits[i + 1][j + k]);
                    }
                }
            }
        }
        ans += dp[n-1][n-2] + dp[n-2][n-1];
        return ans;
    }
};
