class Solution {
public:
    string convertBin( int n ) {
        string s = "";
        while ( n > 0 ) {
            s += to_string(n%2);
            n /= 2;
        }
        return s;
    }
    int longestSubsequence(string s, int k) {
        int n = s.size();
        string kBin = convertBin(k);
        reverse(kBin.begin(),kBin.end());
        int m = kBin.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,0)));
        for ( int i = n - 1 ; i >= 0 ; --i ) {
            if ( s[i] > kBin[m - 1] ) {
                dp[i][m-1][1] = 1;
            } else {
                dp[i][m-1][0] = 1;
            }
        }
        int ans = 0;
        int pos = -1;
        for ( int i = n -  1 ; i >= 0 ; --i ) {
            for ( int j = i + 1 ; j < n ; ++j ) {
                for ( int z = 0 ; z < m - 1 ; ++z ) {
                    if ( s[i] < kBin[z] ) {
                        dp[i][z][0] |= dp[j][z+1][0];
                        dp[i][z][0] |= dp[j][z+1][1];
                    } else if ( s[i] > kBin[z] ) {
                        dp[i][z][1] |= dp[j][z+1][0];
                        dp[i][z][1] |= dp[j][z+1][1];
                    } else {
                        dp[i][z][0] |= dp[j][z+1][0];
                        dp[i][z][1] |= dp[j][z+1][1];
                    }
                }
            }
            if ( dp[i][0][0] ) {
                pos = i;
                break;
            }
        }
        if ( pos != -1 ) {
            ans = m;
            for ( int i = 0 ; i < pos ; ++i ) {
                ans += (s[i] == '0');
            }
        }
        if ( n < m ) {
            ans = n;
        } else {
            ans = max(ans,m-1);
        }
        return ans;
    }
};
