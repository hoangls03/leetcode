const int oo = 1e9 + 7;
class Solution {
public:
    /*
        1: greater than
        0: less than
    */
    int zigZagArrays(int n, int l, int r) {
        vector<vector<int>> dp(r + 1, vector<int>(2,0));
        for ( int i = l ; i <= r ; ++i ) {
            dp[i][1] = i - l;
            dp[i][0] = r - i;
        }
        vector<vector<int>> newDp(r + 1, vector<int>(2,0));
        for ( int i = 3 ; i <= n ; ++i ) {
            long long sum = 0;
            
            for ( int j = l ; j <= r ; ++j ) {
                newDp[j][1] = sum;
                sum = (sum + dp[j][0])%oo;
            }

            sum = 0;
            for ( int j = r ; j >= l ; --j ) {
                newDp[j][0] = sum;
                sum = (sum + dp[j][1])%oo;
            }
            for ( int j = l ; j <= r ; ++j ) {
                dp[j][0] = newDp[j][0];
                dp[j][1] = newDp[j][1];
            }
        }
        long long ans = 0;
        for ( int j = l ; j <= r ; ++j ) {
            ans = (ans + dp[j][0] + dp[j][1])%oo;
        }
        return ans;
    }
};
