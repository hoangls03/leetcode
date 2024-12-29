const int oo = 1e9 + 7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = words[0].size();
        int n = target.size();
        vector<vector<int>> mark(26,vector<int>(m,0));
        for ( auto word : words ) {
            for ( int i = 0 ; i < word.size() ; ++i ) {
                mark[word[i] - 'a'][i]++;
            }
        }
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < m ; ++j ) {
                dp[i][j] = mark[target[i]-'a'][j];
                if ( i > 0 ) {
                    if ( j > 0 ) dp[i][j] = dp[i-1][j-1] * dp[i][j] % oo;
                    else {
                        if ( i > 0 ) dp[i][j] = 0;
                    }
                }
                if ( j > 0 ) dp[i][j] += dp[i][j-1];
                dp[i][j] %= oo;
            }
        }
        return dp[n-1][m-1];
    }
};
