class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1,vector<vector<int>>(n + 1,vector<int>(k + 1,-1e9)));
        dp[0][0][0] = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                for ( int z = 0 ; z <= k ; ++z ) {
                    if ( z + (grid[i][j] != 0) <= k ) { 
                        int up = (i - 1) >= 0 ? dp[i-1][j][z] : -1e9;
                        int left = (j - 1) >= 0 ? dp[i][j-1][z] : -1e9;
                        if ( up != -1e9 || left != -1e9 ) {
                            dp[i][j][z + (grid[i][j] != 0)] = max(dp[i][j][z + (grid[i][j] != 0)], max(up,left) + grid[i][j]);
                        }
                    }
                }
            }
        }
        int ans = -1e9;
        for ( int z = 0 ; z <= k ; ++z ) {
            ans = max(ans,dp[m-1][n-1][z]);
        }
        if ( ans == -1e9 ) ans = -1;
        return ans;
    }
};
