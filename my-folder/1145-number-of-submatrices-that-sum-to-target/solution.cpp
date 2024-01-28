#pragma GCC optimize("O3", "Ofast", "unroll-loops")
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vt(m+1,vector<int>(n+1));
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for ( int i = 1 ; i <= m ; ++i ) {
            int s = 0;
            for ( int j = 1 ; j <= n ; ++j ) {
                vt[i][j] = matrix[i-1][j-1];
                s += vt[i][j];
                dp[i][j] = dp[i-1][j] + s;
                //cout<<dp[i][j]<<" ";
            }
           // cout<<'\n';
        }
        int ans = 0;
        for ( int i = 1 ; i <= m ; ++i ) {
            for ( int j = 1 ; j <= n ; ++j ) {
                for ( int k = 1 ; k <= i ; ++k ) {
                    for ( int z = 1 ; z <= j ; ++z ) {
                        if ( dp[i][j] - dp[k-1][j] - dp[i][z-1] + dp[k-1][z-1] == target ) ans++;
                    }
                }
            }
        }
        return ans;
    }
};
