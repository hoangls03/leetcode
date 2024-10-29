class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1e9));
        int ans = 0;
        for ( int j = 0 ; j < n ; ++j ) {
            for ( int i = 0 ; i < m ; ++i ) {
                if ( j != 0 ) {
                    if ( i - 1 >= 0 && grid[i-1][j-1] < grid[i][j] ) {
                        dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
                    }
                    if ( grid[i][j-1] < grid[i][j] ) {
                        dp[i][j] = max(dp[i][j],dp[i][j-1] + 1);
                    }
                    if ( i + 1 < m && grid[i+1][j-1] < grid[i][j] ) {
                        dp[i][j] = max(dp[i][j],dp[i+1][j-1] + 1);
                    }
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
