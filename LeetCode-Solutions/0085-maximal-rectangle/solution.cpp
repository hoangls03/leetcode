class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if ( m == 1 && n == 1 ) return matrix[0][0] == '1';
        vector<int> dp(n+5,0);
        int ans = 0;
        for ( int i = 0 ; i < m ; ++i ) {
            vector<int> vt = {-1};
            for ( int j = 0 ; j <= n ; ++j ) {
                dp[j]= ( j == n || matrix[i][j]=='0') ? 0 : dp[j]+1;
                while ( vt.size() > 1 && ( j == n || dp[j] < dp[vt.back()]) ) {
                    int pos = vt.back();
                    vt.pop_back();
                    int width = j - vt.back() - 1;
                    ans = max(dp[pos]*width,ans);
                }
                vt.push_back(j);
            }
        }
        return ans;
        
    }
};
