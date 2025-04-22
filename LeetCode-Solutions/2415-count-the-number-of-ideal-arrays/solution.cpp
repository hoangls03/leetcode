const int oo = 1e9 + 7;
vector<vector<int>> dp(100005,vector<int>(14,0));
vector<vector<int>> cnt(100005,vector<int>(14,0));
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        if ( dp[1][1] == 0 ) {
            dp[0][0] = 1;
            for ( int i = 1 ; i <= 10000 ; ++i ) {
                for ( int j = 0 ; j < 14 ; ++j ) {
                    dp[i][j] = j == 0 ? 1 : (dp[i-1][j-1] + dp[i-1][j])%oo;
                }
            }
            for ( int i = 1 ; i <= 10000 ; ++i ) {
                cnt[i][0]++;
                for ( int j = 2*i ; j <= 10000 ; j += i ) {
                    for ( int k = 0 ; k < 14 ; ++k ) {
                        if ( cnt[i][k] ) {
                            cnt[j][k+1] += cnt[i][k];
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for ( int i = 1 ; i <= maxValue ; ++i ) {
            for ( int j = 0 ; j < min(14,n) ; ++j ) {
                if ( cnt[i][j] == 0 ) {
                    break;
                } else {
                    ans = ( 1LL* cnt[i][j] * dp[n-1][j] + ans)%oo;
                }
            }
        }
        return ans;
    }
};
