const char mons[] = {'E','F','W'};
const int oo = 1e9 + 7;
class Solution {
public:
    int countWinningSequences(string s) {
        long long dp[2005][3];
        int n = s.size();
        int point = 1000;
        for ( int i = 0 ; i <= 2000 ; ++i ) {
            for ( int j = 0 ; j < 3 ; ++j ) {
                dp[i][j] = 0;
            }
        }
        for ( int i = 0 ; i < 3 ; ++i ) {
            if ( mons[i] == s[0] ) {
                dp[point+1][(i+1)%3] = 1;
                dp[point][i] = 1;
                dp[point-1][(i-1+3)%3] = 1;
            }
        }
        for ( int i = 1 ; i < n ; ++i ) {
            int pos;
            for ( int j = 0 ; j < 3 ; ++j ) {
                if ( mons[j] == s[i] ) {
                    pos = j;
                }
            }
            long long temp[2005][3];
            for ( int j = 0 ; j <= 2000 ; ++j ) {
                for ( int k = 0 ; k < 3 ; ++k ) {
                    temp[j][k] = dp[j][k];
                }
            }
            int win = (pos + 1)%3;
            int lose = (pos - 1 + 3)%3;
            for ( int j = 1 ; j <= 2000 ; ++j ) {

                dp[j][win] = (temp[j-1][lose] + temp[j-1][pos] )%oo;
            }
            for ( int j = 0 ; j <= 2000 ; ++j ) {
                dp[j][pos] = (temp[j][win] + temp[j][lose] )%oo;
            }
            for ( int j = 0 ; j < 2000 ; ++j ) {
                dp[j][lose] = (temp[j+1][win] + temp[j+1][pos] )%oo;
            }
        }
        int ans = 0;
        for ( int i = 1001 ; i <= 2000 ; ++i ) {
            for ( int j = 0 ; j < 3 ; ++j ) {
                ans = ( ans + dp[i][j] )%oo;
            }
        }
        return ans;
    }
};
