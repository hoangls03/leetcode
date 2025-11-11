class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int lenS = strs.size();
        vector<vector<int>> dp(m + 2,vector<int>(n+2,0));
        for ( int i = 0 ; i < lenS ; ++i ) {
            int num0 = 0, num1 = 0;
            for ( char ch : strs[i] ) {
                num0 += (ch == '0');
                num1 += (ch == '1');
            }
            for ( int j = m ; j >= 0 ; --j ) {
                for ( int z = n ; z >= 0 ; --z ) {
                    if ( j + num0 <= m && z + num1 <= n ) {
                        dp[j + num0][z + num1] = max(dp[j+num0][z+num1],dp[j][z] + 1);
                    }
                }
            }
        }
        int ans = 0;
        for ( int i = 0 ; i <= m ; ++i ) {
            for ( int j = 0 ; j <= n ; ++j ) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
