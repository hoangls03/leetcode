class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalin(n,vector<bool>(n,false));
        for ( int i = 0 ; i < n ; ++i ) {
            isPalin[i][i] = true;
        }
        for ( int len = 1 ; len < n ; ++len ) {
            for ( int i = 0 ; i + len < n ; ++i ) {
                if ( s[i] == s[i+len] && (len <= 1 || isPalin[i+1][i+len-1]) ) {
                    isPalin[i][i+len] = true;
                }
            }
        }
        vector<int> dp(n + 1,0);
        for ( int i = 1 ; i <= n ; ++i ) {
            for ( int j = 1 ; j <= i ; ++j ) {
                if ( isPalin[j-1][i-1] && i - j + 1 >= k ) {
                    dp[i] = max(dp[i],dp[j-1] + 1);
                }
                dp[i] = max(dp[i],dp[j]);
            }
        }
        return dp[n];
    }
};
