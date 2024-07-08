class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = 1e9;
        int n = grid.size();
        int dp[n][n];
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                dp[i][j] = 1e9;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            int l[n],r[n];
            if ( i != 0  ) {
                l[0] = dp[i-1][0];
                for ( int j = 1 ; j < n ; ++j ) {
                    l[j] = min(l[j-1],dp[i-1][j]);
                }
                r[n-1] = dp[i-1][n-1];
                for ( int j = n - 2 ; j >= 0 ; --j ) {
                    r[j] = min(r[j+1],dp[i-1][j]);
                }
            }
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i == 0 ) {
                    dp[i][j] = grid[i][j];
                } else {
                    if ( j == 0 ) dp[i][j] = r[j+1] + grid[i][j];
                    else if ( j == n - 1 ) dp[i][j] = l[j-1] + grid[i][j];
                    else dp[i][j] = min(l[j-1],r[j+1]) + grid[i][j];
                }
                if ( i == n - 1 ) {
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
