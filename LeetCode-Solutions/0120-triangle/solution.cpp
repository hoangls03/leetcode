class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,1e9));
        for ( int i = 0 ; i < m ; ++i ) {
            int n = triangle[i].size();
            if ( i == 0 ) {
                dp[i][0] = triangle[i][0];
            }
            if ( i >= m - 1 ) break;
            for ( int j = 0 ; j < n ; ++j ) {
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + triangle[i+1][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + triangle[i+1][j+1]);
            }
        }
        int ans = 1e9;
        for ( int j = 0 ; j < m ; ++j ) {
            ans = min(ans,dp[m-1][j]);
        }
        return ans;
    }
};
