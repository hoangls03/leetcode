class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector< vector<int> > dp(n+1,vector<int>(n+1,1e7));
        int ans = 1e7;
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i == 0 ) {
                    dp[i][j] = matrix[i][j];
                }
                else {
                    for ( int k = 0 ; k < n ; ++k ) {
                        if ( j != k ) {
                            dp[i][j] = min(dp[i][j],dp[i-1][k]+ matrix[i][j]);
                        }
                    }
                }
                if ( i == n - 1 ) {
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
