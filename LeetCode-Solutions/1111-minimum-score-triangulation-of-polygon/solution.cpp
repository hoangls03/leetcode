class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1,vector<int>(n+1,1e9));
        for ( int i = 2 ; i < n ; ++i ) {
            for ( int j = 0 ; j + i < n ; ++j ) {
                for ( int z = j + 1 ; z < j + i ; ++z ) {
                    int left = 0;
                    int right = 0;
                    if ( z > j + 1 ) {
                        left = dp[j][z];
                    }
                    if ( z < j + i - 1 ) {
                        right = dp[z][j+i];
                    }
                    dp[j][j+i] = min(dp[j][j+i],left + values[j]*values[z]*values[j+i] + right);
                }
            }
        }
        return dp[0][n-1];
    }
};
