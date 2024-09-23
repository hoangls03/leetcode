class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int> mp;
        for ( auto t : dictionary ) {
            mp[t] = 1;
        }
        int n = s.size();
        vector<int> dp(n,1e9);
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( mp[s.substr(0,i)] == 1 ) {
                dp[i-1] = 0;
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            dp[i] = min(dp[i],i+1);
        }
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j <= i ; ++j ) {
                string t = s.substr(j,i-j+1);
                if ( mp[t] == 1 ) {
                    for ( int z = 0 ; z < j ; ++z ) {
                        dp[i] = min(dp[z] + j - z - 1,dp[i]);
                    }
                }
            }
            for ( int j = 0 ; j < i ; ++j ) {
                dp[i] = min(dp[j] + i - j ,dp[i]);
            }
        }
        return dp[n-1];
    }
};
