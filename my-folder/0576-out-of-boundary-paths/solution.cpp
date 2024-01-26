const int oo = 1e9 + 7;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[startRow][startColumn] = 1;
        int ans = 0;
        for ( int moves = 1 ; moves <= maxMove ; ++moves ) {
            vector<vector<int>> f(m,vector<int>(n,0));
            for ( int i = 0 ; i < m ; ++i ) {
                for ( int j = 0 ; j < n ; ++j ) {
                    if ( i == 0 ) ans = ( ans + dp[i][j] )%oo;
                    if ( j == 0 ) ans = ( ans + dp[i][j] )%oo;
                    if ( i == m - 1 ) ans = ( ans + dp[i][j] )%oo;
                    if ( j == n - 1 ) ans = ( ans + dp[i][j] )%oo; 
                    f[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % oo +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % oo
                    ) % oo;
                }
            }
            dp = f;
        }
        return ans;
    }
};
